#include <iostream>

int main () {
  int num = 1;
  for (int day = 2; day <= 9; ++day) {
    num = (num + 1) * 2;
  }
  std::cout << num << std::endl;
  return 0;
}