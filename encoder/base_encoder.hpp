#include "encoder.hpp"
#include <thread>
#include <iostream>
#define TRUE 1

class Base_encoder {
  public:
    Base_encoder (int left_pin, int right_pin);
    //void setup();//Initialize, open /mem
    void read_ticks();//Read, return when tick is read

  private:
    int encoder_left_pin;//Set into constructor the value
    int encoder_right_pin;//Set into constructor the value
    Encoder encoder_left;
    Encoder encoder_right;
};
