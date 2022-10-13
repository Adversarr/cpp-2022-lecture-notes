#include <iostream>
using namespace std;

double g(int m, double x) {
  return (1 + m) * m * .5 * x;
}

double f(double x) {
  double sum = 1.0;
  for (int i = 1; i <= 12; ++i) {
    sum += 1 / g(i * 2 + 1, x);
  }
  return sum;
}

int main () {
  double x;
  cout << "Input x:";
  cin >> x;
  if (x > 1 || x < -1) {
    cout << "Error Input." << endl;
    return -1;
  }

  cout << "f(" << x << ") = " << f(x) << ", (n = 12)" << endl;
  return 0;
}