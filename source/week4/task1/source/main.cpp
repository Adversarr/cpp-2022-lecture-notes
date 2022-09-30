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
  if (income < 1000) {
    ratio = .02;
  } else if (income < 2000) {
    ratio = .03;
  } else if (income < 5000) {
    ratio = .04;
  } else if (income < 10000) {
    ratio = .05;
  } else {
    ratio = .06;
  }

  std::cout << "Fund: " << ratio * income << std::endl;
  return 0;
}