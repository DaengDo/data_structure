#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>

template<typename T>
class MinHeap {
  protected:
    T* heap_ = nullptr;
    int capacity_ = 0;
    int size_ = 0;

  public:
    MinHeap (int cap = 10) {
      capacity_ = cap;
      size_ = 0;
      T* new_heap = new T[capacity_ + 1];
      heap_ = new_heap;
    }
    ~MinHeap () {
      if (heap_) delete [] heap_;
    }

    bool IsFull () {
      return size_ == capacity_;
    }

    bool IsEmpty () {
      return size_ == 0;
    }

    void Resize (int new_capacity) {
      T* new_heap = new T[new_capacity];
      std::memcpy(new_heap, heap_, sizeof(T) * (capacity_ + 1));
      delete[] heap_;
      heap_ = new_heap;
      capacity_ = new_capacity;
    }

    void Push (T val) {
      if (IsFull()) Resize(capacity_ * 2);
      size_ += 1;
      heap_[size_] = val;

      // 정렬
      int parent_index = size_ / 2;
      int child_index = size_;
      bool isRoot = parent_index == 0;
      while (!isRoot && heap_[parent_index] > val) {
        // 부모 자식 노드 변경
        heap_[child_index] = heap_[parent_index];
        heap_[parent_index] = val;
        child_index = parent_index;
        parent_index = parent_index / 2;
      }
    }

    void Pop () {
      // 루트 요소 반환하기
      assert(!IsEmpty());
      // if (IsEmpty()) return nullptr;

      int current_idx = 1;
      heap_[current_idx] = heap_[size_];
      size_ -= 1;
      while (current_idx * 2 <= size_) {
        // 왼쪽 값이 사이즈를 넘어서는 경우
        if (current_idx * 2 + 1 > size_) {
          if (heap_[current_idx * 2] < heap_[current_idx]) {
            T temp = heap_[current_idx];
            heap_[current_idx]  = heap_[current_idx * 2];
            heap_[current_idx * 2] = temp;
          }
          break;
        }

        // 오른쪽 왼쪽 비교해서 더 작은값과 교환
        int exchange_idx = heap_[current_idx * 2] < heap_[current_idx * 2 + 1] ? current_idx * 2 : current_idx * 2 + 1;

        T temp = heap_[current_idx];
        heap_[current_idx] = heap_[exchange_idx];
        heap_[exchange_idx] = temp;

        current_idx = exchange_idx;
      }
    }

    T Top () {
      return heap_[1];
    }
};

int main () {
  // 최소 힙 활용
  MinHeap<int> heap;

  int inputLength;
  std::cin >> inputLength;

  for (int i = 0; i < inputLength; i++) {
    int temp;
    std::cin >> temp;
    heap.Push(temp);
  }

  for (int i = 0; i < inputLength; i++) {
    std::cout << heap.Top() << "\n";
    heap.Pop();
  }

  return 0;
}