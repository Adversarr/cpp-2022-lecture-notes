#include <iostream>
using namespace std;

double legendre(double x, int n) {
  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return x;
  } else {
    return ((2 * n - 1) * x * legendre(x, n - 1) - (n - 1) * legendre(x, n - 2)) / n;
  }
}


int main () {
  cout << "P_4(1.5) = " << legendre(1.5, 4) << endl;
  return 0;
}
