#include <iostream>

struct Complex {
  double real, image;
  Complex(double real = 0, double image = 0) : real(real), image(image) {}
};

template <typename T> class LinkedListInternal {
public:
  LinkedListInternal() {
    next_ = nullptr;
    prev_ = nullptr;
  }

  LinkedListInternal(LinkedListInternal<T> *prev, LinkedListInternal<T> *next,
                     T value)
      : prev_(prev), next_(next), data_(value) {}

  T &Value() { return data_; }

  LinkedListInternal<T> *EmplaceBack(T val) {
    LinkedListInternal<T> *backup_next = next_;
    next_ = new LinkedListInternal<T>(this, backup_next, val);
    if (backup_next != nullptr) {
      backup_next->prev_ = next_;
    }
    return next_;
  }

  /**
   * Original prev_ -> this
   *
   * After emplace: prev_ -> new -> this
   */
  LinkedListInternal<T> *EmplaceFront(T val) {
    LinkedListInternal<T> *backup_prev = prev_;
    prev_ = new LinkedListInternal<T>(backup_prev, this, val);
    if (backup_prev != nullptr) {
      backup_prev->next_ = prev_;
    }
    return prev_;
  }

  LinkedListInternal<T> *Next() const { return next_; }

  LinkedListInternal<T> *Prev() const { return prev_; }

private:
  LinkedListInternal<T> *next_;
  LinkedListInternal<T> *prev_;

  T data_;
};

template <typename T> class LinkedList {
public:
  LinkedList() : tail_(new LinkedListInternal<T>) { head_ = tail_; }

  ~LinkedList() { Destroy(); }

  bool IsEmpty() const { return head_ == tail_; }

  void PushBack(T val) {
    LinkedListInternal<T> *tail_prev = tail_->EmplaceFront(val);
    if (head_ == tail_) {
      head_ = tail_prev;
    }
  }
  void PushFront(T val) { head_ = head_->EmplaceFront(val); }

  LinkedListInternal<T> *Begin() const { return head_; }

  LinkedListInternal<T> *End() const { return tail_; }

  void Destroy() {
    if (head_ == nullptr) {
      return;
    }
    LinkedListInternal<T> *ptr = head_;
    do {
      LinkedListInternal<T> *next = ptr->Next();
      // Inspect the deletion:
      std::cout << "Delete: " << ptr << std::endl;
      delete ptr;
      ptr = next;
    } while (ptr != nullptr);
    head_ = nullptr;
    tail_ = nullptr;
  }

  void Copy(const LinkedList<T> &linked_list) {
    Destroy();
    head_ = tail_ = new LinkedListInternal<T>;
    for (LinkedListInternal<Complex> *iter = linked_list.Begin();
         iter != linked_list.End(); iter = iter->Next()) {
      PushBack(iter->Value());
    }
  }

  LinkedList<T>& operator=(const LinkedList<T>& rhs){
    Copy(rhs);
    return *this;
  }

  LinkedList(const LinkedList<T> & rhs) {
    head_ = tail_ = nullptr;
    Copy(rhs);
  }

private:
  LinkedListInternal<T> *head_;

  LinkedListInternal<T> *tail_;
};
template<typename T>
void print_linked_list(const LinkedList<T> &linked_list) {

  for (LinkedListInternal<Complex> *iter = linked_list.Begin();
       iter != linked_list.End(); iter = iter->Next()) {
    std::cout << "Node address: " << iter << "\tPrev: " << iter->Prev()
              << "\tNext: " << iter->Next() << "\tValue: " << iter->Value().real
              << " + " << iter->Value().image << std::endl;
  }

}


int main() {
  LinkedList<Complex> linked_list;
  for (int i = 0; i < 2; ++i) {
    linked_list.PushBack(Complex(i, 0));
  }
  for (int i = 0; i < 2; ++i) {
    linked_list.PushFront(Complex(-i, i));
  }

  print_linked_list(linked_list);
  LinkedList<Complex> copy_construct = linked_list;
  std::cout << "Test for copy constructor:" << std::endl;
  print_linked_list(copy_construct);

  LinkedList<Complex> copy_assignment = linked_list;
  std::cout << "Test for copy assignment:" << std::endl;
  print_linked_list(copy_assignment);
  return 0;
}
