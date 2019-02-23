#include <iostream>
#include "OneVariableFunction.hpp"

OneVariableFunction::OneVariableFunction(double (*fn)(double)) {
  std::cout << "OneVariableFunction started\n";
  setFunction(fn);
}

OneVariableFunction::~OneVariableFunction() {
  std::cout << "OneVariableFunction finished\n";
}

void OneVariableFunction::setFunction(double (*fn)(double)) {
  _func = *fn;
}

double OneVariableFunction::call(double arg) {
  return _func(arg);
}