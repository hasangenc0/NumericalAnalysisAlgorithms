#ifndef OneVariableFunction_hpp
#define OneVariableFunction_hpp

class OneVariableFunction
{

  public:
    OneVariableFunction(double (*fn)(double));  //Constructor prototype
    ~OneVariableFunction(); //Destructor prototype
    void setFunction(double (*fn)(double));
    double call(double);
  private:
    double (*_func)(double);
};

#endif /* OneVariableFunction_hpp */