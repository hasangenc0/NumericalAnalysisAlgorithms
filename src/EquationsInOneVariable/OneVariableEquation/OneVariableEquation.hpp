#ifndef OneVariableEquation_hpp
#define OneVariableEquation_hpp

class OneVariableEquation
{

  public:
    OneVariableEquation();  //Constructor prototype
    ~OneVariableEquation(); //Destructor prototype
};

OneVariableEquation::OneVariableEquation() {
  std::cout << "OneVariableEquation started\n";
}

OneVariableEquation::~OneVariableEquation() {
  std::cout << "OneVariableEquation finished\n";
}

#endif /* OneVariableEquation_hpp */
