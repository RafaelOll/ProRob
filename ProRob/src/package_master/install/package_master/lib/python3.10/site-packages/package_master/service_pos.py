import rclpy
from rclpy.node import Node
from example_interfaces.srv import Trigger
from geometry_msgs.msg import Point

class CombinedService(Node):

    def __init__(self):
        super().__init__('combined_service')

        # Service pour vérifier la disponibilité
        self.is_ready_state = True  # Définissez l'état initial comme prêt ou non prêt
        self.is_ready_srv = self.create_service(Trigger, 'is_ready', self.is_ready_callback)
        
        # Service pour obtenir les coordonnées
        self.get_coordinates_srv = self.create_service(Trigger, 'get_coordinates', self.get_coordinates_callback)

    def is_ready_callback(self, request, response):
        response.success = self.is_ready_state
        response.message = 'Service is ready' if self.is_ready_state else 'Service is not ready'
        self.get_logger().info(f'Is ready service: {response.message}')
        return response

    def get_coordinates_callback(self, request, response):
        if self.is_ready_state:
            point = Point()
            point.x = 1.23
            point.y = 4.56
            point.z = 7.89
            response.success = True
            response.message = f'Coordinates: ({point.x}, {point.y}, {point.z})'
            self.get_logger().info(f'Returning coordinates: {response.message}')
        else:
            response.success = False
            response.message = 'Service is not ready to provide coordinates'
            self.get_logger().info(response.message)
        return response

def main(args=None):
    rclpy.init(args=args)
    combined_service = CombinedService()
    rclpy.spin(combined_service)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
