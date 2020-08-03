// MOCKING C-Functions with GMOCK :)
#include <memory>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class BCM2835Lib_MOCK{
public:
    virtual ~BCM2835Lib_MOCK(){}

    // mock methods
    MOCK_METHOD0(bcm2835_init,int());
    MOCK_METHOD2(bcm2835_gpio_fsel,void(uint8_t,uint8_t));
};

class TestFixture: public ::testing::Test {
public:
    TestFixture(){
        _bcm2835libMock.reset(new ::testing::NiceMock<BCM2835Lib_MOCK>());
    }
    ~TestFixture(){
        _bcm2835libMock.reset();
    }
    virtual void SetUp(){}
    virtual void TearDown(){}

    // pointer for accessing mocked library
    static std::unique_ptr<BCM2835Lib_MOCK> _bcm2835libMock;
};