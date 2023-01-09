#include <iostream>

using namespace std;

class Student {

private:
  int score_;

public:
  Student(int score = 0) : score_(score) {}

  void SetScore(int score) { score_ = score; }

  int GetScore() const { return score_; }

  bool operator<(const Student &r) const { return score_ < r.score_; }
};

std::ostream &operator<<(std::ostream &os, const Student &student) {
  os << "Student[" << student.GetScore() << "] ";
  return os;
}

template <typename T> void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T> void insertion_sort(T *data, int n) {
  for (int i = 1; i < n; ++i) {
    for (int j = i; j > 0; --j) {
      if (data[j] < data[j - 1]) {
        ::swap(data[j], data[j - 1]);
      } else {
        break;
      }
    }
  }
}

template <typename T> void bubble_sort(T *data, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n - 1; ++j) {
      if (data[j + 1] < data[j]) {
        ::swap(data[j], data[j + 1]);
      }
    }
  }
}

int main() {
  Student stu_array[5];
  std::cout << "Before sort:" << std::endl;
  for (int i = 0; i < 5; ++i) {
    stu_array[i].SetScore(5 - i);
    cout << stu_array[i] << endl;
  }

  std::cout << "After sort:" << std::endl;
  bubble_sort(stu_array, 5);
  // insertion_sort(stu_array, 5);
  for (int i = 0; i < 5; ++i) {
    cout << stu_array[i] << endl;
  }
  return 0;
}
