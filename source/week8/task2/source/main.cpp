#include <iostream>
#include <cmath>
#include <cstdlib>
/**
 * @brief Calculate the GCD of x, y
 * 
 * @param x 
 * @param y 
 * @return int 
 */
int gcd(int x, int y) {
  if (x == 0 || y == 0) {
    // if one of x or y equals to zero, the result is zero.
    // (avoid divide-by-zero)
    return 0;
  } else {
    // make sure x, y > 0. the result of % may become confusing 
    // if you use negative numbers.
    x = std::abs(x);
    y = std::abs(y);
    // Euclid Algorithm, explanation is available at:
    // https://oi-wiki.org/math/number-theory/gcd/
    while (x % y != 0) {
      x = x % y;
      std::swap(x, y);
    }
    return y;
  }
}

/**
 * @brief Reduce the frac $n/d$ inplace.
 * 
 * @param n numerator
 * @param d dominator
 */
void frac_reduce(int& n, int& d) {
  if (n == 0) {
    d = 1;
  } else if (d == 0) {
    std::cerr << "Error frac" << n << "/" << d << std::endl;
    std::exit(-1);
  } else {
    int g = gcd(n, d);
    n /= g;
    d /= g;
  }
}

/**
 * @brief a, b stand for two fracs, perform c = a + b.
 *
 *  n standfor numerator.
 *  d standfor dominator.
 */
void frac_plus(int a_n, int a_d, int b_n, int b_d, int& c_n, int& c_d) {
  int g = gcd(a_d, b_d);
  a_n *= g;
  a_d *= g;
  b_n *= g;
  b_d *= g;
  c_n = a_n + b_n;
  c_d = a_d;
  frac_reduce(c_n, c_d);
}

void frac_minus(int a_n, int a_d, int b_n, int b_d, int &c_n, int &c_d) {
  c_n = a_n * b_d - b_n * a_d;
  c_d = a_d * b_d;
  frac_reduce(c_n, c_d);
}

void frac_times(int a_n, int a_d, int b_n, int b_d, int &c_n, int &c_d) {
  c_n = a_n * b_n;
  c_d = a_d * b_d;
  frac_reduce(c_n, c_d);
}

void frac_divide(int a_n, int a_d, int b_n, int b_d, int &c_n, int &c_d) {
  c_n = a_n * b_d;
  c_d = a_d * b_n;
  frac_reduce(c_n, c_d);
}

void frac_print(int n, int d) {
  std::cout << n << "/" << d;
}

void frac_input(int& n, int& d) {
  std::cout << "Input the numerator and the dominator: ";
  std::cin >> n >> d;
  if (d == 0) {
    // Invalid frac with d == 0
    std::cout << "d = 0" << std::endl;
    std::exit(-1);
  }
}


int main() {
  int a1 = 0, a2 = 1;
  int b1 = 0, b2 = 1;
  int c1 = 0, c2 = 1;

  frac_input(a1, a2);
  frac_input(b1, b2);

  // c = a + b;
  frac_plus(a1, a2, b1, b2, c1, c2);
  frac_print(a1, a2);
  std::cout << " + ";
  frac_print(b1, b2);
  std::cout << " = ";
  frac_print(c1, c2);
  std::cout << std::endl;

  // c = a - b;
  frac_minus(a1, a2, b1, b2, c1, c2);
  frac_print(a1, a2);
  std::cout << " - ";
  frac_print(b1, b2);
  std::cout << " = ";
  frac_print(c1, c2);
  std::cout << std::endl;
  return 0;
}