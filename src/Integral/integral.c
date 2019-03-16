/**
 * Hasan Genç
 */

#include <stdio.h>
#include <math.h> // for euler number

// integral is in the interval 0 - 4
const int interval[2] = {0, 4};

// function that we will take the integral
double function(int x) {
	const double Euler = exp(1.0);
	return pow(Euler, x);
}

//prototypes
void integral();
void trapez();
double simpson();
void simpsonThreeEight();
void boole();

int main() {
	integral();
  return 0;
}


void trapez() {

}

double simpson() {
  double h = (interval[1] - interval[0])/2;
  double point = 3;
  double x0 = interval[0];
  double x1 = x0 + h;
  double x2 = x0 + 2*h;
  double fx0 = function(x0);
  double fx1 = function(x1);
  double fx2 = function(x2);
  printf("%lf %lf %lf\n", fx0, fx1, fx2);
  return (h/point)*(fx0 + 4*fx1 + fx2);   
}

void simpsonThreeEight() {

}

void boole() {

}

void  integral() {
  printf("%lf\n", simpson());
}
