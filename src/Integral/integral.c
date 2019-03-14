/**
 * Hasan Genç
 */

#include <stdio.h>
#include <math.h> // for euler number

// integral is in the interval 0 - 4
const interval[2] = [0, 4];

// function that we will take the integral
double function(int x) {
	const double Euler = exp(1.0);
	return pow(Euler, x);
}

//prototypes
void integral();
void trapez();
void simpson();
void simpsonThreeEight();
void boole();

int main() {
	printf("%lf", function(2));
	return 0;
}


void trapez() {

}

void simpson() {

}

void simpsonThreeEight() {

}

void boole() {

}

void  integral() {

}
