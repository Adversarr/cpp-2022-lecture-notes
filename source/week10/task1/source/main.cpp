#include <iostream>

using namespace std;

class Point // 点类
{
private:
  int x_, y_; // 私有成员变量，坐标
public:
  Point() : x_(0), y_(0) {} // 无参数的构造方法，对xy初始化为0
  Point(int a, int b) : x_(a), y_(b) {}
  void setXY(int a, int b) {
    x_ = a;
    y_ = b;
  }
  int getX() const { return x_; }
  int getY() const { return y_; }
};

ostream &operator<<(ostream &os, const Point &p) {
  os << '(' << p.getX() << ',' << p.getY() << ')';
  return os;
}

class Rectangle // 矩形类
{
  /**
   *   1 --- 2
   *   |     |
   *   |     |
   *   3 --- 4
   *
   */
private:
  Point point1_, point2_, point3_, point4_;

public:
  Rectangle(); // 类Point的无参构造函数对每个对象做初始化，这里不用对每个点多初始化
  Rectangle(Point one, Point two)
      : point1_(one), point4_(two), point2_(two.getX(), one.getY()),
        point3_(one.getX(), two.getY()) {}
  Rectangle(int x1, int y1, int x2, int y2)
      : Rectangle(Point(x1, y1), Point(x2, y2)) {
  } // 使用x1,y1, 初始化左上点， x2,y2 初始化右下点
  void printPoint() {
    cout << "Left Top:" << point1_ << endl;
    cout << "Right Top:" << point2_ << endl;
    cout << "Left Bottom:" << point3_ << endl;
    cout << "Right Bottom:" << point4_ << endl;
  }             // 打印四个点的函数
  int getArea() // 计算面积的函数
  {
    return (point4_.getX() - point1_.getX()) *
           (point1_.getY() - point4_.getY());
  }
};
int main() {
  Point p1(-15, 56), p2(89, -10); // 定义两个点
  Point p3;
  Rectangle r1(p1, p2); // 用两个点做参数，声明一个矩形对象r1
  Rectangle r2(1, 5, 5, 1); // 用两队左边，声明一个矩形对象r2
  cout << "矩形r1的4个定点坐标：" << endl;
  r1.printPoint();
  cout << "矩形r1的面积：" << r1.getArea() << endl;
  cout << "\n矩形r2的4个定点坐标：" << endl;
  r2.printPoint();
  cout << "矩形r2的面积：" << r2.getArea() << endl;
}
