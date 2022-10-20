#include <iostream>
#include <cmath>
using namespace std;

int gcd(int m, int n) {
  if (m == 0 || n == 0) {
    return 0;
  } else if (m % n == 0) {
    return n;
  } else {
    return gcd(n, m % n);
  }
}


int main () {
  double x;
  cin >> x;
  int d = x, n = 1;
  while (fabs(x * n - d) > 1e-5) {
    n *= 10;
    d = x * n;
  }

  int g = gcd(d, n);
  if (g != 0) {
    d /= g;
    n /= g;
  }

  cout << d << "/" << n << endl;
  return 0;
}