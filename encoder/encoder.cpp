#include "encoder.hpp"
#include <iostream>

int old_value;

Encoder::Encoder(int pin):encoder_pin(pin)
{
  this->encoder_pin = pin;//Store pin
  //Configure as input
  encoder_pin.setup();
  encoder_pin.type_input();
  old_value = 0;
}

int Encoder::tick()
{
  // if (encoder_pin.read() > 0)//Read high -> wait until goes '0'
  //   while (encoder_pin.read() != 0)
  //   {}
  // else// Read at 0, wait until arrives to '1'
  //   while (encoder_pin.read() == 0)//Read low -> wait until goes high
  //   {}
  int value = encoder_pin.read();
  if ( value != old_value)
  {
    old_value = value;
    return 1;//Change happened
  }
  else
  {
    old_value = value;
    return 0;//No Change
  }
}

// int main(int argc, char const *argv[]) {
//   /* code */
//   Encoder encoder(21);
//   #define TRUE 1
//   int value;
//   while (1) {
//     value = encoder.tick();
//     if (value == TRUE)
//       std::cout << "Tick read!" << '\n';
//   }
//   return 0;
// }
