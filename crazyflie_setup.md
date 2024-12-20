# Crazyflie setup

1. recharge batteries
2. Setup the transmittors and the carpet
3. Calibration:
    3.1 in terminal: go to folder crazyflie-clients-python
    3.2 start the GUI: cfclient
    3.3 enter address of drone: e.g. for drone 7: 0x7
    3.4 Scan
    3.5 once it is found (i.e. you see radio://0/80/2M/7 to the left of the buttons), click connect
    3.6 add "Lighthouse Positioning" tab: View -> Tabs -> Lighthouse Positioning
    3.7 in tab Lighthouse Positioning: Manage geometry
    3.8 follow instructions for calibration
    3.9 write to crazyflie
    3.10 optional: save calibration on the computer to be able to load it onto multiple drones
