#include <cmath>
#include <iostream>
#include <iomanip>

double newton(double x0, double err) {
  double dx = (x0 * x0 * x0 - 3 * x0 * x0 + x0 + 1) / (3 * x0 * x0 - 6 * x0 + 1);
  do {
    x0 -= dx;
    dx = (x0 * x0 * x0 - 3 * x0 * x0 + x0 + 1) / (3 * x0 * x0 - 6 * x0 + 1);
  } while (std::fabs(dx) > err);
  return x0;
}

int main() {
  std::cout << std::setw(13) << "Error Bound" << std::setw(10) << "Root" << std::endl;
  std::cout << std::setw(13) << 0.1 << std::setw(10) << newton(5, 0.1) << std::endl;
  std::cout << std::setw(13) << 0.01 << std::setw(10) << newton(5, 0.01) << std::endl;
  std::cout << std::setw(13) << 0.001 << std::setw(10) << newton(5, 0.001) << std::endl;
  std::cout << std::setw(13) << 0.0001 << std::setw(10) << newton(5, 0.0001) << std::endl;
  return 0;
}
