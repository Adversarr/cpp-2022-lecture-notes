#include <iostream>

using namespace std;

#define TEST_CASE(e) cout << #e " = " << e << endl

int factor(int num, int k) {
  if (num == 0) {
    return 0;
  }

  if (num % k == 0) {
    return factor(num / k , k) + 1;
  } else {
    return 0;
  }
}


int main() {
  TEST_CASE(factor(2, 3));
  TEST_CASE(factor(3, 3));
  TEST_CASE(factor(0, 3));
  TEST_CASE(factor(18, 3));
  TEST_CASE(factor(27, 3));
  TEST_CASE(factor(48, 2));
  return 0;
}