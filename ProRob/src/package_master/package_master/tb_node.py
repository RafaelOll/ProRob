import rclpy
from rclpy.node import Node
from example_interfaces.srv import SetBool
from package_master_interfaces.srv import RobotPositions, SendPositions

# from package_master.control_bot import TurtleController, Vector2

from math import atan2, pi, sqrt
from time import time

import rclpy
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from rclpy.node import Node

#added
class Vector2:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        
    def to(self, other):
        return Vector2(other.x - self.x, other.y - self.y)

    def set(self, x, y):
        self.x = x
        self.y = y

    def length(self):
        return sqrt(self.x*self.x + self.y*self.y)
        
class TurtleController(Node):

    def __init__(self, dict_wp, robot_count):
        super().__init__('turtle_controller')
        
        self.publisher_dict = {}
        self.subscriber_dict = {}
        
        for i in range(robot_count):
            topic_publisher = f"/robot{i}/cmd_vel"
            topic_subscriber = f'/robot{i}/odom'
            
            self.publisher_dict[i] = self.create_publisher(Twist, topic_publisher, 1)
            
            self.subscriber_dict[i] = self.create_subscription(
                Odometry, 
                topic_subscriber,
                lambda msg: self.test_robot2(msg, i),
                1
            )
        
        #self.publisher_ = self.create_publisher(Twist, '/robot1/cmd_vel', 1)

        self.time = 0
        #self.timer = self.create_timer(1/5, self.move_turtle)
        self.get_logger().info("Turtle Controller Node has started")
        
        self.path = dict_wp
        self.target_index = 0
        self.turning = False

#        self.subscription = self.create_subscription(
#            Odometry,
#            '/robot1/odom',
#            self.move_turtle,
#            1
#        )

# #added client
#         self.robot_count = robot_count
#         self.arrived_robot_pos = {}
#         self.client_master = self.create_client(RobotPositions, 'get_robot_positions')
#         while not self.client_master.wait_for_service(timeout_sec=1.0):
#             self.get_logger().info('service not available, waiting again...')
# #added

    def test_robot2(self, msg, id):
        self.get_logger().info(str(id))

    def move_turtle(self, turtle_pose : Odometry, robot_id):
        ANGLE_THRESHOLD_HIGH = 0.5
        ANGLE_THRESHOLD_LOW = 0.2
        k_rot = 1
        rot_min = 0 # 0.5
        DST_THRESHOLD = 0.05
        k_speed = 0.1 # 0.5
        
        pose = turtle_pose.pose.pose
        curr_theta = pose.orientation.z*pi
        curr_pos = Vector2(pose.position.x, pose.position.y)

        delta = Twist()
        
        curr_target = self.path[robot_id][self.target_index]
        r = self.get_angle(curr_theta, curr_pos, curr_target)
        signe_r = -1 if r < 0 else 1
        d = curr_pos.to(curr_target).length()
        
        if abs(r) > ANGLE_THRESHOLD_HIGH:
            self.turning = True

        if time() - self.time > 1/3:
            self.get_logger().info(f"ID: {robot_id}")
            self.get_logger().info(f"D:{d:2f}, R:{(r*180/pi):2f}")
            if self.turning: 
                self.get_logger().info("action = turning")
            else:
                self.get_logger().info("action = forwarding")
            self.get_logger().info(f"current: (x={curr_pos.x:2f}, y={curr_pos.y:2f}), theta={(curr_theta*180/pi):2f}")
            self.get_logger().info("----------------------------")
            
            self.time = time()

#changed
        global arrived_robot_pos
        if d < DST_THRESHOLD:
            self.get_logger().info(f"arrived wp: {self.target_index}")

            if self.target_index==len(self.path)-1:
                self.arrived_robot_pos[f"tb{robot_id}"] = (curr_pos.x, curr_pos.y, 0)
                arrived_robot_pos[f"tb{robot_id}"] = (curr_pos.x, curr_pos.y, 0)
                
            else: 
                self.target_index += 1

    # # added
    #         if self.target_index==len(self.path)-1:
    #             self.arrived_robot_pos[f"tb{robot_id}"] = (curr_pos.x, curr_pos.y, 0)
    #             if len(self.arrived_robot_pos)==self.robot_count:
    #                 self.send_positions(self.arrived_robot_pos)
                
    #         else: 
    #             self.target_index += 1
    # # added
#changed

        elif self.turning:
            delta.angular.z = max(abs(k_rot*r/pi), rot_min)*signe_r
            r = self.get_angle(curr_theta, curr_pos, curr_target)
            if abs(r) < ANGLE_THRESHOLD_LOW:
                self.turning = False    
        else:
            delta.linear.x = k_speed*min(d, 0.4)
            d = curr_pos.to(curr_target).length() # Update distance to travel left
        
            
        self.publisher_dict[robot_id].publish(delta)
        
    
    def get_angle(self, theta, pos1, pos2):
        dir = pos1.to(pos2)
        theta_turn = atan2(dir.y, dir.x) - theta
        if theta_turn > pi:
            theta_turn = theta_turn-2*pi
        elif theta_turn < -pi:
            theta_turn = theta_turn+2*pi
        return theta_turn

# #added
#     def send_positions(self, arrived_robot_pos): # a modifier
#         request = RobotPositions.Request()

#         request.all_robot_pos = arrived_robot_pos

#         self.get_logger().info(f"Sending position of robots finished")

#         future = self.client_send_positions.call_async(request)
#         rclpy.spin_until_future_complete(self, future)

#         if future.result():
#             self.get_logger().info(f"Server Response: {str(future.result())}")
#         else:
#             self.get_logger().warn("Failed to send robot position")

# #added




class GetPosService(Node):
    def __init__(self):
        super().__init__('ask_for_pos_client')
        self.srv = self.create_service(SendPositions, 'send_positions', self.send_positions_callback)
        self.destroy_after_response = False

    def send_positions_callback(self, request, response):
        response.ack = True
        global position_dict
        position_dict = {
                name: (x, y, z)
                for name, x, y, z in zip(request.robot_names, request.positions_x, request.positions_y, request.positions_z)
            }
        self.destroy_after_response = True
        return response



class StartService(Node):
    def __init__(self):
        super().__init__('start_service')
        self.srv = self.create_service(SetBool, 'set_bool', self.handle_set_bool)
        self.get_logger().info('SetBool service is ready.')
        self.destroy_after_response = False

    def handle_set_bool(self, request, response):
        # Log the received request
        self.get_logger().info(f'Received request: {request.data}')
        
        # Process the request and prepare the response
        if request.data:
            response.success = True
            response.message = "The operation was set to True successfully."
        else:
            response.success = True
            response.message = "The operation was set to False successfully."
        
        # Return the response
        self.destroy_after_response = True
        return response



class SendPosService(Node):
    def __init__(self):
        super().__init__('send_pos__service')
        self.service = self.create_service(RobotPositions, 'get_robot_positions', self.handle_request)
        self.destroy_after_response = False
        print("init")

    #def make_the_move(self): move the turtlebot the send their final location with get_position



    def get_position(self, request):
        # robot_position_map = request.all_robot_pos
        global arrived_robot_pos
        robot_position_map = arrived_robot_pos
        final_pos_dict = {
            name: robot_position_map.get(name, (0.0, 0.0, 0.0))
            for name in request.robot_names
        }
        return final_pos_dict
    
    def handle_request(self, request, response):
        self.get_logger().info('Incoming request')
        #self.make_the_move() #move the tbs
        final_pos_dict = self.get_position(request)
        for name, position in final_pos_dict.items():
            response.robot_names.append(name)
            response.positions_x.append(position[0])
            response.positions_y.append(position[1])
            response.positions_z.append(position[2])
        self.destroy_after_response = True
        return response



def main(args=None):
    rclpy.init(args=args)

    # Lancer MinimalService
    get_pos_service = GetPosService()
    while rclpy.ok():
        rclpy.spin_once(get_pos_service)
        if get_pos_service.destroy_after_response:
            get_pos_service.destroy_node()
            
            break
    print("stage 1 done")
    print(position_dict)


    start_service = StartService()
    while rclpy.ok():
        rclpy.spin_once(start_service)
        if start_service.destroy_after_response:
            start_service.destroy_node()
            break
    print("stage 2 done")


    robot_count = 1
    arrived_robot_pos = {}

    dict_wp = {}
    dict_wp[0] = [Vector2(2,0.0)]
    dict_wp[1] = [Vector2(1,-1)]
    dict_wp[2] = [Vector2(2,0)]

    turtle_controller = TurtleController(dict_wp, robot_count)

    while rclpy.ok():
        rclpy.spin_once(turtle_controller)
        if len(arrived_robot_pos)==robot_count: 
            turtle_controller.destroy_node()
            break

    

    # Lancer SendPosService
    send_pos_service = SendPosService()
    while rclpy.ok():
        rclpy.spin_once(send_pos_service)
        if send_pos_service.destroy_after_response:
            send_pos_service.destroy_node()
            break
    print("stage 3 done")

    rclpy.shutdown()

if __name__ == '__main__':
    main()
