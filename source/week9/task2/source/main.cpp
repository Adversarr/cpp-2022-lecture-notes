#include <iostream>
using namespace std;

class Rectangle {
  /*
   * (x1, y1) -------*
   *  |              |
   *  |  Rectangle   |
   *  |              |
   *  *-------------(x2, y2)
   */

public:
  Rectangle();
  Rectangle(int x1, int y1, int x2, int y2);

  void Show();

  void Set(int x1, int y1, int x2, int y2);

  int Area() const;

  int Perimeter() const;

private:
  int x1_, y1_, x2_, y2_;
};

int main() {
  Rectangle rect;
  rect.Show();
  rect.Set(100, 400, 300, 200);
  rect.Show();
  Rectangle rect1(0, 200, 200, 0);
  rect1.Show();
  cout << "面积" << rect.Area() << '\t' << "周长" << rect.Perimeter() << endl;
  return 0;
}
void Rectangle::Show() {
  cout << "Rect[(" << x1_ << ", " << y1_ << "), (" << x2_ << ", " << y2_ << ")]"
       << endl;
}

Rectangle::Rectangle() : x1_(0), y1_(0), x2_(0), y2_(0) {}

Rectangle::Rectangle(int x1, int y1, int x2, int y2)
    : x1_(x1), y1_(y1), x2_(x2), y2_(y2) {}

int Rectangle::Area() const {
  int area = (x1_ - x2_) * (y1_ - y2_);
  return (area < 0) ? -area : area;
}

int Rectangle::Perimeter() const {
  return 2 * (abs(x1_ - x2_) + abs(y1_ - y2_));
}

void Rectangle::Set(int x1, int y1, int x2, int y2) {
  x1_ = x1;
  y1_ = y1;
  x2_ = x2;
  y2_ = y2;
}
