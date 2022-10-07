#include <iostream>
#include <fstream>
using namespace std;

int main () {
  // Declare a input file stream.
  ifstream input_file;

  // 1. Open the file： full path is recommended here.
  input_file.open(ASSET_DIR "/input_data.txt");

  // 2. Check the file is opend correctly:
  if (! input_file.is_open()) {
    // error: file is not opened.
    cout << "Cannot open file." << endl;
    // exit the program.
    return -1;
  }
  // 3. Read the file, until End Of File (eof)
  while (! input_file.eof()) {
    char c;

    // Get one char from file.
    input_file.get(c);
    // If the operation failed, break the loop.
    if (! input_file.good()) {
      break;
    }
    
    // else print the char c in console.
    cout << c;
  }

  // 3. (Optional) Close the file.
  input_file.close();
  return 0;
}