#include <iostream>
#include <cmath>
#include "OneVariableFunction.hpp"
#include "BisectionMethod.hpp"

BisectionMethod::BisectionMethod(int range[2], int iterateNumber, double tol,OneVariableFunction* func) {
  setRange(range);
  setIterateNumber(iterateNumber);
	setFunction(func);
	_TOL = tol;
}

BisectionMethod::~BisectionMethod() {
}

// Setters
void BisectionMethod::setRange(int range[2]) {
	_range[0] = range[0];
	_range[1] = range[1];
}

void BisectionMethod::setIterateNumber (int iterateNumber) {
	_iterateNumber = iterateNumber;
}

void BisectionMethod::setFunction (OneVariableFunction* func) {
	_func = func;
}

// Main Methods
double BisectionMethod::f (double arg) {
	return _func->call(arg);
}

double BisectionMethod::findRoot() {
	// ranges
	double r1 = _range[0];
	double r2 = _range[1];

	double fr1 = _func->call(r1);
	double fmid;

	// middle point of range
	double mid;

	for(int i = 0; i < _iterateNumber; i++) {
		mid = (r1 + r2)/2;
		fmid = _func->call(mid);
		if(fmid == 0 || fabs(r2 -r1)/2 < _TOL) {
			return mid;
		}

		if(fr1*fmid > 0) {
			r1 = mid;
		} else {
			r2 = mid;
		}

	}
	std::cout<<"Method failed after "<<_iterateNumber<<" iterations.\n";
	return 0;
}