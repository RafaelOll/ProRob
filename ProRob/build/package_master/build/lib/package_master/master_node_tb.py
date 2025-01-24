import rclpy
from rclpy.node import Node
from example_interfaces.srv import Trigger, SetBool
from geometry_msgs.msg import Point
from example_interfaces.srv import SetBool
from std_msgs.msg import Bool
from package_master_interfaces.srv import RobotPositions, SendPositions



class GetPosClient(Node):
    def __init__(self):
        super().__init__('get_pos_client')
        self.client = self.create_client(RobotPositions, 'get_robot_positions')
        self.request = RobotPositions.Request()

    def send_request(self, robot_names):
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting...')
        self.request.robot_names = robot_names
        self.future = self.client.call_async(self.request)
        rclpy.spin_until_future_complete(self, self.future)
        response = self.future.result()

        if response:
            # Créer un dictionnaire associant les noms de robots à leurs positions
            position_dict = {
                name: (x, y, z)
                for name, x, y, z in zip(response.robot_names, response.positions_x, response.positions_y, response.positions_z)
            }
            # Afficher le dictionnaire
            self.get_logger().info(f"Dictionnaire des positions : {position_dict}")
            return position_dict



class SendOrderClient(Node):
    def __init__(self):
        super().__init__('bool_client')
        self.client = self.create_client(SetBool, 'set_bool')

    def send_request(self):
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting...')

        # Create and send the request
        request = SetBool.Request()
        request.data = True
        future = self.client.call_async(request)
        rclpy.spin_until_future_complete(self, future)

        # Process and log the response
        if future.result() is not None:
            self.get_logger().info(f'Response: success={future.result().success}, message="{future.result().message}"')
        else:
            self.get_logger().error('Service call failed')



class SendPosClient(Node):
    def __init__(self):
        super().__init__('send_pos_client')
        self.client = self.create_client(SendPositions, 'send_positions')
        self.request = SendPositions.Request()
        self.response = None
        self.completed = False

    def send_request(self, position_dict):
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting...')
            
        for name, position in position_dict.items():
            self.request.robot_names.append(name)
            self.request.positions_x.append(position[0])
            self.request.positions_y.append(position[1])
            self.request.positions_z.append(position[2])
        self.future = self.client.call_async(self.request)

    def check_response(self):
        if self.future.done():
            try:
                self.response = self.future.result()
                self.get_logger().info(f'Received response from service: {self.response.ack}')
                self.completed = True
            except Exception as e:
                self.get_logger().error(f'Failed to call first service: {e}')
                self.completed = True



def main(args=None):
    rclpy.init(args=args)

    zero_client = SendPosClient()
    first_client = SendOrderClient()
    second_client = GetPosClient()


    
    robot_position_map = { #a changer (récuperer les positions reelles)
            "drone1": (1.0, 2.0, 3.0),
            "drone2": (4.0, 5.0, 6.0),
            "drone3": (7.0, 8.0, 9.0)
        }
    position_dict = {
        name: robot_position_map.get(name, (0.0, 0.0, 0.0))
        for name in ["drone1", "drone2", "drone3"]
    }
    zero_client.send_request(position_dict)
    while rclpy.ok():
        rclpy.spin_once(zero_client)
        zero_client.check_response()
        if zero_client.completed:
            first_client.send_request()
            break

    while rclpy.ok():
        rclpy.spin_once(first_client)
        position_dict = second_client.send_request(["tb1", "tb2", "tb3"])
        break
    
    while rclpy.ok():
        rclpy.spin_once(second_client)
        if position_dict:
            print(f"Dictionnaire des positions : {position_dict}")  # Affiche le résultat
            break


    zero_client.destroy_node()
    second_client.destroy_node()
    first_client.destroy_node()

    rclpy.shutdown()

if __name__ == '__main__':
    main()
