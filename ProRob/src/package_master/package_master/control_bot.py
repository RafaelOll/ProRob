#!/usr/bin/env python3

from math import atan2, pi, sqrt
from time import time

import rclpy
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from rclpy.node import Node


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
            
        self.publisher_dict[0] = self.create_publisher(Twist, '/robot0/cmd_vel', 10)
            
        self.subscriber_dict[0] = self.create_subscription(
            Odometry, 
            "/robot0/odom",
            lambda msg: self.move_turtle(msg, 0),
            10
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

    def test_robot2(self, msg, str_id):
        self.get_logger().info(str_id)

    def move_turtle(self, turtle_pose : Odometry, robot_id):
        ANGLE_THRESHOLD_HIGH = 0.4
        ANGLE_THRESHOLD_LOW = 0.2
        k_rot = 2
        rot_min = 0.1 # 0.5
        DST_THRESHOLD = 0.10
        k_speed = 0.5 # 0.5
        MAX_SPEED = 0.35
        
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

        if d < DST_THRESHOLD:
            self.get_logger().info(f"arrived wp: {self.target_index}")
            self.target_index = min(self.target_index + 1, len(self.path[robot_id])-1)
        elif self.turning:
            delta.angular.z = max(abs(k_rot*r/pi), rot_min)*signe_r
            r = self.get_angle(curr_theta, curr_pos, curr_target)
            if abs(r) < ANGLE_THRESHOLD_LOW:
                self.turning = False    
        else:
            delta.linear.x = k_speed*min(d, MAX_SPEED)
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
        
        
def main(args=None):
    rclpy.init(args=args)
    
    robot_count = 1
    
    dict_wp = {}
    dict_wp[0] = [Vector2(0,-1.25)]
    #dict_wp[0] = [Vector2(1.2,0), Vector2(1.5,-0.7)]
    #dict_wp[0] = [Vector2(1.2,0), Vector2(1.5,-0.7)]
    
    #dict_wp[1] = [Vector2(0,0)] #[Vector2(0.2,-1), Vector2(0.8,0.5)]
    
    node = TurtleController(dict_wp, robot_count)
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()

