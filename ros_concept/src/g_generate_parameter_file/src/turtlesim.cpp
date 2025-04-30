#include <rclcpp/rclcpp.hpp>
#include "turtlesim_parameters.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcpp::Node>("turtlesim");
  auto param_listener = std::make_shared<turtlesim::ParamListener>(node);
  auto params = param_listener->get_params();
  param_listener->  
  auto color = params.background;
  RCLCPP_INFO(node->get_logger(),
    "Background color (r,g,b): %d, %d, %d",
    color.r, color.g, color.b);

  return 0;
}