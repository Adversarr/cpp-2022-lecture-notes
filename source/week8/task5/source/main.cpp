#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>

bool is_palindrome(int x) {
  x = std::abs(x);
  // `int` ranges from [-2^31, 2^31)
  int numbers[11];
  int len = 0;
  while(x > 0) {
    numbers[len] = x % 10;
    x /= 10;
    len += 1;
  }

  for (int i = 0; i < len / 2; ++i) {
    if (numbers[i] != numbers[len - 1 - i]) {
      return false;
    }
  }
  return true;
}

int main() {
  std::ofstream file{ASSET_DIR "/huiwen.txt"};

  if (! file.is_open()) {
    std::cout << "Error when open output file" << std::endl;
    std::exit(-1);
  }

  for (int i = 1000; i < 3000; ++i) {
    if (is_palindrome(i)) {
      file << i << std::endl;
    }
  }
  // Acturally, there is no need for closing the file. (See RAII in C++)
  // but closing the file explicitly is a good manner.
  file.close();
  return 0;
}
