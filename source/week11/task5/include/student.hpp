#pragma once

class Student {

public:
  Student(int id, char yw, double sx);
  Student();

  void Print();

  void Set(int id, char yuwen, double shuxue);

  bool operator<(const Student &rhs) const { return id_ < rhs.id_; }
  bool operator==(const Student &rhs) const {
    return id_ == rhs.id_ && yuwen_ == rhs.yuwen_ && shuxue_ == rhs.shuxue_;
  }

private:
  int id_;
  char yuwen_;
  double shuxue_;
};

void exchange_student(Student &lhs, Student &rhs);

void sort_students(Student *arr, int n);

int search_students(const Student &stu, const Student *arr, int n);
