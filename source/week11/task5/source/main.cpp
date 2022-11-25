#include "student.hpp"

#include <iostream>

using namespace std;
int main() {
  Student stus[] = {
      Student(1, 'A', 0),  Student(3, 'A', 10), Student(2, 'B', 20),
      Student(4, 'C', 30), Student(5, 'A', 40),
  };

  for (int i = 0; i < 5; ++i) {
    stus[i].Print();
  }
  sort_students(stus, 5);
  for (int i = 0; i < 5; ++i) {
    stus[i].Print();
  }

  int id;
  char yw;
  double sx;
  std::cin >> id >> yw >> sx;
  Student stu(id, yw, sx);
  int position = search_students(stu, stus, 5);
  if (position < 5) {
    std::cout << "Found, order=" << position << std::endl;
  } else {
    std::cout << "Not Found..." << std::endl;
  }
  return 0;
}
