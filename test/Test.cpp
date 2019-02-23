#include "Test.hpp"
#include "gtest/gtest.h"
#include "OneVariableFunction.hpp"
#include "BisectionMethod.hpp"
#include "FixedPointMethod.hpp"

double fn (double arg) {
  return 61;
}
OneVariableFunction func(fn);

int range[2] = {1, 2};
int iterateNumber = 12;
BisectionMethod  b1(range, iterateNumber);

TEST(SquareFuncTest, PositiveNos) {
  EXPECT_EQ (164.0, b1.findRoot ());
}

int main (int argc, char *argv[]) {
	b1.findRoot();
  std::cout<<func.call(4.4);
  ::testing::InitGoogleTest(&argc, argv);
  return 0;
  return RUN_ALL_TESTS();
}
