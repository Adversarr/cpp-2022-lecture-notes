#include <iostream>
#include <fstream>
int main () {
  std::ofstream output_file(ASSET_DIR "/data.txt");
  if (! output_file.is_open()) {
    std::cout << "Error: file cannot open." << std::endl;
    return -1;
  }

  for (int i = 1; i < 1000; ++i) {
    int sum = 0;
    for (int j = 1; j < i; ++j) {
      if (i % j == 0) {
        sum += j;
      }
    }
    if (sum == i) {
      output_file << i << std::endl;
      std::cout << i << std::endl;
    }
  }
  output_file.close();
  return 0;
}