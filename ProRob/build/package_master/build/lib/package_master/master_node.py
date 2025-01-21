import rclpy
from rclpy.node import Node
from example_interfaces.srv import Trigger, SetBool
from geometry_msgs.msg import Point
from example_interfaces.srv import AddTwoInts, SetBool  # Adapter aux services requis
from std_msgs.msg import Bool
from package_master_interfaces.srv import AddThreeInts, RobotPositions, SendPositions
from package_master_interfaces.msg import Num




class AskForPosClient(Node):
    def __init__(self):
        super().__init__('ask_for_pos_client')
        self.client = self.create_client(AddThreeInts, 'add_three_ints') #a changer
        self.request = AddThreeInts.Request() #a changer
        self.response = None
        self.completed = False

    def send_request(self, a, b, c):
        self.request.a = a
        self.request.b = b
        self.request.c = c
        self.future = self.client.call_async(self.request)

    def check_response(self):
        if self.future.done():
            try:
                self.response = self.future.result()
                self.get_logger().info(f'Received response from first service: {self.response.sum}')
                self.completed = True
            except Exception as e:
                self.get_logger().error(f'Failed to call first service: {e}')
                self.completed = True



class GetPosClient(Node):
    def __init__(self):
        super().__init__('get_pos_client')
        self.client = self.create_client(RobotPositions, 'get_robot_positions')
        self.request = RobotPositions.Request()

    def send_request(self):
        self.request.robot_names = ["drone1", "drone2", "drone3"]
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
        for name, position in pos_dict.items():
            request.robot_names.append(name)
            request.positions_x.append(position[0])
            request.positions_y.append(position[1])
            request.positions_z.append(position[2])
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



class IsReadyClient(Node):
    def __init__(self):
        super().__init__('is_ready_client')
        self.client = self.create_client(SetBool, 'check_ready')
        self.request = SetBool.Request()
        #self.future = None
        #self.response = None  # Initialisation de l'attribut response
        #self.completed = False

    def send_request(self):
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


# class StartOrderClient(Node):
#     def __init__(self):
#         super().__init__('start_order_client')
#         self.client = self.create_client(StartMooving, 'start_mooving')
#         self.request = StartMooving.Request()
#         self.response = None

#     def send_request(self, condition):
#         self.request.data = condition
#         self.future = self.client.call_async(self.request)

#     def check_response(self):
#         if self.future.done():
#             try:
#                 self.response = self.future.result()
#                 self.get_logger().info(f'Received response from second service: {self.response.success}, message: {self.response.message}')
#             except Exception as e:
#                 self.get_logger().error(f'Failed to call second service: {e}')



def main(args=None):
    rclpy.init(args=args)

    # zero_client = AskForPosClient()
    # first_client = GetPosClient()
    # second_client = IsReadyClient()

    # zero_client.send_request(5, 7, 5)
    # while rclpy.ok():
    #     rclpy.spin_once(zero_client)
    #     zero_client.check_response()
    #     if zero_client.completed:
    #         position_dict = first_client.send_request()
    #         break
    
    # while rclpy.ok():
    #     rclpy.spin_once(first_client)
    #     if position_dict:
    #         print(f"Dictionnaire des positions : {position_dict}")  # Affiche le résultat
    #         second_client.send_request()
    #         break

    # print("dddddd")
    # while rclpy.ok():
    #     rclpy.spin_once(second_client)
    #     second_client.check_response()
    #     if second_client.response:
    #         print(f"Réponse reçue : {second_client.response.success}")
    #         break

    # zero_client.destroy_node()
    # first_client.destroy_node()
    # second_client.destroy_node()

    second_client = IsReadyClient()
    print(rclpy.ok())
    second_client.send_request()
    print(rclpy.ok())
    while rclpy.ok():
        rclpy.spin_once(second_client)
        print("cccc")
        second_client.check_response()
        print("bbbbb")
        if second_client.response:
            print("aaaaaaaa")
            print(f"Réponse reçue : {second_client.response.success}")
            break
    second_client.destroy_node()


    rclpy.shutdown()

if __name__ == '__main__':
    main()
