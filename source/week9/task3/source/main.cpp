#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

class Fraction {
  int above_; // 分子
  int below_; // 分母
  void reduction() {
    int d = gcd(abs(above_), abs(below_));
    above_ = above_ / d;
    below_ = below_ / d;
  }

public:
  Fraction(int above = 0, int below = 1) : above_(above), below_(below) {}

private:
  Fraction makecommond(const Fraction &b) const {
    return Fraction(above_ * b.below_, below_ * b.below_);
  }

public:
  Fraction Add(const Fraction &another) const {
    Fraction c_this = makecommond(another);
    Fraction c_another = another.makecommond(*this);
    Fraction result(c_this.above_ + c_another.above_, c_this.below_);
    result.reduction();
    return result;
  }

  Fraction Sub(const Fraction &another) const {
    Fraction c_this = makecommond(another);
    Fraction c_another = another.makecommond(*this);
    Fraction result(c_this.above_ - c_another.above_, c_this.below_);
    result.reduction();
    return result;
  }

  void Display() { cout << above_ << '/' << below_ << endl; }

  void Input() {
    cin >> above_ >> below_;
    // TODO: check below != 0
  }

  bool Equal(const Fraction &another) const {
    return above_ * another.below_ == below_ * another.above_;
  }
};

int main() {
  Fraction a(1, 2), b(5, 15), c;
  a.Display();
  b.Display();

  c = a.Add(b);
  c.Display();

  c = b.Sub(a);
  c.Display();

  if (a.Equal(b))
    cout << "相等";
  else
    cout << "不等";
  return 0;
}
