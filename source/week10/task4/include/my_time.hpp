#pragma once

#include <iostream>
class MyTime {
private:
  // hour, minute, second
  int h_, m_, s_;

  void fix_sec() {
    if (s_ >= 60) {
      m_ += s_ / 60;
      s_ = s_ % 60;
    } else if (s_ < 0) {
      m_ = m_ + (s_ / 60) - 1;
      s_ += (-(s_ / 60) + 1) * 60;
    }
  }
  void fix_min() {
    if (m_ >= 60) {
      h_ += s_ / 60;
      m_ = m_ % 60;
    } else if (m_ < 0) {
      h_ = h_ + (m_ / 60) - 1;
      m_ += (-(m_ / 60) + 1) * 60;
    }
  }

  void fix() {
    fix_sec();
    fix_min();
  }

public:
  MyTime(int h, int m, int s) : h_(h), m_(m), s_(s) {}

  void Display() { std::cout << h_ << ":" << m_ << ":" << s_; }

  MyTime &operator--() {
    s_--;
    fix();
    return *this;
  }
  MyTime operator--(int) {
    MyTime ret = *this;
    s_--;
    fix();
    return ret;
  }
};
