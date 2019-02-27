#ifndef FixedPointMethod_hpp
#define FixedPointMethod_hpp

class FixedPointMethod
{
  public:
    FixedPointMethod(int [2], int, double,OneVariableFunction*);    //Constructor prototype
    ~FixedPointMethod();   //Destructor prototype
    void setRange (int [2]);
    void setIterateNumber (int);
    void setFunction (OneVariableFunction*);
    double f (double);
    double findRoot ();
	private:
		int _range[2];
		int _iterateNumber;
    OneVariableFunction* _func;
    double _TOL;
};

#endif /* FixedPointMethod_hpp */
