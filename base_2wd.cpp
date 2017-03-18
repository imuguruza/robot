#include "base_2wd.hpp"

// Pass pin ctrl numbers to constructor & make startup
Base::Base():MotorA(motorA_pin1, motorA_pin2), MotorB(motorB_pin1,motorB_pin2)
{
  //Just in case stop the motors
  MotorA.stop();
  MotorB.stop();
}
void Base::stop(){
  MotorA.stop();
  MotorB.stop();
}
void Base::forward_steady(){
  MotorA.forward();
  MotorB.forward();
}
void Base::forward(){
  MotorA.forward();
  MotorB.forward();
  std::this_thread::sleep_for(std::chrono::microseconds(100000));
  MotorA.stop();
  MotorB.stop();
}
void Base::backward(){
  MotorA.backward();
  MotorB.backward();
  std::this_thread::sleep_for(std::chrono::microseconds(100000));
  MotorA.stop();
  MotorB.stop();
}
void Base::backward_steady(){
  MotorA.backward();
  MotorB.backward();
}
void Base::right(){
  MotorA.forward();
  MotorB.backward();
  std::this_thread::sleep_for(std::chrono::microseconds(100000));
  MotorA.stop();
  MotorB.stop();
}
void Base::right_steady(){
  MotorA.forward();
  MotorB.backward();
}
void Base::left(){
  MotorA.backward();
  MotorB.forward();
  std::this_thread::sleep_for(std::chrono::microseconds(100000));
  MotorA.stop();
  MotorB.stop();
}
void Base::left_steady(){
  MotorA.backward();
  MotorB.forward();
}
