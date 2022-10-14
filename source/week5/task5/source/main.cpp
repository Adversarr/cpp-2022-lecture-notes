#include <iostream>
#include <cmath>

int main() {
  double pi = 0, sign = 1;
  int i = 1;
  while (fabs(sign / i) > 1e-7) {
    pi += sign / i;
    sign = - sign;
    i += 2;
  }
  std::cout << "Pi = " << pi * 4 << std::endl;
  return 0;
}