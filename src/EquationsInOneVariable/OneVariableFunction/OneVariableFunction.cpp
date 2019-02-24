#include <iostream>
#include "OneVariableFunction.hpp"

OneVariableFunction::OneVariableFunction(double (*fn)(double)) {
  setFunction(fn);
}

OneVariableFunction::~OneVariableFunction() {
}

void OneVariableFunction::setFunction(double (*fn)(double)) {
  _func = *fn;
}

double OneVariableFunction::call(double arg) {
  return _func(arg);
}