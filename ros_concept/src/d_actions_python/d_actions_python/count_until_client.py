#!/user/bin/env python3
import rclpy
import rclpy.action
from rclpy.node import Node
from rclpy.action import ActionClient
from e_interfaces.action import CountUntil

import time

class CountUntilCLientNode(Node):
    def __init__(self):
        super().__init__("count_until_client")
        self.count_until_client_ = ActionClient(
            self,
            CountUntil,
            "count_until")

    def send_goal(self, targer_number, period):

        # wait for service
        self.get_logger().info("waiting for service...")
        self.count_until_client_.wait_for_server()

        #create a goal
        goal = CountUntil.Goal()
        goal.period = period
        goal.target_number = targer_number

        #send goal
        self.get_logger().info("Sending goal")
        self.count_until_client_.send_goal_async(goal)



def main(args=None):
    rclpy.init(args=args)
    node = CountUntilCLientNode()
    node.send_goal(10,0.2)
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
     main()