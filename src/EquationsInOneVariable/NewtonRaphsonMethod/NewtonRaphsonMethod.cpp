#include <iostream>
#include <cmath>
#include "OneVariableFunction.hpp"
#include "NewtonRaphsonMethod.hpp"

NewtonRaphsonMethod::NewtonRaphsonMethod(int range[2], int iterateNumber, double tol,OneVariableFunction* func, OneVariableFunction* diffFunc) {
  setRange(range);
  setIterateNumber(iterateNumber);
	setFunction(func);
	setDiffFunction(diffFunc);
	_TOL = tol;
}

NewtonRaphsonMethod::~NewtonRaphsonMethod() {
}

// Setters
void NewtonRaphsonMethod::setRange(int range[2]) {
	_range[0] = range[0];
	_range[1] = range[1];
}

void NewtonRaphsonMethod::setIterateNumber (int iterateNumber) {
	_iterateNumber = iterateNumber;
}

void NewtonRaphsonMethod::setFunction (OneVariableFunction* func) {
	_func = func;
}

void NewtonRaphsonMethod::setDiffFunction (OneVariableFunction* func) {
	_diff_func = func;
}

// Main Methods
double NewtonRaphsonMethod::f (double arg) {
	return _func->call(arg);
}

double NewtonRaphsonMethod::findRoot() {
	// ranges
	double p0 = _range[0];

	double p;

	for(int i  = 0; i < _iterateNumber; i++) {
    p = p0 - (_func->call(p0)/_diff_func->call(p0));

		if(fabs(p - p0) < _TOL) {
			return p;
		}

		p0 = p;
	}
	std::cout<<"Method failed after "<<_iterateNumber<<" iterations.\n";
	return 0;
}