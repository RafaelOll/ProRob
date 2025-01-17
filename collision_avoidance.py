import time
import sys
import os
import numpy as np

# Add crazyflie-lib-python to the system path
sys.path.append(os.path.abspath("crazyflie-lib-python"))

# Import your modules from the library

import cflib.crtp
from cflib.crazyflie.swarm import CachedCfFactory
from cflib.crazyflie.swarm import Swarm
from cflib.crazyflie.log import LogConfig


def activate_led_bit_mask(scf):
    scf.cf.param.set_value('led.bitmask', 255)

def deactivate_led_bit_mask(scf):
    scf.cf.param.set_value('led.bitmask', 0)

def light_check(scf):
    activate_led_bit_mask(scf)
    time.sleep(2)
    deactivate_led_bit_mask(scf)
    time.sleep(2)


def take_off(scf):
    commander= scf.cf.high_level_commander

    commander.takeoff(1.0, 2.0)
    time.sleep(3)

def land(scf):
    commander= scf.cf.high_level_commander

    commander.land(0.0, 2.0)
    time.sleep(2)

    commander.stop()

def hover_sequence(scf):
    take_off(scf)
    land(scf)


def run_square_sequence(scf):
    box_size = 0.5
    flight_time = 2

    commander= scf.cf.high_level_commander

    commander.go_to(box_size, 0, 0, 0, flight_time, relative=True)
    time.sleep(flight_time)

    commander.go_to(0, box_size, 0, 0, flight_time, relative=True)
    time.sleep(flight_time)

    commander.go_to(-box_size, 0, 0, 0, flight_time, relative=True)
    time.sleep(flight_time)

    commander.go_to(0, -box_size, 0, 0, flight_time, relative=True)
    time.sleep(flight_time)




def log_callback(uri, timestamp, data, logconf):
    x = data['stateEstimate.x']
    y = data['stateEstimate.y']
    z = data['stateEstimate.z']
    with open("cf_log.txt", "a") as f:
        f.write(f"{timestamp} {uri} {x} {y} {z}\n")
        f.close()


def start_states_log(scf):
    log_conf = LogConfig(name="pos", period_in_ms=100)
    log_conf.add_variable("stateEstimate.x", "float")
    log_conf.add_variable("stateEstimate.y", "float")
    log_conf.add_variable("stateEstimate.z", "float")
    
    uri = scf.cf.link_uri
    scf.cf.log.add_config(log_conf)
    log_conf.data_received_cb.add_callback(lambda timestamp, data, logconf: log_callback(uri, timestamp, data, logconf))
    log_conf.start()


uris = [
    'radio://0/80/2M/8',
    'radio://0/80/2M/2',
    #'radio://0/80/2M/3'
    # Add more URIs if you want more copters in the swarm
]



def run_sequence(scf, sequence):
    cf = scf.cf

    for arguments in sequence:
        commander = scf.cf.high_level_commander

        x, y, z = arguments[0], arguments[1], arguments[2]
        duration = arguments[3]

        print('Setting position {} to cf {}'.format((x, y, z), cf.link_uri))
        commander.go_to(x, y, z, 0, duration, relative=True)
        time.sleep(duration)

u = 0.3
dt = 3

def check_collision_linear_segment(t_i1, t_f1, r_i1, r_f1, t_i2, t_f2, r_i2, r_f2, epsilon):
    """checks if two linear trajectories have a collision.
    returns:
    - indices at which the collisions occur
    - times"""
    t_eval_i = np.max([t_i1, t_i2])
    t_eval_f = np.min([t_f1, t_f2])
    t = np.linspace(t_eval_i, t_eval_f, 100)
    print(f"evaluation for t in [{t_eval_i}, {t_eval_f}]")

    delta = np.zeros(len(t))
    for k in range(len(t)):
        v = r_i1-r_i2 + (r_f1-r_i1)*(t[k]-t_i1)/(t_f1-t_i1) - (r_f2-r_i2)*(t[k]-t_i2)/(t_f2-t_i2)
        delta[k] = np.sqrt(v[0]**2 + v[1]**2)

    indices_collisions = np.where(delta<epsilon)
    return t[indices_collisions]


def position(t, r_i, r_f, t_i, t_f):
    """returns the position of a linearly displaced object at time t"""
    return r_i + (r_f-r_i)*(t-t_i)/(t_f-t_i)


def construct_sequences(r_i, r_f, T, epsilon):
    """constructs a pair of sequences that avoid a crash"""
    t_i0 = 0
    t_f0 = T
    t_i1 = 0
    t_f1 = T

    dx0, dy0 = r_f[0]-r_i[0]
    sequence0 = [
        (dx0, dy0, 0, T)
    ]
    v0 = np.sqrt(dx0**2+dy0**2)/T
    t_delay = 2*epsilon/v0
    print(f"comuted delay time: {t_delay}")

    t_coll = check_collision_linear_segment(t_i0, t_f0, r_i[0], r_f[0], t_i1, t_f1, r_i[1], r_f[1], epsilon)


    if len(t_coll) > 0:
        r_wp = position(t_coll[0], r_i[1], r_f[1], t_i1, t_f1)
        t_wp = t_coll[0] + t_delay

        dx10, dy10 = r_wp - r_i[1]
        dx11, dy11 = r_f[1] - r_wp
        sequence1 = [
            (dx10, dy10, 0, t_wp),
            (dx11, dy11, 0, T-t_wp)
        ]
    
    else:
        dx1, dy1 = r_f[1]-r_i[1]
        sequence1 = [
            (dx1, dy1, 0, T)
        ]
    
    return sequence0, sequence1
        

sequence0 = [
    (0, u, 0, dt),              # dx, dy, dz, dt
    (0, -u, 0, dt)
]

sequence1 = [
    (u, 0, 0, dt),
    (-u, 0, 0, dt)
]

sequence2 = [
    (0, -u, 0, dt),
    (0, u, 0, dt)
]



def get_positions():
    data = np.genfromtxt("cf_log.txt", dtype=None, encoding=None)
    
    r = np.zeros(shape=(len(uris), 2))

    for i_uri in range(len(uris)):
        found = False
        i_data = -1
        while not found:
            if data[i_data][1] == uris[i_uri]:
                found = True
                r[i_uri] = np.array([data[i_data][2], data[i_data][3]])
            i_data -= 1           
    return r


def flight():    
    print("init drivers")
    cflib.crtp.init_drivers()

    print("create factory")
    factory = CachedCfFactory(rw_cache='./cache')

    print("create Swarm")
    with Swarm(uris, factory=factory) as swarm:
            #print("\nStarting light check")
            #swarm.sequential(light_check)            # parallel_safe will execute the function given to it as an argument for all crazyflies in the swarm
            
            print("\nreset estimators")
            swarm.reset_estimators()

            #print("\nsequential take off and landing")
            #swarm.parallel_safe(hover_sequence)

            print("Initialize logging")
            open("cf_log.txt", "w").close()
            swarm.parallel_safe(start_states_log)

            print("Run the test sequence")
            swarm.parallel_safe(take_off)
            
            T = 10
            epsilon = 0.5
            r_i = get_positions()
            r_f = np.array(
                [
                    [0, 1],
                    [1, 0],
                ]
            )

            seq0, seq1 = construct_sequences(r_i, r_f, T, epsilon)
            seq_args = {
                uris[0]: [seq0],
                uris[1]: [seq1],
            }
            print(seq0)
            print(seq1)
            time.sleep(10)
            print("It goes on!")

            swarm.parallel_safe(run_sequence, args_dict=seq_args)
            swarm.parallel_safe(land)



def seq_constr_test():
    r_i1 = np.array([0, -1])
    r_f1 = np.array([0, 1])
    r_i2 = np.array([-1, 0])
    r_f2 = np.array([1, 0])
    #t_i1 = 0
    #t_f1 = 10
    #t_i2 = 5
    #t_f2 = 10
    epsilon = 0.25
    T = 10

    #t_coll = check_collision_linear_segment(t_i1, t_f1, r_i1, r_f1, t_i2, t_f2, r_i2, r_f2, epsilon)
    #print(t_coll)

    r_i = np.array([r_i1, r_i2])
    r_f = np.array([r_f1, r_f2])

    seq0, seq1 = construct_sequences(r_i, r_f, T, epsilon)
    print(seq0)
    print(seq1)
    try:
        print(seq1[0][0]+seq1[1][0])
        print(seq1[0][1]+seq1[1][1])
        print(seq1[0][3]+seq1[1][3])
    except:
        print(":)")


if __name__ == "__main__":
    flight()

    