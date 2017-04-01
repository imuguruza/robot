#include "base_encoder.hpp"

Base_encoder::Base_encoder (int left_pin, int right_pin):encoder_left(left_pin), encoder_right(right_pin)
{
  this->encoder_left_pin=left_pin;
  this->encoder_right_pin=right_pin;
}

void Base_encoder::read_ticks()
{
  int right_value = 0;
  int left_value = 0;
  //left_value = encoder_left.tick();
  //right_value = encoder_right.tick());

  left_value = std::thread en1(encoder_left.tick());
  right_value = std::thread en2(encoder_right.tick());
  en1.join();
  en2.join();

  if (left_value == TRUE)
    std::cout << "Left encoder tick!" << '\n';
  if (right_value == TRUE)
    std::cout << "Right encoder tick!" << '\n';
}
int main(int argc, char const *argv[]) {

  Base_encoder base_encoders (21,17);
  while (1) {
    base_encoders.read_ticks();
  }
  return 0;
}
