// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

#include <string>

template<typename T, int size>
class TStack {
 public:
  TStack() : top_(-1) {}

  bool isEmpty() const {
    return top_ == -1;
  }

  bool isFull() const {
    return top_ == kSize - 1;
  }

  T get() const {
    if (!isEmpty())
      return arr_[top_];
    else
      throw std::string("empty");
  }

  void pop() {
    if (!isEmpty())
      top_--;
    else
      throw std::string("empty");
  }

  void push(T item) {
    if (!isFull())
      arr_[++top_] = item;
    else
      throw std::string("full");
  }

 private:
  static const int kSize = size;
  T arr_[kSize];
  int top_;
};

#endif  // INCLUDE_TSTACK_H_
