#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool is_neg = n < 0;
  n = abs(n);

  char nstr[10];
  int total = 0;
  while (n > 0) {
    int hex = n % 16;
    if (hex >= 10) {
      nstr[total] = hex - 10 + 'A';
    } else {
      nstr[total] = hex + '0';
    }
    total += 1;
    n /= 16;
  }
  for (int j = 0; j < total / 2; ++j) {
    char t = nstr[total - 1 - j];
    nstr[total - 1 - j] = nstr[j];
    nstr[j] = t;
  }
  nstr[total] = '\0';
  if (is_neg) {
    std::cout << '-';
  }
  cout << nstr << endl;
  return 0;
}
