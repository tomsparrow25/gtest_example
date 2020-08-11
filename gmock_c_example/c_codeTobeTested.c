#include <stdint.h>
#ifdef UNIT_TEST
#include "fake_cFunctions.h"
//#else
//#include "real_implementation.h"
#endif

int inits(){
    return bcm2835_init();
}

void pinMode(uint8_t pin, uint8_t mode){
    bcm2835_gpio_fsel(pin, mode);
}