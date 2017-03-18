#include "ros/ros.h"
#include "std_msgs/String.h"
#include "base_2wd.hpp"
#include <string>
#include <iostream>


Base base;

void keyCallback(const std_msgs::String::ConstPtr& msg)
{
  std::string data = msg->data.c_str();
  std::cout << ("I heard: ") << data << std::endl;

  if (data.compare("forward") == 0)
    base.forward();
  if (data.compare("backward") == 0)
    base.backward();
  if (data.compare("left") == 0)
    base.left();
  if (data.compare("right") == 0)
    base.right();

  // if (msg->data.c_str() == "forward")
  //   base.forward();
  // if (msg->data.c_str() == "backward")
  //   base.backward();
  // if (msg->data.c_str() == "left")
  //   base.left();
  // if (msg->data.c_str() == "right")
  //   base.right();
}

int main(int argc, char **argv) {

  /**** INIT ROS STUFFS  *****/
  ros::init(argc, argv, "base_2wd");
  std_msgs::String msg;
  ros::NodeHandle n;
  ros::Subscriber key_sub = n.subscribe("key_teleop", 1000, keyCallback);
  ros::Rate loop_rate(1);
  /***************************/


  while (ros::ok())
    ros::spin();
return 0;
}
