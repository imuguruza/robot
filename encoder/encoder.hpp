#include "gpio.hpp"

class Encoder {
  public:
    Encoder (int pin);
    //void setup();//Initialize, open /mem
    int tick();//Read, return '1' when tick is read

  private:
    int pin_number;//Set into constructor the value
    Gpio encoder_pin;
};
