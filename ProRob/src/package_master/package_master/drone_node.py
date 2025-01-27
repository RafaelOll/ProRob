import rclpy
from rclpy.node import Node
from example_interfaces.srv import SetBool
from package_master_interfaces.srv import RobotPositions, SendPositions

import time
import numpy as np
import os
import sys

collision_avoidance_path = os.path.expanduser("~/ProRob")
sys.path.append(collision_avoidance_path)

from collision_avoidance import (construct_sequences, 
                                 run_sequence, 
                                 land, 
                                 start_states_log,
                                 take_off, 
                                 light_check)

# if the following imports don't work, make sure, ~/ProRob/crazyflie-lib-python exists,
# navigate to the folder in the terminal and run "pip install .". This will install 
# the crazyflie lib as a package which means, that it is no longer necessary
# to modify the sys.path manually in a program.
import cflib.crtp
from cflib.crazyflie.swarm import CachedCfFactory
from cflib.crazyflie.swarm import Swarm

uris = [
    'radio://0/80/2M/8',
    'radio://0/80/2M/3',
    'radio://0/80/2M/A'
]

cf_log_path = os.path.expanduser("~/ProRob/cf_log.txt")
sys.path.append(cf_log_path)


class TrajectoryCalculator():
    def __init__(self, T, epsilon):
        """arguments:
        - T         total duration of flights
        - epsilon   radius of clearance around a drone
        """
        self.N_drones = len(uris)
        self.r_i = np.zeros(shape=(self.N_drones, 2))
        self.r_f = np.zeros(shape=(self.N_drones, 2))
        self.T = T
        self.epsilon = epsilon

    def set_final_position(self, final_position_dict):
        for i in range(self.N_drones):
            self.r_f[i] = final_position_dict[f"tb{i+1}"][:2]       # only the (x, y) positions are needed for the trajectory planning => [:2]
        print(f"r_f = {self.r_f}")

    def set_initial_position(self, initial_position_dict):
        for i in range(self.N_drones):
            self.r_i[i] = initial_position_dict[f"drone{i+1}"][:2]
        print(f"r_i = {self.r_i}")

    def calculate_trajectories(self):
        """calculates trajectories for three drones such that they avoid collisions
        returns:
        - seq_args      dict with the sequences for the drones. 
                        Can directly be given to a parallel_safe for running a sequence"""
        sequences = construct_sequences(self.r_i, self.r_f, self.T, self.epsilon)
        



        u = 0.5
        dt = 3
        sequence0 = [
            (u, 0, 0, dt),              # dx, dy, dz, dt
            (-u, 0, 0, dt)
        ]

        sequence1 = [
            (0, 0, 0, dt),
            (0, 0, 0, dt)
        ]

        sequence2 = [
            (-u, 0, 0, dt),
            (u, 0, 0, dt)
        ]

        #sequences = [sequence0, sequence1, sequence2]

        seq_args = {
            uris[0]: [sequences[0]],
            uris[1]: [sequences[1]],
#            uris[2]: [sequences[2]]
        }
        return seq_args



class SendPosService(Node):
    def __init__(self, swarm:Swarm, trajectory_calculator:TrajectoryCalculator):
        super().__init__('send_pos_service')
        self.service = self.create_service(RobotPositions, 'get_robot_positions', self.handle_request)
        self.destroy_after_response = False
        self.trajectory_calculator = trajectory_calculator

        print("Initialize logging")
        open("cf_log.txt", "w").close()
        swarm.parallel_safe(start_states_log)


    def get_position(self, request):  #a changer (récuperer les positions reelles)
        """gets the positions of all drones by reading the cf_log.txt file.
        Attention: if swarm.parallel_safe(start_states_log) has not been called before,
        no positions are written to the cf_log.txt. The positions that are read by this function
        correspond in that case to the ones that were written during the last run and are
        therefore meaningless."""

        data = np.genfromtxt("cf_log.txt", dtype=None, encoding=None)
        
        # get the positions from the log file
        #r = np.zeros(shape=(len(uris), 2))
        r = np.zeros(shape=(3, 3))

        for i_uri in range(len(uris)):
            found = False
            i_data = -1
            while not found:
                if data[i_data][1] == uris[i_uri]:
                    found = True
                    r[i_uri] = np.array([data[i_data][2], data[i_data][3], data[i_data][4]])
                i_data -= 1   
        print(r)

        # construct dictionary
        robot_position_map = {
            "drone1": r[0],
            "drone2": r[1],
            "drone3": r[2]
        }
        pos_dict = {
            name: robot_position_map.get(name, (0.0, 0.0, 0.0))
            for name in request.robot_names
        }
        return pos_dict
    
    def handle_request(self, request, response):
        self.get_logger().info('Incoming request')
        print("handle_request")
        pos_dict = self.get_position(request)
        self.trajectory_calculator.set_initial_position(pos_dict)
        for name, position in pos_dict.items():
            response.robot_names.append(name)
            response.positions_x.append(position[0])
            response.positions_y.append(position[1])
            response.positions_z.append(position[2])
        self.destroy_after_response = True
        return response



class TakeOffService(Node):
    def __init__(self, swarm:Swarm):
        super().__init__('take_off_service')
        self.service = self.create_service(SetBool, 'check_ready', self.handle_request)
        self.destroy_after_response = False
        self.swarm = swarm

    def is_ready(self):   # to change, make the drone take off and send true when the tbs can move
        try:
            self.swarm.parallel_safe(take_off)
            return True
        except:
            print("takeoff impossible in is_ready")
            return False

    def handle_request(self, request, response):
        self.get_logger().info('Incoming request')
        response.success = self.is_ready()  # Appelle une fonction pour déterminer l'état
        response.message = 'Ready state checked'
        #self.get_logger().info(f'Responding with ready state: {response.success}')
        self.destroy_after_response = True
        return response



class GetPosService(Node):
    def __init__(self, swarm:Swarm, trajectory_calculator:TrajectoryCalculator):
        super().__init__('ask_for_pos_client')
        self.srv = self.create_service(SendPositions, 'send_positions', self.send_positions_callback)
        self.destroy_after_response = False

        self.swarm = swarm
        self.trajectory_calculator = trajectory_calculator

    def send_positions_callback(self, request, response):
        
        global final_position_dict
        final_position_dict = {
                name: (x, y, z)
                for name, x, y, z in zip(request.robot_names, request.positions_x, request.positions_y, request.positions_z)
            }
        self.destroy_after_response = True

        try:
            # get trajectories 
            self.trajectory_calculator.set_final_position(final_position_dict)
            seq_args = self.trajectory_calculator.calculate_trajectories()

            print(seq_args)
            # follow the trajectories to the destination
            self.swarm.parallel_safe(run_sequence, args_dict=seq_args)        

            print("landing")
            # land
            self.swarm.parallel_safe(land)
            print("landed")

            response.ack = True # to change send true not when you received the coordinates but all the drones land.
        
        except:
            print("Could not get and execute the trajectories in send_positions_callback")
            response.ack = False

        return response





def main(args=None):
    trajectory_calculator = TrajectoryCalculator(T=10, epsilon=0.25)

    rclpy.init(args=args)

    cflib.crtp.init_drivers()
    factory = CachedCfFactory(rw_cache='./cache')

    with Swarm(uris, factory) as swarm:         # for this line to work, a crazyradio dongle has to be attached to the computer
        print("Swarm created")
        swarm.reset_estimators()
        print("estimators reset")
        
        # Lancer SendPosService
        send_pos_service = SendPosService(swarm, trajectory_calculator)
        while rclpy.ok():
            rclpy.spin_once(send_pos_service)
            if send_pos_service.destroy_after_response:
                send_pos_service.destroy_node()             # possible source of problem: When node is destroyed, does the states_log continue or not -> verify once a crazyflie_dongle is available
                break
        print("stage 1 done")

        
        #Lancer IsReadyService après SendPosService
        node = TakeOffService(swarm)
        while rclpy.ok():
            rclpy.spin_once(node)
            print(node)
            if node.destroy_after_response:
                node.destroy_node()
                break
        print("stage 2 done")
        time.sleep(2)
        
        
        get_pos_service = GetPosService(swarm, trajectory_calculator)
        while rclpy.ok():
            rclpy.spin_once(get_pos_service)
            print(get_pos_service)
            if get_pos_service.destroy_after_response:
                get_pos_service.destroy_node()
                
                break
        #swarm.parallel_safe(land)
        print("stage 3 done")

        
        rclpy.shutdown()

if __name__ == '__main__':
    main() 
