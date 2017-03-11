#include "motor.hpp"

#ifndef BASE
#define BASE
//Define pins each motor is going to use
#define motorA_pin1 19
#define motorA_pin2 16
#define motorB_pin1 26
#define motorB_pin2 20

class Base {
  public:
    Base ();
    void stop();
    void forward();
    void backward();
    void right();
    void left();
 private:
    Motor MotorA;
    Motor MotorB;
};
#endif
