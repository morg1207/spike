#!/user/bin/env python3
import rclpy
import rclpy.action
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.action.server import ServerGoalHandle
from e_interfaces.action import CountUntil

import time

class CountUntilServerNode(Node):
    def __init__(self):
        super().__init__("count_until_server")
        self.count_until_server_ = ActionServer(
            self,
            CountUntil,
            "count_until",
            execute_callback=self.execute_callback)
        self.get_logger().info("Action server has been started")

    def execute_callback(self, goal_handle:ServerGoalHandle):
        # get request from goal
        target = goal_handle.request.target_number
        period = goal_handle.request.period

        #execute the action
        self.get_logger().info("Executing the goal")

        counter= 0
        for i in range(target):
            counter +=1
            time.sleep(period)
            self.get_logger().info(str(counter))
        # Once done
        goal_handle.succeed()

        result = CountUntil.Result()
        result.reached_number = counter
        return result

def main(args=None):
    rclpy.init(args=args)
    node = CountUntilServerNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
     main()