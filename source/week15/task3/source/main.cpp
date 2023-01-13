#include <iostream>
#define PI 3.14

class Shape {
public:
  virtual double Perimeter() const = 0;

  virtual double Area() const = 0;

  virtual double Volume() const = 0;

  virtual void Show() const = 0;
};

class Circle : public Shape {
public:
  Circle(double radius) : radius_(radius) {}

  double Perimeter() const final { return 2 * PI * radius_; }

  double Area() const final { return PI * radius_ * radius_; } 

  double Volume() const final { return 0; } 

  void Show() const final {
    std::cout << "Circle: radius = " << radius_ << std::endl;
  }

private:
  double radius_;
};

int main() {
  Circle c(10);
  std::cout << "Perimeter: " << c.Perimeter() << std::endl;
  std::cout << "     Area: " << c.Area() << std::endl;
  std::cout << "   Volume: " << c.Volume() << std::endl;
  c.Show();
  return 0;
}
