cmake_minimum_required(VERSION 3.0.2)
project(actions_quiz)

find_package(catkin REQUIRED COMPONENTS
  actionlib
  actionlib_msgs
  roscpp
  rospy
  std_msgs
  message_generation  # AsegÃºrate de incluir esto
)

generate_messages(
  DEPENDENCIES
  actionlib_msgs
  std_msgs
)

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

add_action_files(
  FILES
  CustomActionMsg.action
)

catkin_package(
  CATKIN_DEPENDS actionlib actionlib_msgs roscpp rospy std_msgs message_runtime
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(action_server src/action_server.cpp)
add_dependencies(action_server ${action_server_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(action_server ${catkin_LIBRARIES})