#include <cassert>
#include <cstring>
#include <iostream>
using namespace std;
#define STRING_MINIMAL_SIZE 32

// NOTE: Usage of function `memset`
void _memset_demo(void *dst, int val, unsigned long size) {
  char *dst_in_byte = (char *)dst;
  for (unsigned long i = 0; i < size; ++i) {
    dst_in_byte[i] = val;
  }
}

class String {
private:
  char *data_{nullptr};
  int max_size_{0};
  int length_{0};

  void Reserve(int size) {
    size = max(size, STRING_MINIMAL_SIZE);
    if (size < max_size_) {
      return;
    } else if (data_ == nullptr) {
      data_ = new char[size];
      memset(data_, 0, size);
    } else {
      char* new_data = new char[size];
      memcpy(new_data, data_, max_size_);
      delete[] data_;
      data_ = new_data;
    }
    max_size_ = size;
  }

public:
  String() {
    length_ = 0;
    max_size_ = 0;
    Reserve(max_size_);
  }
  String(int count, char val) {
    Reserve(count + 1);
    length_ = count;
    memset(data_, val, sizeof(char) * count);
  }

  String(const char *c) { Assign(c); }

  void Copy(const String &rhs) {
    length_ = rhs.length_;
    Reserve(rhs.max_size_);
    memcpy(data_, rhs.data_, rhs.max_size_);
  }

  String &operator=(const String &rhs) {
    Copy(rhs);
    return *this;
  }

  String(const String &rhs) { Copy(rhs); }

  String &operator+=(const String &rhs) {
    Reserve(rhs.length_ + length_ + 1);
    strcpy(data_ + length_, rhs.data_);
    return *this;
  }

  void Assign(const char *c) {
    length_ = strlen(c);
    Reserve(length_ + 1);
    strcpy(data_, c);
  }

  ~String() {
    if (data_ != nullptr) {
      delete[] data_;
    }

    data_ = nullptr;
  }

  int Length() const { return length_; }

  char At(int index) {
    assert(index < length_ + 1);
    return data_[index];
  }

  void Clear() {
    length_ = 0;
    Reserve(0);
  }

  void Show() { std::cout << data_ << std::endl; }
};

int main() {
  String str1, str2(5, 'c'), str3("China");
  str1.Show();
  str2.Show();
  str3.Show();

  str2.Assign("C++ Programming");
  str2.Show();
  str2.Clear();

  char c1 = str3.At(2);
  std::cout << c1 << std::endl;
  std::cout << str3.Length() << std::endl;

  str1.Assign("SEU");

  String str4 = str1;
  str4.Show();
  str4 += str1;
  str4.Show();
  String str5;
  str5 = str4;
  str5.Show();
  return 0;
}
