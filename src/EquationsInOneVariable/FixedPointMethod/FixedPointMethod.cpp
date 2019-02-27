#include <iostream>
#include <cmath>
#include "OneVariableFunction.hpp"
#include "FixedPointMethod.hpp"

FixedPointMethod::FixedPointMethod(int range[2], int iterateNumber, double tol,OneVariableFunction* func) {
  setRange(range);
  setIterateNumber(iterateNumber);
	setFunction(func);
	_TOL = tol;
}

FixedPointMethod::~FixedPointMethod() {
}

// Setters
void FixedPointMethod::setRange(int range[2]) {
	_range[0] = range[0];
	_range[1] = range[1];
}

void FixedPointMethod::setIterateNumber (int iterateNumber) {
	_iterateNumber = iterateNumber;
}

void FixedPointMethod::setFunction (OneVariableFunction* func) {
	_func = func;
}

// Main Methods
double FixedPointMethod::f (double arg) {
	return _func->call(arg);
}

double FixedPointMethod::findRoot() {
	// ranges
	double p0 = _range[0];

	double p;

	for(int i = 0; i < _iterateNumber; i++) {
    p = _func->call(p0);

		if(fabs(p - p0) < _TOL) {
			return p;
		}

		p0 = p;
	}
	std::cout<<"Method failed after "<<_iterateNumber<<" iterations.\n";
	return 0;
}