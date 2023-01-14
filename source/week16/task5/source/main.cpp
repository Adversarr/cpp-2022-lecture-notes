#include <cmath>
#include <iostream>
using namespace std;

class Newton {
  double epsilon, result;

public:
  virtual double fun(double x) = 0; //  ！！！！注意这里函数声明为纯虚函数
  Newton(double ep = 0.00001) {
    //补充构造函数
    epsilon = ep;
    result = 0;
  }
  void root() {
    //补充函数求根，利用说明中的递推函数，调用fun，按照精度要求把结果存入result

    double x = 1.0;
    double current_ep = 2 * epsilon;
    while (current_ep > epsilon) {
      double delta = fun(x) / grad(x);
      current_ep = fabs(delta);
      x -= delta;
    }
    result = x;
  }
  //补充其他必要函数
  virtual double grad(double x) = 0;

  void Print() const {
    std::cout << "Root is " << result << std::endl;
  }
};

class Myroot : public Newton {
  double n_;

public:
  Myroot(double ra) : Newton(ra){};
  double fun(double x) final { return x * x - n_; }
  double grad(double x) final { return 2 * x;}

  void SetN(double n) { n_ = n; }
  //补充其他必要函数
};

int main() {
  Myroot a1(0.0000001);
  a1.SetN(10);
  Newton *s = &a1;
  s->root();
  s->Print();
  return 0;
}
