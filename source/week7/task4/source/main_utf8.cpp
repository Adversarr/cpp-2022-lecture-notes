#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
/**
 * Newton for f(x) = x^2 - N:
      x[n+1] = x[n] - f(x[n]) / f'(x[n]);
 * Then:
 *    step(x) = x - (x^2 - N) / (2 * x) = 0.5 * (x + N / x)
 */

void print_to_stream(std::ostream &stream, int number, int n, double value,
                     int count) {
  stream << std::setw(8) << number;
  stream << std::setw(8) << n;
  stream << std::setw(10) << std::setprecision(4) << value;
  stream << std::setw(8) << count;
  stream << std::endl;
}

void print_iteration(std::ostream &stream, int n, double value, int count) {
  static int number = 0;
  number += 1;
  print_to_stream(std::cout, number, n, value, count);
  print_to_stream(stream, number, n, value, count);
}

void print_init(std::ostream &stream) {
  // Notice: this file is encoded with utf-8, add /utf-8 compile option
  // if you are using MSVC.
  stream << std::setw(10) << "序号";
  stream << std::setw(11) << "正整数";
  stream << std::setw(13) << "平方根";
  stream << std::setw(13) << "迭代次数";
  stream << std::endl;
}

double delta(double x, double n) { return 0.5 * (-x + n / x); }

void roots(double epsilon, std::ostream &output) {
  print_init(std::cout);
  print_init(output);
  for (int i = 0; i < 10; ++i) {
    if (i == 0) {
      // avoid divide by zero.
      print_iteration(output, i, 0, 1);
    } else {
      int count = 0;
      double n = i;
      double x = n;
      double dx = 0;
      do {
        dx = delta(x, n);
        print_iteration(output, i, x, count);
        x += dx;
      } while (std::abs(dx) > epsilon);
    }
  }
}

int main() {
  std::ofstream file(ASSET_DIR "/output.txt");

  if (! file.is_open()) {
    std::cout << "Error when open output file" << std::endl;
    std::exit(-1);
  }
  roots(0.001, file);

  file.close();
  return 0;
}
