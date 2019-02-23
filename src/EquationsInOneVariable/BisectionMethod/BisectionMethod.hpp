#ifndef BisectionMethod_hpp
#define BisectionMethod_hpp

class BisectionMethod
{
  public:
    BisectionMethod(int [2], int);    //Constructor prototype
    ~BisectionMethod();   //Destructor prototype
    void setRange (int [2]);
    void setIterateNumber (int);
    double findRoot ();
	private:
		int _range[2];
		int _iterateNumber;
};

#endif /* BisectionMethod_hpp */
