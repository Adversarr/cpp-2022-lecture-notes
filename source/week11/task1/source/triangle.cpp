#include "triangle.hpp"

double operator+(const Triangle &lhs, const Triangle &rhs) {
  return lhs.GetArea() + rhs.GetArea();
}
double operator-(const Triangle &lhs, const Triangle &rhs) {
  return lhs.GetArea() - rhs.GetArea();
}
