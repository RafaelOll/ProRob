# test Nodes

## source the environment
```bash
source /opt/ros/humble/setup.bash
```

## Everytime you make a change and want to test the code for the drone test

### First terminal
Note you need to be in the directory /ProRob
```bash
colcon build
source install/setup.bash
ros2 run package_master service_drone
```

### second terminal
Note you need to be in the directory /ProRob
```bash
source install/setup.bash
ros2 run package_master client_drone
```


## Everytime you make a change and want to test the code for the tb test

### First terminal
Note you need to be in the directory /ProRob
```bash
colcon build
source install/setup.bash
ros2 run package_master service_tb
```

### second terminal
Note you need to be in the directory /ProRob
```bash
source install/setup.bash
ros2 run package_master client_tb
```


## Everytime you make a change and want to test the code for the global test

### First terminal
Note you need to be in the directory /ProRob
```bash
colcon build
source install/setup.bash
ros2 run package_master service_drone
```

### second terminal
Note you need to be in the directory /ProRob
```bash
source install/setup.bash
ros2 run package_master service_tb
```

### Third terminal
```bash
source install/setup.bash
ros2 run package_master client
```