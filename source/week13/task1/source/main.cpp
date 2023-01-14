#include <iostream>
using namespace std;

template <typename T, int N> bool is_symm(T data[][N]) {

  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < i; ++j) {
      if (data[i][j] != data[j][i]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int integers[4][4] = {{1, 2, 3, 4}, {2, 1, 4, 3}, {3, 4, 1, 2}, {4, 3, 2, 1}};
  char characters[4][4] {{'a', 'b', 'c', 'd'}, {'b', 'a', 'b', 'c'}, {'c', 'b', 'a', 'b'}, {'d', 'c', 'b', 'a'}};

  std::cout << "Integers Symm? " << std::boolalpha << is_symm(integers) << std::endl;
  std::cout << "Characters Symm? " << std::boolalpha << is_symm(characters) << std::endl;
  return 0;
}
