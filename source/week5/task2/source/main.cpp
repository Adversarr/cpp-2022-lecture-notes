#include <iostream>
#include <fstream>
#include <iomanip>
int main () {
  std::ofstream output_file(ASSET_DIR "/data.txt");
  if (! output_file.is_open()) {
    std::cout << "Error: file cannot open." << std::endl;
    return -1;
  }

  int count = 0;
  for (int n_10 = 0; n_10 <= 100 / 10; n_10 ++) {
    for (int n_5 = 0; n_5 <= (100 - n_10) / 5; n_5 ++) {
      int n_1 = 100 - n_10 * 10 + n_5 * 5;
      std::cout << std::setw(5) << n_10 << std::setw(5) << n_5 << std::setw(5) << n_1 << std::endl;
      output_file << std::setw(5) << n_10 << std::setw(5) << n_5 << std::setw(5) << n_1 << std::endl;
    }
  }
  output_file.close();
  return 0;
}