#include "motor.hpp"
#include <chrono>

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
    void forward_steady();
    void backward();
    void backward_steady();
    void right();
    void right_steady();
    void left();
    void left_steady();
 private:
    Motor MotorA;
    Motor MotorB;
};
#endif
