cmake_minimum_required(VERSION 3.8)
project(b_tf)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(turtlesim REQUIRED)

set(dependencies
  rclcpp
  tf2
  tf2_ros
  turtlesim
)

add_executable(static_broadcaster src/static_broadcaster.cpp)
ament_target_dependencies(static_broadcaster ${dependencies})

add_executable(broadcaster src/broadcaster.cpp)
ament_target_dependencies(broadcaster ${dependencies})

add_executable(listener src/listener.cpp)
ament_target_dependencies(listener ${dependencies})

install(TARGETS
  static_broadcaster
  broadcaster
  listener
  
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
