#include <iostream>

using namespace std;

int main() {
  int arr[10];
  for (int i = 0; i < 10; ++i) {
    cin >> arr[i];
  }

  bool has_odd=false, has_even=false;
  int max_odd, max_even;
  for (int i = 0; i < 10; ++i) {
    if (arr[i] % 2 == 0) {
      if (!has_even) {
        max_even = arr[i];
      } else {
        max_even = max(max_even, arr[i]);
      }
      has_even = true;

    } else {
      if (!has_odd) {
        max_odd = arr[i];
      } else {
        max_odd = max(max_odd, arr[i]);
      }
      has_odd = true;
    }
  }

  if (has_odd) {
    cout << "Max odd is " << max_odd << endl;
  } else {
    cout << "No odd number in array." << endl;
  }
  if (has_even) {
    cout << "Max even is " << max_even << endl;
  } else {
    cout << "No even number in array." << endl;
  }
  return 0;
}
