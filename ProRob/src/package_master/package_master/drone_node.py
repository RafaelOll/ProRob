import rclpy
from rclpy.node import Node
from example_interfaces.srv import SetBool
from package_master_interfaces.srv import RobotPositions, SendPositions

import numpy as np
import time
import sys
import os


# if the following imports don't work, make sure, ~/ProRob/crazyflie-lib-python exists,
# navigate to the folder in the terminal and run "pip install .". This will install 
# the crazyflie lib as a package which means, that it is no longer necessary
# to modify the sys.path manually in a program.
import cflib.crtp
from cflib.crazyflie.swarm import CachedCfFactory
from cflib.crazyflie.swarm import Swarm
from cflib.crazyflie.log import LogConfig

uris = [
    'radio://0/80/2M/8',
    'radio://0/80/2M/2',
    #'radio://0/80/2M/3'
]

cf_log_path = os.path.expanduser("~/ProRob/cf_log.txt")

class SendPosService(Node):
    def __init__(self, swarm:Swarm):
        super().__init__('send_pos_service')
        self.service = self.create_service(RobotPositions, 'get_robot_positions', self.handle_request)
        self.destroy_after_response = False
        
        swarm.parallel_safe(self.start_states_log)

    def start_states_log(self, scf):
        log_conf = LogConfig(name="pos", period_in_ms=100)
        log_conf.add_variable("stateEstimate.x", "float")
        log_conf.add_variable("stateEstimate.y", "float")
        log_conf.add_variable("stateEstimate.z", "float")
        
        uri = scf.cf.link_uri
        scf.cf.log.add_config(log_conf)
        log_conf.data_received_cb.add_callback(lambda timestamp, data, logconf: self.log_callback(uri, timestamp, data, logconf))
        log_conf.start()

    def log_callback(self, uri, timestamp, data, logconf):
        x = data['stateEstimate.x']
        y = data['stateEstimate.y']
        z = data['stateEstimate.z']
        with open(cf_log_path, "a") as f:
            f.write(f"{timestamp} {uri} {x} {y} {z}\n")
            f.close()

    def get_position(self, request):  #a changer (récuperer les positions reelles)
        """gets the positions of all drones by reading the cf_log.txt file.
        Attention: if swarm.parallel_safe(start_states_log) has not been called before,
        no positions are written to the cf_log.txt. The positions that are read by this function
        correspond in that case to the ones that were written during the last run and are
        therefore meaningless."""

        data = np.genfromtxt(cf_log_path, dtype=None, encoding=None)
        
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
        self.swarm.parallel_safe(self.take_off)
        return True

    def take_off(self, scf):
        commander= scf.cf.high_level_commander
        commander.takeoff(1.0, 2.0)
        time.sleep(3)

    def handle_request(self, request, response):
        self.get_logger().info('Incoming request')
        response.success = self.is_ready()  # Appelle une fonction pour déterminer l'état
        response.message = 'Ready state checked'
        #self.get_logger().info(f'Responding with ready state: {response.success}')
        self.destroy_after_response = True
        return response



class GetPosService(Node):
    def __init__(self):
        super().__init__('ask_for_pos_client')
        self.srv = self.create_service(SendPositions, 'send_positions', self.send_positions_callback)
        self.destroy_after_response = False

    def send_positions_callback(self, request, response):
        response.ack = True # to change send true not when you received the coordinates but all the drones land.
        global final_position_dict
        final_position_dict = {
                name: (x, y, z)
                for name, x, y, z in zip(request.robot_names, request.positions_x, request.positions_y, request.positions_z)
            }
        self.destroy_after_response = True
        return response



def main(args=None):
    rclpy.init(args=args)

    cflib.crtp.init_drivers()
    factory = CachedCfFactory(rw_cache='./cache')

    with Swarm(uris, factory) as swarm:         # for this line to work, a crazyradio dongle has to be attached to the computer
        swarm.reset_estimators()

        # Lancer SendPosService
        send_pos_service = SendPosService(swarm)
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

        get_pos_service = GetPosService()
        while rclpy.ok():
            rclpy.spin_once(get_pos_service)
            print(get_pos_service)
            if get_pos_service.destroy_after_response:
                get_pos_service.destroy_node()
                
                break
        print("stage 3 done")

        rclpy.shutdown()

if __name__ == '__main__':
    main()
