#include <iostream>

int main() {
  int n, base = 10;
  // Uncomment following lines for the extra requirement.
  // std::cout << "Input the base (2-10): ";
  // std::cin >> base;
  std::cout << "Input num: ";
  std::cin >> n;
  if (n < 0) {
    // negative numbers should be converted to its absolute value.
    // e.g. (-10) % 3 == -1
    n = -n;
  }

  int count = 0;
  int sum = 0;
  std::cout << "Invert: ";
  if (n == 0) {
    // for zero, 0 should be printed once.
    std::cout << 0;
    count = 1;
  }
  while (n != 0) {
    int last = n % base;
    std::cout << last;
    count += 1;
    sum += last;
    n /= base;
  }
  std::cout << std::endl;
  std::cout << "Count :" << count << std::endl;
  std::cout << "Sum   :" << sum << std::endl;
  return 0;
}