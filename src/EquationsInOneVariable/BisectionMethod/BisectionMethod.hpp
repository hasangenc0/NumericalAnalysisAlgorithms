#ifndef BisectionMethod_hpp
#define BisectionMethod_hpp

class BisectionMethod
{
  public:
    BisectionMethod(int [2], int, double,OneVariableFunction*);    //Constructor prototype
    ~BisectionMethod();   //Destructor prototype
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

#endif /* BisectionMethod_hpp */
