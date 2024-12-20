# Setting up the structure

## documentation
- see on moodle
- [talker listener tutorial](https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Writing-A-Simple-Py-Publisher-And-Subscriber.html)

## Create a workspace

First create a folder containing the workspace
```bash
mkdir -p road/to/the/workspace/src
cd road/to/the/workspace
```


## Build the Workspace

```bash
colcon build
```


## Source the environment

```bash
source install/setup.bash
```


## Create a package to manage the codes

```bash
cd ./src
source /opt/ros/foxy/setup.bash
ros2 pkg create [package_name] --build-type ament_python --dependencies [depend1] [depend2] [depend3]
```


# different stages

1. Setup a workspace on the main computer
2. Create a package : <package_name>
3. Create 3 nodes : main, Command_CF, Command_TB
4. Create a Service : CTG
5. Create a talker ans a listener in every node
6. Create 6 topics (communication between main and node)