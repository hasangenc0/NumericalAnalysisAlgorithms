#include "Test.hpp"
#include <algorithm>    // std::equal_range
#include "gtest/gtest.h"
#include "OneVariableFunction.hpp"
#include "BisectionMethod.hpp"
#include "FixedPointMethod.hpp"
#include "NewtonRaphsonMethod.hpp"
#include  <cmath>

// define one variable function
double fn (double arg) {
  return pow(arg, 3) + 4*pow(arg,2) - 10;
}

double fixed_fn (double arg) {
  return pow((10 - pow(arg, 3)), 0.5) * 0.5;
}

double nfunc (double arg) {
  return pow(arg, 3) - 2*pow(arg,2) - 5;
}

double ndiff (double arg) {
  return 3*pow(arg, 2) - 4*arg;
}

OneVariableFunction nfn(nfunc);
OneVariableFunction ndif(ndiff);

// bisection metod parameters
int range[2] = {1, 2};
int range2[2]= {1, 4};
int iterateNumber = 10000;
double tol = 0.0001;

// Create Functions
OneVariableFunction func(fn); // for bisection
OneVariableFunction func2(fixed_fn); // for fixed point

// Equation Solver Methods
BisectionMethod b1(range, iterateNumber, tol,&func);
FixedPointMethod f1(range, iterateNumber, tol,&func2);
NewtonRaphsonMethod n1(range2, iterateNumber, tol, &nfn, &ndif);

// test class
myTest::Test t;

TEST(BisctionMethod, Test1) {
  double res = fn(b1.findRoot ());
  double res2 = fn(f1.findRoot ());
  double res3 = nfunc(n1.findRoot ());
  EXPECT_TRUE(t.isBetween(res, tol, -1*tol)) ;
  EXPECT_TRUE(t.isBetween(res2, tol, -1*tol)) ;
  EXPECT_TRUE(t.isBetween(res3, tol, -1*tol)) ;

}

int main (int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
