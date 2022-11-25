#include "my_time.hpp"

int main() {
  MyTime t(1, 2, 3);
  t.Display(); std::cout << std::endl;
  MyTime t1 = t--;
  t.Display(); std::cout << std::endl;
  t1.Display(); std::cout << std::endl;
  MyTime t2 = --t;
  t.Display(); std::cout << std::endl;
  t2.Display(); std::cout << std::endl;
  --t; --t; --t; --t;
  t.Display(); std::cout << std::endl;
  return 0;
}
