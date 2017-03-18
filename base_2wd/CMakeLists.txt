cmake_minimum_required(VERSION 2.8.3)
project(base_2wd)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

## Declare ROS messages and services
##add_message_files(DIRECTORY msg FILES pwm.msg)

## Generate added messages and services
##generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

#SET(CMAKE_CXX_FLAGS "fpermissive")
add_definitions ( -std=c++11 )

add_executable(base_2wd src/base_2wd.cpp src/motor.cpp src/gpio.cpp src/main.cpp)
target_link_libraries(base_2wd ${catkin_LIBRARIES})

#file(GLOB SCRIPTS ${PROJECT_SOURCE_DIR}/examples/*)
#  catkin_install_python(PROGRAMS
#  ${SCRIPTS}
#  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
#)

install(
	TARGETS base_2wd base_2wd
	ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
	LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
