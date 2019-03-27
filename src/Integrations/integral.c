/**
 * Hasan Genç
 */

#include <stdio.h>
#include <math.h> // for euler number

// integral is in the interval 0 - 4
const int interval[2] = {0, 4};

// function that we will take the integral
double function(double x) {
	const double Euler = exp(1.0);
	return pow(Euler, x);
}

//prototypes
void integral();
double trapez();
double simpson();
double simpsonThreeEight();
double boole();

int main() {
	integral();
  return 0;
}


double trapez() {
  double point = 2;
  double h = (interval[1] - interval[0]) / (point - 1);
  double x0 = interval[0];
  double x1 = x0 + h;
  double fx0 = function(x0);
  double fx1 = function(x1);
  double error = pow(h, 3)/12*function( (x1-x0 )/2 );
  return (h/point)*(fx0 + fx1) - error;

}

double simpson() {
  double point = 3;
  double h = (interval[1] - interval[0]) / (point - 1);
  double x0 = interval[0];
  double x1 = x0 + h;
  double x2 = x0 + 2*h;
  double fx0 = function(x0);
  double fx1 = function(x1);
  double fx2 = function(x2);
  double error = pow(h, 5)/90*function( (x2-x0 )/2 );
  return (h/point)*(fx0 + 4*fx1 + fx2) - error;
}

double simpsonThreeEight() {
  double point = 4;
  double h = (interval[1] - interval[0]) / (point - 1);
  double x0 = interval[0];
  double x1 = x0 + h;
  double x2 = x0 + 2*h;
  double x3 = x0 + 3*h;
  double fx0 = function(x0);
  double fx1 = function(x1);
  double fx2 = function(x2);
  double fx3 = function(x3);
  double error = 3*pow(h, 5)/80*function( (x3-x0 )/2 );
  return (3*h/(2*point)) *(fx0 + 3*fx1 + 3*fx2 + fx3) - error;
}

double boole() {
  double point = 5;
  double h = (interval[1] - interval[0]) / (point - 1);
  double x0 = interval[0];
  double x1 = x0 + h;
  double x2 = x0 + 2*h;
  double x3 = x0 + 3*h;
  double x4 = x0 + 4*h;
  double fx0 = function(x0);
  double fx1 = function(x1);
  double fx2 = function(x2);
  double fx3 = function(x3);
  double fx4 = function(x4);
  double error = 8*pow(h, 7)/945*function( (x4-x0 )/2 );
  return (2*h/(9*point)) *(fx0 + 32*fx1 + 12*fx2 + 32*fx3 + 7*fx4) - error;
}

void  integral() {
  printf("Trapezoidal: %lf\n", trapez());
  printf("Simpson: %lf\n", simpson());
  printf("Simpson3/8:  %lf\n", simpsonThreeEight());
  printf("Boole:  %lf\n", boole());
}
