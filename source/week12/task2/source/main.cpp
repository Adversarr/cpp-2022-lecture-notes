#include <cassert>
#include <iomanip>
#include <iostream>

using namespace std;

#define MAXN 20

class Matrix {
private:
  int m_, n_;
  double data_[MAXN][MAXN]{0.0};

public:
  Matrix(int m = 0, int n = 0) : m_(m), n_(n) {}

  Matrix(const double *data, int m, int n) : m_(m), n_(n) {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        data_[i][j] = data[i * n_ + j];
      }
    }
  }

  Matrix &operator=(const Matrix &rhs) {
    m_ = rhs.m_;
    n_ = rhs.n_;

    for (int i = 0; i < m_; ++i) {
      for (int j = 0; j < n_; ++j) {
        data_[i][j] = rhs.data_[i][j];
      }
    }
    return *this;
  }

  Matrix operator+(const Matrix &rhs) const {
    assert(m_ == rhs.m_ && n_ == rhs.n_);
    Matrix result(m_, n_);
    for (int i = 0; i < m_; ++i) {
      for (int j = 0; j < n_; ++j) {
        result.Set(data_[i][j] + rhs.data_[i][j], i, j);
      }
    }
    return result;
  }

  Matrix Transpose() const {
    Matrix result(n_, m_);
    for (int i = 0; i < m_; ++i) {
      for (int j = 0; j < n_; ++j) {
        result.Set(data_[i][j], j, i);
      }
    }
    return result;
  }

  void Set(double value, int i, int j) {
    assert(i < m_ && j < n_);
    data_[i][j] = value;
  }

  void Show() const {
    for (int i = 0; i < m_; ++i) {
      for (int j = 0; j < n_; ++j) {
        std::cout << setw(5) << setprecision(3) << data_[i][j];
      }

      std::cout << std::endl;
    }
  }

  int Cols() const { return n_; }
  int Rows() const { return m_; }
};

int main() {
  Matrix m1(3, 5);
  for (int i = 0; i < m1.Rows(); i++) {
    for (int j = 0; j < m1.Cols(); j++) {
      m1.Set(i * j, i, j);
    }
  }
  m1.Show();

  Matrix m2;
  m2 = m1.Transpose();
  m2.Show();

  m2.Set(100, 0, 0);
  m2.Set(100, 1, 2);
  m2.Show();

  m2 = m2.Transpose();
  Matrix m3 = m1 + m2;
  m3.Show();
  return 0;
}
