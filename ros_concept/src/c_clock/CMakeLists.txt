cmake_minimum_required(VERSION 3.8)
project(c_clock)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)

set(dependencies
  rclcpp
  tf2
  tf2_ros
)

add_executable(test_clock src/test_clock.cpp)
ament_target_dependencies(test_clock ${dependencies})


install(TARGETS
  test_clock

  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
