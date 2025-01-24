import rclpy
from rclpy.node import Node
from example_interfaces.srv import SetBool
from package_master_interfaces.srv import RobotPositions, SendPositions



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

    #turtle_controller = TurtleController(dict_wp, robot_count)

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
