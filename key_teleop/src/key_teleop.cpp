#include <unistd.h>
#include <stdlib.h>
#include <termios.h> // for keyboard input
#include <string.h>
//#include <sstream>
#include <stdio.h>

#include "ros/ros.h"
#include "std_msgs/String.h"


bool quit_requested = false;


std::string processKeyboardInput (char c)
{
  /*
    * Arrow keys are a bit special, they are escape characters - meaning they
    * trigger a sequence of keycodes. In this case, 'esc-[-Keycode_xxx'. We
    * ignore the esc-[ and just parse the last one. So long as we avoid using
    * the last one for its actual purpose (e.g. left arrow corresponds to
    * esc-[-D) we can keep the parsing simple.
    */
   switch (c)
   {
     case 68:// Left arrow pressed
     {
       puts("Left pressed");
       return ("left");
     }
     case 67://Right arrow pressed
     {
       puts("Right pressed");
       return ("right");
     }
     case 65://Up arrow pressed
     {
       puts("Up pressed");
       return ("forward");
     }
     case 66://Down arrow pressed
     {
       puts("Down pressed");
       return ("backward");
     }
     case 'q'://Quit arrow pressed
     {
       quit_requested = true;
       puts("q pressed, quitting...");
     }
     default:
     {
       return ("");
     }
 }

}

int main(int argc, char **argv) {
  
  std::string cmd;
  int key_file_descriptor;
  struct termios raw;
  struct termios original_terminal_state;
  //std::string name = "key_teleop";

  /**** INIT ROS STUFFS  *****/
  ros::init(argc, argv, "key_teleop");
  std_msgs::String msg;
  ros::NodeHandle n;
  ros::Publisher key_pub = n.advertise<std_msgs::String>("key_teleop", 1000);
  ros::Rate loop_rate(1);
  /***************************/

  tcgetattr(key_file_descriptor, &original_terminal_state); // get terminal properties
  memcpy(&raw, &original_terminal_state, sizeof(struct termios));

  raw.c_lflag &= ~(ICANON | ECHO);//local modes, enable canonical mode and echo
  // Setting a new line, then end of file
  raw.c_cc[VEOL] = 1;//special characters
  raw.c_cc[VEOF] = 2;
  tcsetattr(key_file_descriptor, TCSANOW, &raw);

  puts("Reading from keyboard");
  puts("---------------------------");
  puts("Press the arrow keys to move and q to quit");

  char c;
  int error;
  while (ros::ok() & (!quit_requested))
  {
  //if (read(key_file_descriptor, &c, 1) < 0)
    error = read(key_file_descriptor, &c, 1);
    if ( error < 0)//Process the error
    {//TODO I get errors, not ROSify code doesn't, C / C++ code mixture issue??
      if (error == EAGAIN)
        puts ("EAGAIN");
      else if (error == EBADF)
        puts ("EBADF");
      else if (error == EFAULT)
        puts ("EFAULT");
      else if (error == EINTR)
        puts ("EINTR");
      else if (error == EINVAL)
        puts ("EINVAL");
      else if (error == EIO)
        puts ("EIO");
      else if (error = EISDIR)
        puts ("EISDIR");
      perror("read char failed():");
      exit(-1);
    }
    cmd = processKeyboardInput(c);
    if (!cmd.empty())
    {
      msg.data = cmd;
      key_pub.publish(msg);
      ros::spinOnce();
      //Not sure if necessary
      //loop_rate.sleep();
    }
  }
  tcsetattr(key_file_descriptor, TCSANOW, &original_terminal_state);
  puts("Exit");
return 0;
}
