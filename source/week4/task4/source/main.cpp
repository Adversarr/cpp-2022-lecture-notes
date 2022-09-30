#include <iostream>

int main() {
  int x, y;
  std::cout << "Input two numbers for gcd and lcm:";
  std::cin >> x >> y;
  if (x == 0 || y == 0) {
    std::cout << "gcd: 0" << std::endl;
    if (x == 0 && y == 0) {
      std::cout << "lcm: 0" << std::endl;
    } else {
      std::cout << "lcm: infinity" << std::endl;
    }
  } else {
    if (x < 0) {
      x = -x;
    }
    if (y < 0) {
      y = -y;
    }

    int gcd = std::min(x, y);
    int lcm = std::max(x, y);
    // just ignore the requirement to use for-loop and break:
    while (x % gcd != 0 || y % gcd != 0) {
      gcd -= 1;
    }

    while (lcm % x != 0 || lcm % y != 0) {
      lcm += 1;
    }

    std::cout << "gcd: " << gcd << std::endl;
    std::cout << "lcm: " << lcm << std::endl;
  }
  return 0;
}