#include "motor.hpp"
#include <iostream>
#include <chrono>

using namespace std;

// Pass pin ctrl numbers to constructor & make startup
Motor::Motor (int pin1, int pin2):pinA(pin1), pinB(pin2)
{
  this->pin_1=pin1;
  this->pin_2=pin2;
  //Configure as outputs
  pinA.setup();
  pinA.type_output();
  pinB.setup();
  pinB.type_output();
  pinA.write(0);
  pinB.write(0);
}

void Motor::stop()
{
  pinA.write(0);
  pinB.write(0);
}

void Motor::forward()
{
  pinA.write(1);
  pinB.write(0);
}

void Motor::backward()
{
  pinA.write(0);
  pinB.write(1);
}
