#ifndef BisectionMethod_hpp
#define BisectionMethod_hpp

class BisectionMethod
{
  public:
    BisectionMethod();    //Constructor prototype
    ~BisectionMethod();   //Destructor prototype
    static double square (double);
};

BisectionMethod::BisectionMethod() {
  std::cout<<"BisectionMethod started\n";
}

BisectionMethod::~BisectionMethod() {
  std::cout<<"BisectionMethod finished\n";
}


double BisectionMethod::square (double num) {
  return num*num;
}

#endif /* BisectionMethod_hpp */
