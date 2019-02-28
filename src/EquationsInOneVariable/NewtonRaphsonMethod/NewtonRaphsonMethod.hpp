#ifndef NewtonRaphsonMethod_hpp
#define NewtonRaphsonMethod_hpp

class NewtonRaphsonMethod
{
  public:
    NewtonRaphsonMethod(int [2], int, double,OneVariableFunction*, OneVariableFunction*);    //Constructor prototype
    ~NewtonRaphsonMethod();   //Destructor prototype
    void setRange (int [2]);
    void setIterateNumber (int);
    void setFunction (OneVariableFunction*);
    void setDiffFunction (OneVariableFunction*);
    double f (double);
    double findRoot ();
	private:
		int _range[2];
		int _iterateNumber;
    OneVariableFunction* _func;
    OneVariableFunction* _diff_func;
    double _TOL;
};

#endif /* NewtonRaphsonMethod_hpp */
