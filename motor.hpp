#ifndef MOTOR_H
#define MOTOR_H

#include "gpio.hpp"
#include <thread>

//Define Class gpio
class Motor {
  public:
    Motor (int pin1, int pin2);
    void stop();
    void forward();
    void backward();

  private:
    int pin_1;
    int pin_2;
};

#endif
