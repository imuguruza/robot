// Taken from
// http://elinux.org/RPi_GPIO_Code_Samples#Direct_register_access

#ifndef GPIO_H
#define GPIO_H

// Access from ARM Running Linux

#define BCM2708_PERI_BASE        0x3F000000
#define GPIO_BASE                (BCM2708_PERI_BASE + 0x200000) /* GPIO controller */


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define PAGE_SIZE (4*1024)
#define BLOCK_SIZE (4*1024)

//Define Class gpio
class Gpio {
  public:
    Gpio (int pin);
    void setup();//Initialize, open /mem
    void unload(); // Destroy the GPIOs
    void type_input(); //Configure as input the pin
    void type_output(); //Configure as output the pin
    void write(int value); //Write 0/1 into GPIO
    int read();//Read the value of the GPIO

  private:

    int  mem_fd;
    void *gpio_map;
    // I/O access
    volatile unsigned *gpio;
    int pin_number;//Set into constructor the value
};

#endif
