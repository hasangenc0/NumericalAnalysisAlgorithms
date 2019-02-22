#ifndef FixedPointMethod_hpp
#define FixedPointMethod_hpp

class FixedPointMethod
{
  public:
    FixedPointMethod();    //Constructor prototype
    ~FixedPointMethod();   //Destructor prototype
    static double square (double);
};

FixedPointMethod::FixedPointMethod() {
  std::cout<<"FixedPointMethod started\n";
}

FixedPointMethod::~FixedPointMethod() {
  std::cout<<"FixedPointMethod finished\n";
}


double FixedPointMethod::square (double num) {
  return num*num;
}

#endif /* BisectionMethod_hpp */
