import time
import sys
import os

# Add crazyflie-lib-python to the system path
sys.path.append(os.path.abspath("crazyflie-lib-python"))

# Import your modules from the library

import cflib.crtp
from cflib.crazyflie.swarm import CachedCfFactory
from cflib.crazyflie.swarm import Swarm


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
    box_size = 1
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





uris = {
    'radio://0/80/2M/8',
    'radio://0/80/2M/2'
    # Add more URIs if you want more copters in the swarm
}





if __name__ == '__main__':
    
    print("init drivers")
    cflib.crtp.init_drivers()

    print("create factory")
    factory = CachedCfFactory(rw_cache='./cache')

    print("create Swarm")
    with Swarm(uris, factory=factory) as swarm:
            print("\nStarting light check")
            swarm.sequential(light_check)            # parallel_safe will execute the function given to it as an argument for all crazyflies in the swarm
            
            print("\nreset estimators")
            swarm.reset_estimators()

            print("\nsequential take off and landing")
            swarm.parallel_safe(hover_sequence)


            print("square sequence")
            swarm.parallel_safe(take_off)
            swarm.parallel_safe(run_square_sequence)
            swarm.parallel_safe(land)