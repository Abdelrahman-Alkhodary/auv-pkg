cmake_minimum_required(VERSION 2.8.3)
project(auv_msgs)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  sensor_msgs
  geometry_msgs
  geographic_msgs
  message_generation
)

add_message_files(
  DIRECTORY
    msg
  FILES
    BodyForceRequest.msg
    BodyVelocityRequest.msg
    NavigationStatus.msg
    NED.msg
    NEDArray.msg
    VehiclePose.msg
    VehiclePoseArray.msg
    WorldWaypointRequest.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
  sensor_msgs
  geometry_msgs
  geographic_msgs
)

catkin_package(
  CATKIN_DEPENDS
    geographic_msgs
    geometry_msgs
    std_msgs
    sensor_msgs
    message_runtime
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
)


#This will create executables of the nodes
add_executable(GPS_node src/GPS_node.cpp)
add_executable(Path_Planning_node src/Path_Planning_node.cpp)
add_executable(Thrusters_node src/Thrusters_node.cpp)
add_executable(IMU_node src/IMU_node.cpp)
#This will generate message header file before building the target
add_dependencies(GPS_node
auv_msgs_generate_messages_cpp)
add_dependencies(Path_Planning_node
auv_msgs_generate_messages_cpp)
add_dependencies(Thrusters_node
auv_msgs_generate_messages_cpp)
add_dependencies(IMU_node
auv_msgs_generate_messages_cpp)
#This will link executables to the appropriate libraries
target_link_libraries(GPS_node ${catkin_LIBRARIES})
target_link_libraries(Path_Planning_node ${catkin_LIBRARIES})
target_link_libraries(Thrusters_node ${catkin_LIBRARIES})
target_link_libraries(IMU_node ${catkin_LIBRARIES})



