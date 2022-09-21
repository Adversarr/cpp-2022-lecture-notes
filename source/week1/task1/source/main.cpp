#include <iostream>
int main() {
  double x = 2.5;
  int a = 7;
  double y = 4.7;
  std ::cout << "The value of \""
                "x + a % 3 * (int)(x + y) % 2 / 4"
                "\" is: "
             << (x + a % 3 * (int)(x + y) % 2 / 4) << std ::endl;
  return 0;
}