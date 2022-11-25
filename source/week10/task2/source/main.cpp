#include "fraction.hpp"

int main() {
  Fraction a(1, 2), b(5, 15), c;
  a.display();
  std::cout << std::endl;
  b.display();
  std::cout << std::endl;
  c = a + b;
  c.display();
  std::cout << std::endl;
  c = b - a;
  c.display();
  std::cout << std::endl;
  Fraction f1(10, 30);
  std::cout << "b == f1: " << std::boolalpha << (b == f1) << std::endl;
  std::cout << "After Exchange a, b: " << std::endl;
  exchange_fraction(a, b);
  a.display();
  std::cout << std::endl;
  b.display();
  std::cout << std::endl;
  return 0;
}
