cmake_minimum_required(VERSION 3.8)
project(g_generate_parameter_file)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

find_package(generate_parameter_library REQUIRED)

generate_parameter_library(
  turtlesim_parameters # cmake target name for the parameter library
  src/turtlesim_parameters.yaml # path to input yaml file
)

add_executable(minimal_node src/turtlesim.cpp)
target_link_libraries(minimal_node PRIVATE
  rclcpp::rclcpp
  turtlesim_parameters
)

install(TARGETS
  minimal_node
  DESTINATION lib/${PROJECT_NAME}
)
ament_package()


