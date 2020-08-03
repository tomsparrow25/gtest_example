#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "c_codeToBeTestedMock.h"
// instantiate mocked lib
std::unique_ptr<BCM2835Lib_MOCK> TestFixture::_bcm2835libMock;

// fake lib functions
int  bcm2835_init() {
    return TestFixture::_bcm2835libMock->bcm2835_init();
}
void bcm2835_gpio_fsel(uint8_t pin, uint8_t mode) {
    TestFixture::_bcm2835libMock->bcm2835_gpio_fsel(pin,mode);
}
