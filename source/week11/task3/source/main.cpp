// NOTE: This is the actual homework 1 of week 11.
#include <iostream>

using namespace std;
int main() {
  int arr[10];
  for (int i = 0; i < 9; ++i) {
    cin >> arr[i];
  }
  // Insert x into arr.
  int x;
  cin >> x;
  int position = 0;
  // Determine the position
  while (position < 9 && arr[position] < x) {
    ++position;
  }

  // Move [Position, 9) -> [Position + 1, 10)
  for (int i = 9; i > position; --i) {
    arr[i] = arr[i - 1];
  }

  // Do Insert:
  arr[position] = x;

  for (int i = 0; i < 10; ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << std::endl;

  return 0;
}
