#include <iostream>
using namespace std;

class Student {

public:
  Student(int id, char yw, double sx);
  Student();

  void Print();

  void Set(int id, char yuwen, double shuxue);

private:
  int id_;
  char yuwen_;
  double shuxue_;
};

void stu_exchange(Student &lhs, Student &rhs) {
  Student temporary = lhs;
  lhs = rhs;
  rhs = temporary;
}

int main(void) {
  Student stu1, stu2;
  exchange(stu1, stu2);
  return 0;
}

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
