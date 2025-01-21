import rclpy
from rclpy.node import Node
from example_interfaces.srv import Trigger, SetBool
from geometry_msgs.msg import Point
from example_interfaces.srv import AddTwoInts, SetBool  # Adapter aux services requis
from std_msgs.msg import Bool
from package_master_interfaces.srv import AddThreeInts
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


class IsReadyClient(Node):
    def __init__(self):
        super().__init__('is_ready_client')
        self.client = self.create_client(SetBool, 'check_ready')
        self.future = None
        self.response = None  # Initialisation de l'attribut response
        self.completed = False

    def send_request(self):
        self.request = SetBool.Request()
        self.future = self.client.call_async(self.request)
        # rclpy.spin_until_future_complete(self, future)
        # if future.result() is not None:
        #     self.get_logger().info(f'Server responded: {future.result().success}, {future.result().message}')
        # else:
        #     self.get_logger().error('Failed to call service')

    def check_response(self):
        if self.future.done():
            try:
                self.response = self.future.result()
                self.get_logger().info(f'Received response from second service: {self.response.success}')
                self.completed = True
            except Exception as e:
                self.get_logger().error(f'Failed to call first service: {e}')
                self.completed = True


class StartOrderClient(Node):
    def __init__(self):
        super().__init__('start_order_client')
        self.client = self.create_client(StartMooving, 'start_mooving')
        self.request = StartMooving.Request()
        self.response = None

    def send_request(self, condition):
        self.request.data = condition
        self.future = self.client.call_async(self.request)

    def check_response(self):
        if self.future.done():
            try:
                self.response = self.future.result()
                self.get_logger().info(f'Received response from second service: {self.response.success}, message: {self.response.message}')
            except Exception as e:
                self.get_logger().error(f'Failed to call second service: {e}')



def main(args=None):
    rclpy.init(args=args)

    first_client = AskForPosClient()
    second_client = IsReadyClient()

    first_client.send_request(5, 7, 5)
    while rclpy.ok():
        rclpy.spin_once(first_client)
        first_client.check_response()
        if first_client.completed:
            #second_client.send_request(first_client.response.sum > 10)
            second_client.send_request()
            break

    while rclpy.ok():
        rclpy.spin_once(second_client)
        second_client.check_response()
        if second_client.response:
            print(f"Réponse reçue : {second_client.response.success}")
            break

    first_client.destroy_node()
    second_client.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
