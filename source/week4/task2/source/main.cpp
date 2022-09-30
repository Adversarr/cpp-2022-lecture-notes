#include <iostream>
#include <cmath>

int main() {
  double a, b, c;
  std::cout << "Solve quad-equation ax2 + bx + c = 0: ";
  std::cin >> a >> b >> c;
  if (fabs(a) < 1e-7) {
    std::cout << "Linear Equation. ";
    if (fabs(b) < 1e-7) {
      if (fabs(c) < 1e-7) {
        std::cout << "The eq has infinitely many solutions." << std::endl;
      } else {
        std::cout << "The eq had no solution." << std::endl;
      }
    }
  } else {
    std::cout << "Quadratic Equation." << std::endl;
    double delta = b * b - 4 * a * c;
    if (delta > 1e-7) {
      double x1 = (-b + sqrt(delta)) / (2 * a);
      double x2 = (-b - sqrt(delta)) / (2 * a);
      std::cout << "x1 = " << x1 << std::endl;
      std::cout << "x2 = " << x2 << std::endl;
    } else if (delta < - 1e-7) {
      double real_part = - b / (2 * a);
      double image_part = sqrt(-delta) / (2 * a);
      std::cout << "x1 = " << real_part << " + " << image_part << " i" << std::endl;
      std::cout << "x1 = " << real_part << " - " << image_part << " i" << std::endl;
    } else {
      std::cout << "x1 = x2 = " << - b / (2 * a) << std::endl;
    }
  }
  return 0;
}