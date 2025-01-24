import rclpy
from rclpy.node import Node
from example_interfaces.srv import Trigger, SetBool
from geometry_msgs.msg import Point
from example_interfaces.srv import AddTwoInts, SetBool  # Adapter aux services requis
from std_msgs.msg import Bool
from package_master_interfaces.srv import AddThreeInts, RobotPositions, SendPositions
from package_master_interfaces.msg import Num



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



class SendPosClient(Node):
    def __init__(self):
        super().__init__('ask_for_pos_client')
        self.client = self.create_client(SendPositions, 'send_positions')
        self.request = SendPositions.Request()
        self.response = None
        self.completed = False

    def send_request(self, pos_dict):
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting...')

        for name, position in pos_dict.items():
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



class TakeOffClient(Node):
    def __init__(self):
        super().__init__('take_off_client')
        self.client = self.create_client(SetBool, 'check_ready')
        self.request = SetBool.Request()
        #self.future = None
        #self.response = None  # Initialisation de l'attribut response
        #self.completed = False

    def send_request(self):
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting...')
        self.request.data = True
        self.future = self.client.call_async(self.request)
        rclpy.spin_until_future_complete(self, self.future)
        if self.future.done():
            try:
                self.response = self.future.result()  # Récupérer la réponse du service
                self.get_logger().info(f'Server responded: {self.response.success}, {self.response.message}')
            except Exception as e:
                self.get_logger().error(f'Failed to call service: {e}')
        else:
            self.get_logger().error('Failed to call service')

    def check_response(self):
        if self.response:
            self.get_logger().info(f'Response received: {self.response.success}')
        else:
            self.get_logger().info('No response received yet.')



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



def main(args=None):
    rclpy.init(args=args)

    drone_names = ["drone1", "drone2", "drone3"]
    tb_names = ["tb1", "tb2", "tb3"]

    first_client = GetPosClient()
    second_client = SendPosClient()
    third_client = TakeOffClient()
    fourth_client = SendOrderClient()
    fifth_client = GetPosClient()
    sixth_client = SendPosClient()
    

    position_dict = first_client.send_request(drone_names)
    while rclpy.ok():
        rclpy.spin_once(first_client)
        if position_dict:
            print(f"Dictionnaire des positions : {position_dict}")  # Affiche le résultat
            second_client.send_request(position_dict)
            break

    while rclpy.ok():
        rclpy.spin_once(second_client)
        second_client.check_response()
        if second_client.completed:
            third_client.send_request()
            break

    while rclpy.ok():
        rclpy.spin_once(third_client)
        third_client.check_response()
        if third_client.response:
            print(f"Réponse reçue : {third_client.response.success}")
            fourth_client.send_request()
            tb_position_dict = fifth_client.send_request(tb_names)
            break

    while rclpy.ok():
        rclpy.spin_once(fourth_client)
        tb_position_dict = fifth_client.send_request(tb_names)
        break

    while rclpy.ok():
        rclpy.spin_once(fifth_client)
        if tb_position_dict:
            final_position_dict = {}
            for tb_key, tb_pos in tb_position_dict.items():
                # Récupérer le drone correspondant à partir du numéro (tb1 -> drone1, etc.)
                drone_key = f"drone{tb_key[-1]}"  # Extraire le dernier caractère de la clé pour créer la clé du drone
                if drone_key in position_dict:
                    drone_pos = position_dict[drone_key]
                    # Faire la somme des tuples
                    summed_pos = tuple(a + b for a, b in zip(tb_pos, drone_pos))
                    final_position_dict[tb_key] = summed_pos
            print(final_position_dict)
            print(f"Dictionnaire des positions : {final_position_dict}")  # Affiche le résultat
            sixth_client.send_request(final_position_dict)
            break
    
    while rclpy.ok():
        rclpy.spin_once(sixth_client)
        sixth_client.check_response()
        if sixth_client.completed:
            print("done")
            break

    first_client.destroy_node()
    second_client.destroy_node()
    third_client.destroy_node()
    fifth_client.destroy_node()
    sixth_client.destroy_node()

    print("operation done")

    rclpy.shutdown()

if __name__ == '__main__':
    main()
