import sys

from package_master_interfaces.srv import AddThreeInts
from package_master_interfaces.msg import Num

import rclpy
from rclpy.node import Node


class ClassDronePos(Node):

    def __init__(self):
        super().__init__('class_drone_pos')
        self.cli = self.create_client(SendPos, 'send_pos')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = SendPos.Request()

    def send_request(self):
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()


def main(args=None):
    rclpy.init(args=args)

    minimal_client = MinimalClientAsync()
    response = minimal_client.send_request(int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]))
    minimal_client.get_logger().info(
        'Result of add_three_ints: for %d + %d + %d = %d' %
        (int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]), response.sum))

    minimal_client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()