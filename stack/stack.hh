#include <iostream>

template<typename T>

class Stack {
  protected: 
    T* stack_ = nullptr;
    int top_ = -1;
    int capacity_ = 0;
  
  public:
    Stack(int capacity = 1) {
      Resize(capacity);
    }
    ~Stack() {
      if (stack_) delete[] stack_;
    }
    void Resize(int capacity) {
      T* stack = new T[capacity];
      memcpy(stack, stack_, sizeof(T) * Size());
      delete[] stack_;
      stack_ = stack;
      capacity_ = capacity;
    }
    int Size () {
      return top_ + 1;
    }
    T Top () {
      return stack_[top_];
    }
    int IsEmpty () {
      return top_ == -1;
    }
    void Push(T item) {
      if (Size() >= capacity_) {
        Resize(capacity_ + 1);
      }
      top_ += 1;
      stack_[top_] = item;
    }
    void Pop() {
      if (IsEmpty()) return;
      top_ -= 1;
      if (Size() == 1) return;
      Resize(capacity_ - 1);
    }
    void Print () {
      for (int i = 0; i < Size(); i++) {
        std::cout << stack_[i] << " ";
      }
      std::cout << std::endl;
    }
};
