#include "c_codeTobeTested.h"
#include "c_codeToBeTestedMock.h"

using namespace ::testing;
using ::testing::Return;


// create unit testing class for BCM2835 from TestFixture
class BCM2835LibUnitTest : public TestFixture{
public:
    BCM2835LibUnitTest(){
        // here you can put some initializations
    }
};

TEST_F(BCM2835LibUnitTest,inits){
    EXPECT_CALL(*_bcm2835libMock,bcm2835_init()).Times(1).WillOnce(Return(1));

    EXPECT_EQ(1,inits()) << "init must return 1";
}

uint8_t RPI_V2_GPIO_P1_18=1;
uint8_t BCM2835_GPIO_FSEL_OUTP=0;
TEST_F(BCM2835LibUnitTest,pinModeTest){

    EXPECT_CALL(*_bcm2835libMock,bcm2835_gpio_fsel( (uint8_t)RPI_V2_GPIO_P1_18
                                                   ,(uint8_t)BCM2835_GPIO_FSEL_OUTP
                                                  )
               )
               .Times(1)
               ;

    pinMode((uint8_t)RPI_V2_GPIO_P1_18,(uint8_t)BCM2835_GPIO_FSEL_OUTP);
}

int main(int argc, char **argv) {
  /* Parses the command line for googletest flags, and removes all recognized flags.
   * You must call this function before calling RUN_ALL_TESTS(), or the flags won't be properly
   * initialized.*/
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}