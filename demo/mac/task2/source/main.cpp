#include <iostream>
#include "utils.h"
int main()
{
  int a = 2;
  int b = 3;
  double x = 3.5;
  double y = 2.5;
  std ::cout << "The value of \""
                "float(a + b) / 2 + int(x) % int(y)"
                "\" is: "
             << (float(a + b) / 2 + int(x) % int(y)) << std ::endl;
  return 0;
}