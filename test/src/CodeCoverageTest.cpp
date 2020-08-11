#include "gmock/gmock.h"
#include "CodeCoverage.h"

TEST(CodeCoverage, TestCaseOne) {
    Sum SumUnderTest;
    SumUnderTest.setAValue(10);
    SumUnderTest.setBValue(10);

    EXPECT_EQ(20, SumUnderTest.executeSum());
}