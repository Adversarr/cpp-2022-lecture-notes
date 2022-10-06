#include <iostream>
int main() {
  double pi = 0, sign = 1;
  for (int i = 1; i < 100000; i += 2) {
    pi += sign / i;
    sign = - sign;
  }
  std::cout << "Pi = " << pi * 4 << std::endl;
  return 0;
}