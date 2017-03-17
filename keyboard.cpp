
#include <unistd.h>
#include <stdlib.h>
#include <termios.h> // for keyboard input
#include <string.h>
#include <stdio.h>

bool quit_requested = false;


void processKeyboardInput (char c)
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
       break;
     }
     case 67://Right arrow pressed
     {
       puts("Right pressed");
       break;
     }
     case 65://Up arrow pressed
     {
       puts("Up pressed");
       break;
     }
     case 66://Down arrow pressed
     {
       puts("Down pressed");
       break;
     }
     case 'q'://Quit arrow pressed
     {
       quit_requested = true;
       puts("q pressed, quitting...");
     }
     default:
     {
       break;
     }
 }

}

int main(int argc, char const *argv[]) {
  int key_file_descriptor;
  struct termios raw;
  struct termios original_terminal_state;

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
  while (!quit_requested)
  {
    if (read(key_file_descriptor, &c, 1) < 0)
    {
      perror("read char failed():");
      exit(-1);
    }
    processKeyboardInput(c);
  }
  tcsetattr(key_file_descriptor, TCSANOW, &original_terminal_state);
  puts("Exit");
return 0;
}
