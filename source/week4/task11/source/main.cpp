#include <iostream>

int main() {
  int income;
  std::cout << "Input your income: ";
  std::cin >> income;
  if (income < 0) {
    std::cout << "You cannot have negative income." << std::endl;
    exit(-1);
  }
  double ratio;

  switch (income / 1000) {
  case 0:
    ratio = .02;
    break;
  case 1:
    ratio = .03;
    break;
  case 2:
  case 3:
  case 4:
    ratio = .04;
    break;
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
    ratio = .05;
    break;
  default:
    ratio = .06;
  }

  std::cout << "Fund: " << ratio * income << std::endl;
  return 0;
}