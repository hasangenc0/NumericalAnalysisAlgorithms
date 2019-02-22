#include "Test.hpp"
#include "gtest/gtest.h"
#include "OneVariableEquation.hpp"
// Methods
#include "BisectionMethod.hpp"
#include "FixedPointMethod.hpp"

typedef OneVariableEquation OVE;
typedef BisectionMethod Bisection;

TEST(SquareFuncTest, PositiveNos) {
  EXPECT_EQ (16.0, Bisection::square (4.0));
  EXPECT_EQ (25.0, Bisection::square (5.0));
  EXPECT_EQ (36.0, Bisection::square (6.0));
}

int main (int argc, char *argv[]) {
  Bisection *bisection = new Bisection();

  ::testing::InitGoogleTest(&argc, argv);
  Bisection::square(4.0);

  return RUN_ALL_TESTS();
}
