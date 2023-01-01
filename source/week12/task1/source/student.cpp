#include "student.hpp"
#include <iostream>

void Student::Print() {
  std::cout << "{id = " << id_ << ", name = '" << name_ << "', math = " << math_
            << ", english = " << english_ << ", physics = " << physics_ << "}";
}

template <typename... Args> decltype(auto) average(Args... args) {
  return (args + ...) / sizeof...(args);
}

Student::Student(int id, const char* name, double math, double english,
                 double physics)
    : id_(id), math_(math), english_(english), physics_(physics) {
  strcpy(name_, name);
}

bool Student::operator==(const Student &rhs) const {
  return id_ == rhs.id_ && strcmp(name_, rhs.name_) == 0;
}

bool Student::operator<(const Student &rhs) const {
  return average(math_, english_, physics_) <
         average(rhs.math_, rhs.english_, rhs.physics_);
}

Student &Student::operator=(const Student &rhs) {
  id_ = rhs.id_;
  strcpy(name_, rhs.name_);
  math_ = rhs.math_;
  english_ = rhs.english_;
  physics_ = rhs.physics_;
  return *this;
}

Student::Student() { memset(name_, 0, sizeof(char) * 16); }

bool Student::Query(const char *name) const { return strcmp(name_, name) == 0; }

double Student::Avg() const {
  return average(math_, english_, physics_);
}
