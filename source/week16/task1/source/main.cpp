#include <cassert>
#include <cstring>
#include <iostream>
#define STRING_MINIMAL_SIZE 32

using namespace std;
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
      size *= 2;
      char *new_data = new char[size];
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

  String &operator=(const char *data) {
    Assign(data);
    return *this;
  }

  bool operator<(const String &rhs) const {
    for (int i = 0; i < rhs.length_ && i < length_; ++i) {
      if (data_[i] < rhs.data_[i]) {
        return true;
      } else if (data_[i] > rhs.data_[i]) {
        return false;
      }
    }

    return false;
  }

  // See also: strcmp.
  bool operator==(const String &rhs) const {
    if (length_ != rhs.length_) {
      return false;
    }
    for (int i = 0; i < rhs.length_ && i < length_; ++i) {
      if (data_[i] != rhs.data_[i]) {
        return false;
      }
    }

    return true;
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

  void PushBack(char val) {
    length_ = length_ + 1;
    Reserve(length_ + 1);
    data_[length_ - 1] = val;
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

  char At(int index) const {
    assert(index < length_ + 1);
    return data_[index];
  }

  void Clear() {
    length_ = 0;
    Reserve(0);
  }

  void Show() { std::cout << data_ << std::endl; }

  char &operator[](int i) { return data_[i]; }

  String operator+(const String &rhs) const {
    String retval = *this;
    retval += rhs;
    return retval;
  }

  friend std::ostream& operator<<(std::ostream& os, const String &str);
};

std::istream &operator>>(std::istream &is, String &str) {
  char c = is.get();
  str.Clear();
  while (is.good()) {
    str.PushBack(c);
    c = is.get();
    if (std::isspace(c)) {
      is.putback(c);
      break;
    }
  }
  return is;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
  os << str.data_;
  return os;
}

int main() {
  String str1;
  cin >> str1;
  cout << str1 << endl;
  return 0;
}

