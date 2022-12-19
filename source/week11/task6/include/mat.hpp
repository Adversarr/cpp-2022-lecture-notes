#include <iomanip>
#include <iostream>

// compile time literal
#define MAX_SIZE 10

class Matrix {
private:
  double data_[MAX_SIZE][MAX_SIZE];
  int rows_;
  int cols_;

public:
  Matrix(int rows = 0, int cols = 0) : rows_(rows), cols_(cols) {}

  Matrix(const Matrix& another) {
    rows_ = another.rows_;
    cols_ = another.cols_;
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        data_[i][j] = another.data_[i][j];
      }
    }
  }

  Matrix(double *data, int rows = 0, int cols = 0) : rows_(rows), cols_(cols) {
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        data_[i][j] = data[i * cols_ + j];
      }
    }
  }

  void Transpose() {
    for (int i = 0; i < rows_; ++i) {
      for (int j = i + 1; j < cols_; ++j) {
        double t = data_[i][j];
        data_[i][j] = data_[j][i];
        data_[j][i] = t;
      }
    }

    int t = rows_;
    rows_ = cols_;
    cols_ = t;
  }

  Matrix(const Matrix &lhs, const Matrix &rhs) {
    if (lhs.cols_ != rhs.rows_) {
      std::cout << "lhs.cols != rhs.rows!" << std::endl;
    }
    rows_ = lhs.rows_;
    cols_ = rhs.cols_;
    for (int i = 0; i < lhs.rows_; ++i) {
      for (int j = 0; j < rhs.cols_; ++j) {
        data_[i][j] = 0;
        for (int k = 0; k < lhs.cols_; ++k) {
          data_[i][j] += lhs.data_[i][k] * rhs.data_[k][j];
        }
      }
    }
  }

  void Display() const {
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        std::cout << std::fixed << std::setprecision(2) << data_[i][j] << ' ';
      }
      std::cout << std::endl;
    }
  }

  Matrix operator*(const Matrix &rhs) const { return Matrix(*this, rhs); }
};
