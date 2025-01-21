import rclpy
from rclpy.node import Node
from example_interfaces.srv import SetBool
from package_master_interfaces.srv import AddThreeInts
from package_master_interfaces.msg import Num 


class MinimalService(Node):

    def __init__(self):
        super().__init__('minimal_service')
        self.srv = self.create_service(AddThreeInts, 'add_three_ints', self.add_three_ints_callback)

    def add_three_ints_callback(self, request, response):
        response.sum = request.a + request.b + request.c
        self.get_logger().info('Incoming request\na: %d b: %d c: %d'  % (request.a, request.b, request.c))

        return response


class IsReadyService(Node):
    def __init__(self):
        super().__init__('is_ready_service')
        self.service = self.create_service(SetBool, 'check_ready', self.handle_request)

    def is_ready(self):
        # Replace
        return True  # Par exemple, une condition sur un capteur ou un autre nœud

    def handle_request(self, request, response):
        response.success = self.is_ready()  # Appelle une fonction pour déterminer l'état
        response.message = 'Ready state checked'
        self.get_logger().info(f'Responding with ready state: {response.success}')
        return response



def main(args=None):
    rclpy.init(args=args)

    # Lancer MinimalService
    minimal_service = MinimalService()
    rclpy.spin_once(minimal_service)
    minimal_service.destroy_node()
    
    # Lancer IsReadyService après MinimalService
    node = IsReadyService()
    rclpy.spin_once(node)
    node.destroy_node()
    
    rclpy.shutdown()

if __name__ == '__main__':
    main()
