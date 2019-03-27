#include <stdio.h>
#include <math.h>

// newton raphson method
double NewtonRaphson(int range[2], int iterate, double tolerans);

// our function
double function(double x);
// derivative of our function (we use it in formula)
double derivativeFunction(double x);

int main() {
  // range of the function
  int range[2] = {1, 2};

  // get roots of function with NewtonRaphson method
  double result = NewtonRaphson(range, 1000, 0.001);

  // print root of function if exists
  printf("Root of function: %lf \n", result);

  return 0;
}

// Functions

// e^x + 2^-x + 2cosx -6
double function(double x) {
  const double e = exp(1.0);
  return pow(e, x) + pow(2, -1*x) + 2*cos(x) - 6;
}

// e^x - ln2*2^-x - 2sinx
double derivativeFunction(double x) {
  const double e = exp(1.0);
  return pow(e, x) - log(2)*pow(2, -1*x) - 2*sin(x);
}

double NewtonRaphson(int range[2], int iterate, double tolerans) {
	// ranges
	double p0 = (double) (range[0] + range[1])/2;

	double p;

	for(int i  = 0; i < iterate; i++) {
    p = p0 - (function(p0)/derivativeFunction(p0));

		if(fabs(p - p0) < tolerans) {
			return p;
		}

		p0 = p;
	}

  // if root can not found
	printf("Method failed after %d iterations.\n", iterate);

	return 0;
}
