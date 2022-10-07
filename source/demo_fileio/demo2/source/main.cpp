#include <iostream>
#include <fstream>
using namespace std;

bool is_prime(int n) {
  if (n == 1) {
    return false;
  }

  for (int i = 2; i < n - 1; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}


int main () {
  // Declare an output file stream.
  ofstream output_file;

  // 1. Open the file： full path is recommended here.
  output_file.open(ASSET_DIR "/output_data.txt");

  // 2. Check the file is opend correctly:
  if (! output_file.is_open()) {
    // error: file is not opened.
    cout << "Cannot open file." << endl;
    // exit the program.
    return -1;
  }
  
  // 3. write the file, the operation is similar to cout.
  for (int i = 1; i < 100; ++i) {
    // Here, write the primes between [1, 100) to output_file.
    if (is_prime(i)) {
      output_file << i << endl;
    }
  }

  // 3. (Optional) Close the file.
  output_file.close();
  return 0;
}