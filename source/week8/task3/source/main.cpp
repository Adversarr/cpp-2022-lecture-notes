#include <iostream>
#include <cmath>


/**
 * @brief calculate the number of numbers that meet the requirements.
 * the interval is [l, r)
 * only three divisors <==> divisor = (1, n, n^2), where n^2 is the required.
 * 
 * Therefore, only count how many square of numbers there are inside the interval except for 1.
 * @param l lower bound
 * @param r upper bound
 * @return int 
 */
int count_between(int l, int r) {
  int lb_root = std::ceil(std::sqrt(l));
  int rb_root = std::floor(std::sqrt(r));
  int result = rb_root - lb_root + 1;
  if (l == 1) {
    result -= 1;
  }
  if (rb_root * rb_root == r) {
    result -= 1;
  }
  return result;
}


int main() {
  // 4 meets the requirement
  std::cout << count_between(1, 9) << std::endl;
  // 4 meets the requirement
  std::cout << count_between(2, 9) << std::endl;
  // 4, 9 meet the requirement
  std::cout << count_between(2, 10) << std::endl;
  // 4, 9 meet the requirement
  std::cout << count_between(1, 16) << std::endl;
  // 100, 121, 144, 169, 196, 225, 256, 289 meet the requirement
  std::cout << count_between(100, 300) << std::endl;
  return 0;
}

