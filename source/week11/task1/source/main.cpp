#include "triangle.hpp"
#include <iostream>

int main (int argc, char *argv[])
{
  Triangle t1(1, 1, 1), t2(3, 4, 5);
  std::cout << "[1, 1, 1]'s Area = " << t1.GetArea() << std::endl;
  std::cout << "[3, 4, 5]'s Area = " << t2.GetArea() << std::endl;
  std::cout << "t1 + t2 = " << (t1 + t2) << std::endl;
  std::cout << "t1 - t2 = " << (t1 - t2) << std::endl;
  return 0;
}
