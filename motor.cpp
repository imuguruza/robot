#include "motor.hpp"
#include <iostream>
#include <chrono>

using namespace std;

// Pass pin ctrl numbers to constructor & make startup
Motor::Motor (int pin1, int pin2)
{
  this->pin_1=pin1;
  this->pin_2=pin2;

  Gpio pinA (pin1);
  Gpio pinB (pin2);
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



int main(int argc, char const *argv[]) {
  Motor Motor_A (19,16);
  Motor Motor_B (26,20);

  std::cout << "Go A forward..." << '\n';
  Motor_A.forward();
  Motor_B.forward();
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  Motor_A.stop();
  Motor_B.stop();
  std::cout << "Stop..." << '\n';

  return 0;
}

//Works!
// int main(int argc, char const *argv[]) {
//
//   //Define Motor A & B control pins, using BCM naming
//   int A_pin1 = 19;
//   int A_pin2 = 16;
//   int B_pin1 = 26;
//   int B_pin2 = 20;
//
//   Gpio MotorA_1(A_pin1);
//   Gpio MotorA_2(A_pin2);
//   Gpio MotorB_1(B_pin1);
//   Gpio MotorB_2(B_pin2);
//
//   std::cout << "Motor Hello World!" << '\n';
//
//   //Start GPIOs
//   MotorA_1.setup();
//   MotorA_2.setup();
//   MotorB_1.setup();
//   MotorB_2.setup();
//   MotorA_1.type_output();
//   MotorA_2.type_output();
//   MotorB_1.type_output();
//   MotorB_2.type_output();
//
//   //Initial State, safe
//   MotorA_1.write(0);
//   MotorA_2.write(0);
//   MotorB_1.write(0);
//   MotorB_2.write(0);
//
//   //Go forward A
//   std::cout << "Go A forward..." << '\n';
//   MotorA_1.write(1);
//   MotorA_2.write(0);
//   //sleep
//   std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//   //Go backward A
//   std::cout << "Go A backward..." << '\n';
//   MotorA_1.write(0);
//   MotorA_2.write(1);
//   //sleep
//   std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//   //Go forward B
//   std::cout << "Go B forward..." << '\n';
//   MotorB_1.write(1);
//   MotorB_2.write(0);
//   //sleep
//   std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//   //Go backward B
//   std::cout << "Go B backward..." << '\n';
//   MotorB_1.write(0);
//   MotorB_2.write(1);
//   //sleep
//   std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//
//   //Safe state again
//   //Initial State, safe
//   MotorA_1.write(0);
//   MotorA_2.write(0);
//   MotorB_1.write(0);
//   MotorB_2.write(0);
//
//   std::cout << "Bye bye..." << '\n';
//
//   return 0;
// }
