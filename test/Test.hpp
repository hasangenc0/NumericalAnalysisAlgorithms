#ifndef Test_hpp
#define Test_hpp

namespace myTest {

  class Test {
    public:
      bool succeed;
      bool isBetween(double val, double r1, double r2) {
        double begin = r1 > r2 ? r1 : r2;
        double end = r1 > r2 ? r2 : r1;
        return begin < val || end > val;
      }

  };

}

#endif /* Test_hpp */
