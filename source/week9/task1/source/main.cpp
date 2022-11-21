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

int main(void) {
  Student wang(61101, 'E', 86), li(61102, 'D', 82), zhang;
  zhang.Set(61103, 'A', 90);
  zhang.Print();
  wang.Print();
  li.Print();
  return 0;
}

Student::Student(int id, char yw, double sx)
    : id_(id), yuwen_(yw), shuxue_(sx) {}

Student::Student() : id_(0), yuwen_('\0'), shuxue_(0.) {}

void Student::Print() {
  std::cout << "id=" << id_ << "\tyuwen=" << yuwen_ << "\tmath=" << shuxue_
            << std::endl;
}

void Student::Set(int id, char yuwen, double shuxue){
  id_ = id;
  yuwen_ = yuwen;
  shuxue_ = shuxue;
}
