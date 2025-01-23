import rclpy
from rclpy.node import Node
from example_interfaces.srv import SetBool
from package_master_interfaces.srv import RobotPositions, SendPositions
from std_msgs.msg import String



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



class SendPosService(Node):
    def __init__(self):
        super().__init__('send_pos__service')
        self.service = self.create_service(RobotPositions, 'get_robot_positions', self.handle_request)
        self.destroy_after_response = False
        print("init")

    #def make_the_move(self): move the turtlebot the send their final location with get_position

    def get_position(self, request):
        robot_position_map = { #a changer (récuperer les positions reelles)
            "tb1": (1.0, 2.0, 0.0),
            "tb2": (4.0, 5.0, 0.0),
            "tb3": (7.0, 8.0, 0.0)
        }
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



class MinimalSubscriber(Node):

    def __init__(self):
        super().__init__('minimal_subscriber')
        self.subscription = self.create_subscription(
            String,
            'topic',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        self.get_logger().info('%s' % msg.data)



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

    # Lancer SendPosService
    send_pos_service = SendPosService()
    while rclpy.ok():
        rclpy.spin_once(send_pos_service)
        if send_pos_service.destroy_after_response:
            send_pos_service.destroy_node()
            break
    print("stage 2 done")

    minimal_subscriber = MinimalSubscriber()
    rclpy.spin_once(minimal_subscriber)
    minimal_subscriber.destroy_node()

    rclpy.shutdown()

if __name__ == '__main__':
    main()
