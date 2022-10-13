#include <iostream>
#include <cmath>
using namespace std;

double update(double x) {
  return (x * x - 10 * (x * sin(x) + cos(x))) /
         (2 * x - 10 * sin(x));
}


int main() {
  double x0 = 1, x_new = 1;
  do {
    x0 = x_new;
    x_new = update(x0);
  } while(fabs(x0 - x_new) > 1e-5);
  cout << "Root = " << x0 << endl;
}