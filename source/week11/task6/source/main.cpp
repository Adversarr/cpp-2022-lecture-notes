#include "mat.hpp"
#include <iostream>

int main() {
  double a_data[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  double b_data[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  Matrix a(a_data, 3, 4);
  Matrix b(b_data, 2, 4);

  a.Display();
  b.Display();
  b.Transpose();
  b.Display();
  Matrix c = a * b;
  c.Display();
  return 0;
}
