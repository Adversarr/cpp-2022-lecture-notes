#include "student.hpp"
#include <iostream>

Student::Student(int id, char yw, double sx)
    : id_(id), yuwen_(yw), shuxue_(sx) {}

Student::Student() : id_(0), yuwen_('\0'), shuxue_(0.) {}

void Student::Print() {
  std::cout << "id=" << id_ << "\tyuwen=" << yuwen_ << "\tmath=" << shuxue_
            << std::endl;
}

void Student::Set(int id, char yuwen, double shuxue) {
  id_ = id;
  yuwen_ = yuwen;
  shuxue_ = shuxue;
}
void exchange_student(Student &lhs, Student &rhs) {
  Student temporary = lhs;
  lhs = rhs;
  rhs = temporary;
}

void sort_students(Student *arr, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (arr[i] < arr[j]) {
        exchange_student(arr[i], arr[j]);
      }
    }
  }
}

int search_students(const Student &stu, const Student *arr, int n) {
  int left = 0, right = n;
  int result = n;
  while (left <= right) {
    int mid = (left + right) / 2;

    if (arr[mid] == stu) {
      result = mid;
      break;
    } else if (arr[mid] < stu) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return result;
}
