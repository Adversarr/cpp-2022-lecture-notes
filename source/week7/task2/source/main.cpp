#include <iostream>
using namespace std;

int highest(int n) {
  if (n < 10) {
    return n;
  } else {
    return highest(n / 10);
  }
}


bool check(int n) {
  if (n < 0) {
    n = -n;
  }
  int h = highest(n);
  int l = n % 10;
  return h = l;
}


int main() {
  int count = 0;
  for (int i = 0; i < 5; ++i) {
    int x;
    cin >> x;
    if (check(x)) {
      count += 1;
    }
  }
  cout << "Count = " << count << endl;
  return 0;
}