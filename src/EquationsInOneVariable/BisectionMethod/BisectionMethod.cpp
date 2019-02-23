#include <iostream>
#include "BisectionMethod.hpp"

BisectionMethod::BisectionMethod(int range[2], int iterateNumber) {
  std::cout<<"BisectionMethod started\n";
  setRange(range);
  setIterateNumber(iterateNumber);
}

BisectionMethod::~BisectionMethod() {
  std::cout<<"BisectionMethod finished\n";
}

// Setters
void BisectionMethod::setRange(int range[2]) {
	_range[0] = range[0];
	_range[1] = range[1];
}

void BisectionMethod::setIterateNumber (int iterateNumber) {
	_iterateNumber = iterateNumber;
}

// Main Methods
double BisectionMethod::findRoot() {
	std::cout<<_range[0]<<" - "<<_range[1]<<std::endl; 
	// ranges
	int r1 = _range[0];
	int r2 = _range[1];
	// middle point of range
	double mid = (double)std::abs(r1 - r2)/2;

	for(int i = 0; i < _iterateNumber; i++) {
		std::cout<<i<<std::endl;
	}

	return 10;
}