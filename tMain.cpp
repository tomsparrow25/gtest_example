#include "gtest/gtest.h"

int main(int argc, char **argv) {
  /* Parses the command line for googletest flags, and removes all recognized flags.
   * You must call this function before calling RUN_ALL_TESTS(), or the flags won't be properly
   * initialized.*/
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}