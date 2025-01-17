import time
import sys
import os

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
    'radio://0/80/2M/3',
    'radio://0/80/2M/2'
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

sequence0 = [
    (0, u, 0, dt),
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
seq_args = {
    uris[0]: [sequence0],
    uris[1]: [sequence1],
    uris[2]: [sequence2]
}



if __name__ == '__main__':
    
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
            swarm.parallel_safe(run_sequence, args_dict=seq_args)
            swarm.parallel_safe(land)


