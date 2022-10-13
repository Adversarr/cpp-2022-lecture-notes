#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

constexpr size_t N = 100;

int main () {
  ofstream output_file(ASSET_DIR "/data.txt");
  if (! output_file.is_open()) {
    cout << "Error: Cannot Open File." << endl;
    return -1;
  }

  int a[N];
  for (int i = 0; i < N; ++i) {
    a[i] = 1 + i;
  }
  a[0] = 0;

  for (int i = 0; i < N; ++i) {
    if (a[i] == 0) {
      continue;
    }

    for (int j = i + 1; j < N; ++j) {
      if (a[j] % a[i] == 0) {
        a[j] = 0;
      }
    }
  }
  int count = 0;
  output_file << "between 1 ~ " << N << ", primes are:" << endl;
  for (int i = 0; i < N; ++i) {
    if (a[i] != 0) {
      output_file << setw(6) << a[i];
      count += 1;
      if (count % 10 == 0) {
        output_file << endl;
      }
    }
  }
  output_file << endl;
  output_file.close(); // optional.
  return 0;
}