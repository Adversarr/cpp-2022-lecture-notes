
#include <algorithm>
#include <cstdlib>
#include <iostream>
class Student {
public:
  void Print();

  Student(int id, const char*, double math, double english, double physics);

  Student();

  double Avg() const;

  bool Query(const char *name) const;

  bool operator==(const Student &rhs) const;

  bool operator<(const Student &rhs) const;

  Student &operator=(const Student &rhs);

private:
  int id_;
  double math_;
  double english_;
  double physics_;

  char name_[16];
};

template <int maxsize = 20> class SeuClass {
private:
  Student students_[maxsize];

  int size_{0};

public:
  SeuClass(const Student *stu_array, int n) {
    size_ = n;
    for (int i = 0; i < n; ++i) {
      students_[i] = stu_array[i];
    }
  }

  double get_maxavg() const {
    double maxavg = 0;
    for (int i = 0; i < size_; ++i) {
      double avg = students_[i].Avg();

      if (avg > maxavg) {
        maxavg = avg;
      }
    }

    return maxavg;
  }

  void append(const Student &student) {
    size_ += 1;
    if (size_ == maxsize) {
      std::cerr << "Error: Array index out of range." << std::endl;
      exit(-1);
    }

    students_[size_ - 1] = student;
  }

  Student query(const char *name) const {
    for (int i = 0; i < size_; ++i) {
      if (students_[i].Query(name)) {
        return students_[i];
      }
    }
  }

  void sort() {
    // Assume you have already mastered how to implement a sorting algorithm
    // here. use c++ provided sort algorithm here.
    std::sort(students_, students_ + size_);
  }
};
