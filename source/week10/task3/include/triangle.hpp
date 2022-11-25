#pragma once

#include <cmath>
class Triangle {
private:
  // Edge length
  double a_, b_, c_;

public:
  Triangle(double a = 1, double b = 1, double c = 1) : a_(a), b_(b), c_(c) {}

  double GetArea() const {
    double p = .5 * (a_ + b_ + c_);
    return sqrt(p * (p - a_) * (p - b_) * (p - c_));
  }

  double operator+(const Triangle &rhs) const {
    return GetArea() + rhs.GetArea();
  }
  double operator-(const Triangle &rhs) const {
    return GetArea() - rhs.GetArea();
  }
};
