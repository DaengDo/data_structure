#include <cstring>
#include <iostream>

template <typename T>
class MaxHeap {
 private:
  T* heap_ = nullptr;
  int size_ = 0;
  int capacity_ = 0;

 public:
  explicit MaxHeap(int capacity = 4) { resize(capacity); }

  ~MaxHeap() {
    if (heap_ != nullptr) {
      delete[] heap_;
    }
  }

  auto is_empty() -> bool { return size_ == 0; }

  auto is_full() -> bool { return capacity_ == size_ + 1; }

  auto top() -> T {
    if (is_empty()) {
      std::cout << "heap is empty!\n";
      return T();
    }
    return heap_(1);
  }

  void resize(int capacity) {
    capacity_ = capacity;
    T* temp = new T[capacity_];
    if (heap_ == nullptr) {
      heap_ = temp;
    } else {
      std::memcpy(temp, heap_, sizeof(T) * (size_ + 1));
      delete[] heap_;
      heap_ = temp;
    }
  }

  void push(T element) {
    if (is_full()) {
      resize(capacity_ * 2);
    }

    // 마지막 노드에 추가하고 부모랑 비교하면서 스왑
    size_ += 1;
    int current = size_;

    // (현재 노드가) 부모보다 큰 값일 경우 스왑
    while (current != 1 && element > heap_[current / 2]) {
      heap_[current] = heap_[current / 2];
      current = current / 2;
    }

    heap_[current] = element;
  }

  void pop() {
    // 마지막 노드를 루트로 -> 부모가 자식보다 값이 작을 경우 스왑
    T last_element = heap_[size_];
    size_ -= 1;

    int current = 1;

    while (true) {
      int child = current * 2;

      // 자식 노드가 없을 경우 break;
      if (child > size_) {
        heap_[current] = last_element;
        break;
      }

      int larger_child = child;
      bool has_right_child = size_ >= child + 1;
      // 더 큰 자식 노드 추출
      if (has_right_child && heap_[child] < heap_[child + 1]) {
        larger_child = child + 1;
      }

      // 부모가 더 커서 바꿀 필요 없는 경우
      if (heap_[larger_child] <= last_element) {
        heap_[current] = last_element;
        break;
      }

      // 자식이 더 큰 경우 부모와 스왑
      heap_[current] = heap_[larger_child];
      current = larger_child;
    }
  }

  void print() {
    if (is_empty()) {
      std::cout << "heap is empty!\n";
      return;
    }

    std::cout << "heap size: " << size_ << "\t->\t";

    for (int i = 1; i <= size_; i++) {
      std::cout << heap_[i] << "  ";
    }

    std::cout << '\n';
  }
};

// NOLINTNEXTLINE(modernize-use-trailing-return-type)
int main() {
  MaxHeap<int> max_heap(5);
  max_heap.print();

  max_heap.push(3);
  max_heap.print();

  for (auto element : {1, 2, 3, 4, 5, 6, 7, 8, 9}) {
    max_heap.push(element);
    max_heap.print();
  }

  for (int i = 0; i < 9; i++) {
    max_heap.pop();
    max_heap.print();
  }
}