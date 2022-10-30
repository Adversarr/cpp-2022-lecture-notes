#include <iostream>

#define CHECK(expr)                                                 \
  do {                                                                         \
    auto result = (expr);                                                      \
    std::cout << "  " #expr ": " << typeid(result).name() << " = " << (result)      \
              << std::endl;                                                    \
  } while (false)
#define ENV                                                                    \
  int a = 3, b = 5, c = 0;                                                     \
  float x = 2.5, y = 8.2, z = 1.4;                                             \
  char ch1 = 'a', ch2 = '5', ch3 = '0', ch4



void case1() {
  ENV;
  CHECK(x + (int)y % a);
  CHECK(x); CHECK(y); CHECK(a);
}

void case2() {
  ENV;
  CHECK((x = z * b++, b = b * x, b++));

  CHECK(x); CHECK(z); CHECK(b);
}

void case3() {
  ENV;
  CHECK((ch4 = ch3 - ch2 + ch1));
  CHECK(ch4); CHECK(ch3); CHECK(ch2); CHECK(ch1);
}

void case4() {
  ENV;
  CHECK(int(y / z) + (int)y / (int)z);
}

void case5() {
  ENV;
  CHECK(!(a > b) && c && (x *= y) && b++);
  CHECK(x); CHECK(b);
}

void case6() {
  ENV;
  CHECK(ch3 || (b += a * c) || c++);
  CHECK(b); CHECK(c);
}

void case7() {
  ENV;
  CHECK(z = (a << 2) / (b >> 1));
}

int main() { 
  int x = 1;
  std::cout << "case 1:" << std::endl; case1();
  std::cout << "case 2:" << std::endl; case2();
  std::cout << "case 3:" << std::endl; case3();
  std::cout << "case 4:" << std::endl; case4();
  std::cout << "case 5:" << std::endl; case5();
  std::cout << "case 6:" << std::endl; case6();
  std::cout << "case 7:" << std::endl; case7();

  return 0;
}
