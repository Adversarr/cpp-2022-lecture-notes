#include "fraction.hpp"

void exchange_fraction(Fraction &l, Fraction &r) {
  Fraction temp = l;
  l = r;
  r = temp;
}

int gcd(int a, int b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}
