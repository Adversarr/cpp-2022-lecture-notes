#include <cmath>
#include <iostream>
using namespace std;

template <typename T> class Integrate {
  double a, b, dx; // 积分区间、等分区间的步长 dx=(b-a)/n
  int n;           // 区间等分数
  double result;   // 积分结果
  T cf;            // 被积函数对象
public:
  Integrate(double aa = 0, double bb = 0,
            int nn = 100) // 初始化积分区间和区间等分数
  {
    a = aa;
    b = bb;
    n = nn;
    dx = ((double)(b - a)) / ((double)nn);
  }
  void putlimits(double aa, double bb, int nn) // 修改积分区间和等分数
  {
    a = aa;
    b = bb;
    n = nn;
    dx = ((double)(b - a)) / ((double)nn);
  }
  void integrate(); // 辛普森法计算积分
  void print() { cout << "result = " << result << endl; }
};

template <typename T> void Integrate<T>::integrate() {
  // 补充代码：辛普森法计算定积分
  T function;
  result = dx / 3 * (function(a) + function(b));
  for (int i = 1; i < n; ++i) {
    double value = function(a + i * dx);
    if (i % 2 == 0) {
      result += 4.0 / 3 * dx * value;
    } else {
      result += 2.0 / 3 * dx * value;
    }
  }
}

class F1 {
  // 补充代码：封装被积函数（cosx）
public:
  double operator()(double x) const { return std::cos(x); }
};

int main() {
  Integrate<F1> pf1(0.0, 3.1415926 / 2, 1000); // cosx在[0, pi/2]的定积分
  pf1.integrate();
  pf1.print();
  return 0;
}
