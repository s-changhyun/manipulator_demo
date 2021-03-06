cmake_minimum_required(VERSION 2.8.3)
project(robotis_manipulator_planning)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  control_msgs
  sensor_msgs
  std_msgs
  geometry_msgs
  moveit_msgs
  moveit_core 
  moveit_ros_planning 
  moveit_ros_planning_interface
  pluginlib
  robotis_controller_msgs
  manipulator_demo_module_msgs
  cmake_modules
)

find_package(Eigen REQUIRED)

catkin_package(
  INCLUDE_DIRS include
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${Eigen_INCLUDE_DIRS}
)

add_executable(robotis_manipulator_planning 
	src/ManipulatorPlanning.cpp
)

add_dependencies(robotis_manipulator_planning ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(robotis_manipulator_planning
  ${catkin_LIBRARIES}
)
