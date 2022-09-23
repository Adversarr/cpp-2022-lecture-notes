#include <fstream>
#include <iostream>

char translate(char c) {
  if ('a' <= c && c <= 'z') {
    c += 19;
    // if you do not add condition `c < 0`, the overflow will
    // not be detected.
    if (c > 'z' || c < 0) {
      c -= 26;
    }
  } else if ('A' <= c && c <= 'Z') {
    c += 19;
    if (c > 'Z') {
      c -= 26;
    }
  } else if ('0' < c && c <= '9') {
    // same as (10 - (c - '0')) + '0' because:
    //  (10 - (c - '0)) + '0' = 10 + '0' + '0' - c = 2 * '5' - 0
    c = 2 * '5' - c;
  }
  return c;
}


int main() {
  std::ifstream file(ASSET_DIR "/info.txt");
  if (! file.good() && ! file.eof()) {
    std::cout << "Error when opening input file" << std::endl;
    std::exit(-1);
  }
  char c;
  while (!file.eof()) {
    file.get(c);
    std::cout << translate(c);
  }
  std::cout << std::endl;
  file.close();
  return 0;
}