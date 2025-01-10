import logging
import time
import sys
import os


# Add crazyflie-lib-python to the system path
sys.path.append(os.path.abspath("crazyflie-lib-python"))

import cflib.crtp
from cflib.crazyflie import Crazyflie
from cflib.crazyflie.syncCrazyflie import SyncCrazyflie

from cflib.crazyflie.log import LogConfig
from cflib.crazyflie.syncLogger import SyncLogger

# URI to the Crazyflie to connect to
uri = 'radio://0/80/2M/8'

# Only output errors from the logging framework
logging.basicConfig(level=logging.ERROR)

def simple_log(scf, logconf):


    with SyncLogger(scf, logconf) as logger:

        with open("cf_log.txt", "w") as f:
            for log_entry in logger:

                timestamp = log_entry[0]
                data = log_entry[1]
                logconf_name = log_entry[2]

                f.write(f"{timestamp} {data['stateEstimate.x']} {data['stateEstimate.y']} {data['stateEstimate.z']}")
                f.close()

                break


if __name__ == '__main__':
    # Initialize the low-level drivers
    cflib.crtp.init_drivers()

    #lg_stab = LogConfig(name='Stabilizer', period_in_ms=10)
    #lg_stab.add_variable('stabilizer.x', 'float')
    #lg_stab.add_variable('stabilizer.y', 'float')
    #lg_stab.add_variable('stabilizer.z', 'float')
    lg_stab = LogConfig(name='Position', period_in_ms=10)
    lg_stab.add_variable('stateEstimate.x', 'float')
    lg_stab.add_variable('stateEstimate.y', 'float')
    lg_stab.add_variable('stateEstimate.z', 'float')

    

    with SyncCrazyflie(uri, cf=Crazyflie(rw_cache='./cache')) as scf:

        simple_log(scf, lg_stab)
        
        

