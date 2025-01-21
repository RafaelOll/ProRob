import rclpy
from rclpy.node import Node
from example_interfaces.srv import SetBool
from package_master_interfaces.srv import AddThreeInts, RobotPositions
from package_master_interfaces.msg import Num 



class SendPosService(Node):
    def __init__(self):
        super().__init__('send_pos_service')
        self.service = self.create_service(RobotPositions, 'get_robot_positions', self.handle_request)
        self.destroy_after_response = False
        print("init")

    def get_position(self, request):
        robot_position_map = { #a changer (récuperer les positions reelles)
            "drone1": (1.0, 2.0, 3.0),
            "drone2": (4.0, 5.0, 6.0),
            "drone3": (7.0, 8.0, 9.0)
        }
        pos_dict = {
            name: robot_position_map.get(name, (0.0, 0.0, 0.0))
            for name in request.robot_names
        }
        return pos_dict
    
    def handle_request(self, request, response):
        self.get_logger().info('Incoming request')
        pos_dict = self.get_position(request)
        for name, position in pos_dict.items():
            response.robot_names.append(name)
            response.positions_x.append(position[0])
            response.positions_y.append(position[1])
            response.positions_z.append(position[2])
        self.destroy_after_response = True
        return response



class IsReadyService(Node):
    def __init__(self):
        super().__init__('is_ready_service')
        self.service = self.create_service(SetBool, 'check_ready', self.handle_request)
        self.destroy_after_response = False
        print("init")

    def is_ready(self):
        return True  # Par exemple, une condition sur un capteur ou un autre nœud

    def handle_request(self, request, response):
        self.get_logger().info('Incoming request')
        response.success = self.is_ready()  # Appelle une fonction pour déterminer l'état
        response.message = 'Ready state checked'
        #self.get_logger().info(f'Responding with ready state: {response.success}')
        self.destroy_after_response = True
        return response



def main(args=None):
    rclpy.init(args=args)

    # Lancer SendPosService
    send_pos_service = SendPosService()
    while rclpy.ok():
        print("1")
        rclpy.spin_once(send_pos_service)
        if send_pos_service.destroy_after_response:
            send_pos_service.destroy_node()
            break
    print("stage 1 done")

    #Lancer IsReadyService après SendPosService
    node = IsReadyService()
    while rclpy.ok():
        print("2")
        rclpy.spin_once(node)
        if node.destroy_after_response:
            node.destroy_node()
            break
    print("stage 2 done")

    rclpy.shutdown()

if __name__ == '__main__':
    main()
