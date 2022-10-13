#include <iostream>
using namespace std;

bool is_prime(int x) {
  if (x < 2) {
    // 0, 1 is not prime.
    return false;
  } else {
    // otherwise, test all i between 2 ~ x/2
    for (int i = 2; i < x / 2; ++i) {
      if (x % i == 0) {
        return false;
      }
    }
    return true;
  }
}

int main () {
  for (int n = 4; n <= 50; n += 2) {
    // n = lhs + rhs
    int lhs = 2;
    while (lhs <= n / 2) {
      if (is_prime(lhs) && is_prime(n - lhs)) {
        break;
      }
      lhs += 1;
    }
    if (lhs > n / 2) {
      cout << "Found " << n << "does not satisfy." << endl;
      return 0;
    }
    cout << n << " = " << lhs << " + " << n - lhs << endl;
  }
  return 0;
}