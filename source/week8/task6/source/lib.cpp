#include "lib.h"

double f(int x) {
  double value = 1;
  for (int n = 1; n < 12; ++n) {
    value += 1 / g(2 * n + 1, x);
  }
  return value;
}


double g(int m, int x) {
  return (double) ((1 + m) * m / 2) * x;
}
