#pragma once
#include <iostream>
// NOTE: All the headers should have the line above
int gcd(int a, int b);

class Fraction {
private:
  // value = a / b
  int a_, b_;

  void simplify() {
    int g = gcd(a_, b_);
    a_ /= g;
    b_ /= g;
  }

public:
  // Constructor, also the default constructor(why?)
  Fraction(int a = 0, int b = 1) : a_(a), b_(b) {
    simplify();
    if (b_ == 0) {
      std::cout << "Error: b = 0" << std::endl;
      exit(-1);
    }
  }

  void display() { std::cout << a_ << "/" << b_; }

  // NOTE: rhs stands for Right Hand Side, i.e. lhs(this) + rhs
  Fraction operator+(const Fraction &rhs) const {
    return Fraction(a_ * rhs.b_ + b_ * rhs.a_, b_ * rhs.b_);
  }
  Fraction operator-(const Fraction &rhs) const {
    return Fraction(a_ * rhs.b_ - b_ * rhs.a_, b_ * rhs.b_);
  }
  Fraction operator/(const Fraction &rhs) const {
    return Fraction(a_ * rhs.b_, b_ * rhs.a_);
  }
  Fraction operator*(const Fraction &rhs) const {
    return Fraction(a_ * rhs.a_, b_ * rhs.b_);
  }
  bool operator==(const Fraction &rhs) const {
    return a_ * rhs.b_ == b_ * rhs.a_;
  }
  // NOTE: There is no need to impl a destructor.
  // ~Fraction();
};

// Why "&" ?
void exchange_fraction(Fraction &l, Fraction &y);
