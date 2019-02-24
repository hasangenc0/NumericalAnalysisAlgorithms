#include "Test.hpp"
#include <algorithm>    // std::equal_range
#include "gtest/gtest.h"
#include "OneVariableFunction.hpp"
#include "BisectionMethod.hpp"
#include "FixedPointMethod.hpp"
#include  <cmath>

// define one variable function
double fn (double arg) {
  return pow(arg, 3) + 4*pow(arg,2) - 10;
}

// bisection metod parameters
int range[2] = {1, 2};
int iterateNumber = 100;
double tol = 0.0001;

OneVariableFunction func(fn);
BisectionMethod b1(range, iterateNumber, tol,&func);

// test class
myTest::Test t;

TEST(BisctionMethod, Test1) {
  double res = fn(b1.findRoot ());
  EXPECT_TRUE(t.isBetween(res, tol, -1*tol)) ;
}

int main (int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
