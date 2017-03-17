cmake_minimum_required(VERSION 2.8.3)
project(key_teleop)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

## Declare ROS messages and services
##add_message_files(DIRECTORY msg FILES pwm.msg)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

#SET(CMAKE_CXX_FLAGS "fpermissive")
#add_definitions ( -fpermissive)

add_executable(key_teleop src/key_teleop.cpp)
target_link_libraries(key_teleop ${catkin_LIBRARIES})
##add_dependencies(key_teleop ros_erle_pwm_generate_messages_cpp)

#file(GLOB SCRIPTS ${PROJECT_SOURCE_DIR}/examples/*)
#  catkin_install_python(PROGRAMS
#  ${SCRIPTS}
#  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
#)

install(
	TARGETS key_teleop key_teleop
	ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
	LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
