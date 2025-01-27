import numpy as np


uris = [
    #'radio://0/80/2M/A',
    'radio://0/80/2M/8',
    'radio://0/80/2M/3'
]


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
        #sequences = construct_sequences(self.r_i, self.r_f, self.T, self.epsilon)
        
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

        sequences = [sequence0, sequence1, sequence2]

        seq_args = {
            uris[0]: [sequences[0]],
            uris[1]: [sequences[1]],
#            uris[2]: [sequences[2]]
        }
        return seq_args




if __name__ == "__main__":
    
    drone_position_map = { #a changer (récuperer les positions reelles)
        "drone1": (1.0, 0, 0),
        "drone2": (-1.0, 0.5, 0),
        "drone3": (1.0, -0.5, 0)
    } 
    
    
    
    robot_position_map = { #a changer (récuperer les positions reelles)
        "tb1": (1.0, 0, 0),
        "tb2": (-1.0, 0.5, 0),
        "tb3": (1.0, -0.5, 0)
    }
    final_position_dict = {
        name: robot_position_map.get(name, (0.0, 0.0, 0.0))
        for name in ["tb1", "tb2", "tb3"]
    }

    tc = TrajectoryCalculator(10, 0.25)
    tc.set_initial_position(drone_position_map)
    tc.set_final_position(final_position_dict)
    