#include <fstream>
#include <iostream>
int main() {
  std::ifstream input_file(ASSET_DIR "/data.txt");
  if (! input_file.is_open()) {
    std::cout << "Error: file cannot open." << std::endl;
    return -1;
  }
  int sum = 0, n = 0;
  int negative = 0, positive = 0;
  while(! input_file.eof()) {
    int x;
    input_file >> x;
    if (! input_file.good()) {
      break;
    }
    n += 1;
    sum += x;
    if (x < 0) {
      negative += 1;
    } else if (x > 0) {
      positive += 1;
    }
  }
  std::cout << "Average: " << (double) sum / (double) n << std::endl;
  std::cout << "Positive: " << positive << std::endl;
  std::cout << "Negative: " << negative << std::endl;
  return 0;
}