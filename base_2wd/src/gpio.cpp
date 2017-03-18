#include "gpio.hpp"
//Class constructor
Gpio::Gpio (int pin){
 this->pin_number = pin;//Store the pin number
}

void Gpio::setup(){

  /* open /dev/mem */
  if ((mem_fd = open("/dev/mem", O_RDWR|O_SYNC) ) < 0) {
    printf("can't open /dev/mem \n");
    exit(-1);
  }
  /* mmap GPIO */
  gpio_map = mmap(
      NULL,             //Any adddress in our space will do
      BLOCK_SIZE,       //Map length
      PROT_READ|PROT_WRITE,// Enable reading & writting to mapped memory
      MAP_SHARED,       //Shared with other processes
      mem_fd,           //File to map
      GPIO_BASE         //Offset to GPIO peripheral
  );

  close(mem_fd); //No need to keep mem_fd open after mmap

  if (gpio_map == MAP_FAILED) {
//    printf("mmap error %d\n", (int)gpio_map);//errno also set!
    printf("mmap error \n");//errno also set!
    exit(-1);
  }

  // Always use volatile pointer!
  gpio = (volatile unsigned *)gpio_map;

  //*(gpio+((pin_number)/10)) &= ~(7<<(((pin_number)%10)*3));
}

void Gpio::unload(){
  //Empty fn, not sure how to unload "gpio_map" variable
}

void Gpio::type_input(){
  //*(gpio+((pin_number)/10)) &= ~(7<<(((pin_number)%10)*3));
}

void Gpio::type_output(){
  *(gpio+((pin_number)/10)) |=  (1<<(((pin_number)%10)*3));
  //I don't understand why is the GPIO referenced to 1v8, instead of 3v3
  //Check this later, not essential right now.
}

void Gpio::write(int value){
  if (value == 1)
    *(gpio+7) = (1<<pin_number);
    //printf("Writing 1\n");
  else
    *(gpio+10) = (1<<pin_number);
    //printf("Writing 0\n");
}

int Gpio::read(){
  return (*(gpio+13)&(1<<pin_number)); // 0 if LOW, (1<<pin_number) if HIGH
}

/*
 ** EXAMPLE OF HOW TO USE IT **
  ============================
 **                          **
*/

/*
int main(){
  int pin = 20;// Careful, GPIO number, no RPi Pin number!
  Gpio gpio(pin);
  gpio.setup();
  gpio.type_output();
  int in = 21;
  Gpio input(in);
  input.setup();
  input.type_output();
  input.write(1);
  input.write(0);
  while(1){
    gpio.write(1);
    int value = input.read();
    printf("Read value is %d\n", value);
    sleep(1);
    gpio.write(0);
    value = input.read();
    printf("Read value is %d\n", value);
    sleep(1);
  }
}
*/
