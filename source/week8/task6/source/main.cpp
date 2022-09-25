#include "lib.h"
#include <iostream>

int main() {
  int x;
  std::cout << "Input x:";
  std::cin >> x;
  if (x == 0) {
    std::cerr << "Error x == 0" << std::endl;
  }

  std::cout << "f(" << x << ") = " << f(x) << "(n = 12)" << std::endl;
  return 0;
}
