#include <iostream>
#include <iomanip>
#include <cstring>
#include <cassert>

template<typename T>
class Queue {
  protected:
    T* queue_ = nullptr;
    int front_ = -1; // pop할 때 빠저야 하는 인덱스
    int back_ = -1; // 가장 뒤쪽 요소가리키는 포인터
    int capacity_ = 0;
    int size_ = 0;

  public:
    Queue (int new_capacity = 4) {
      capacity_ = new_capacity;
      T* new_queue = new T[capacity_];
      queue_ = new_queue;
    }

    ~Queue () {
      if (queue_) delete [] queue_;
    }

    bool IsEmpty () {
      return size_ == 0;
    }
    bool IsFull () {
      return capacity_ == size_;
    }
    bool IsReversed () {
      // back_이랑 front_가 뒤집혀있는지 확인하는 함수
      return back_ < front_;
    }
    int Length () {
      return size_;
    }

    void Print () {
      std::cout << "index: ";
      for (int i = 0; i < capacity_; i++) {
        std::cout << std::setw(3) << i;
      }
      std::cout << "\nValue: ";
      for (int i = 0; i < capacity_; i++) {
        bool hasValue = IsReversed()
          ? (front_ <= i && i <= capacity_) || (0 <= i && i <= back_)
          : front_ <= i && i <= back_;
        if (hasValue) {
          std::cout << std::setw(3) << queue_[i];
        } else {
          std::cout << std::setw(3) << ' ';
        }
      }
      std::cout << std::endl;
    }

    void Resize (int new_capacity) {
      T* new_queue = new T[new_capacity];
      // 정방향일 떄
      bool isStraight = front_ == -1 || size_ - front_ == 1;
      if (back_ - front_ >= 0) {
        memcpy(new_queue, queue_, sizeof(T) * size_);
      } else {
        // 메모리 복사 0부터 back_까지
        for (int i = 0; i <= back_; i++) {
          new_queue[i] = queue_[i];
        }
        // 메모리 복사 front_부터 끝까지
        for (int i = front_; i <= capacity_; i++) {
          new_queue[i] = queue_[i];
        }
      }
      delete [] queue_;
      queue_ = new_queue;
      capacity_ = new_capacity;
    }

    void Pop () {
      if (size_ == 0) return; // assert

      size_ -= 1;

      if (front_ == capacity_) {
        front_ = 0;
      } else {
        front_ += 1;
      }
      // 최소 크기4이므로, 요소가 하나밖에 없고 크기가 1인 경우는 상정 안함
    }

    void Push (T value) {
      if (IsFull()) Resize(capacity_ * 2);

      size_ += 1;

      if (back_ == capacity_) {
        back_ = 0;
      } else {
        back_ += 1;
      }
      queue_[back_] = value;

      if (front_ == -1) front_ = 0;
    }

    T Front () {
      assert(!IsEmpty());
      return queue_[front_];
    }
};

int main () {
  // Queue<int> queue;
  // for (auto num: {0, 2, 3, 4, 5, 1}) {
  //   queue.Push(num);
  //   queue.Print();
  // }
  // for (int i = 0; i < 6; i++) {
  //   std::cout << queue.Front() << std::endl;
  //   queue.Pop();
  // }

  // 요세푸스
  int step, length;

  Queue<int> queue;

  std::cin >> length >> step;

  // 만약 2명 1 2 3 4 5 6 7 8 9 이라면
  // 2 4 6 8 1 7 3 9 로 5만 살아남음

  // 1번부터 세기 위함
  for (int i = 1; i < length + 1; i++) {
    std::cout << i << "  ";
    queue.Push(i);
  }
  std::cout << std::endl;

  for (int i = 1; queue.Length() != 1; i++) {
    int temp = queue.Front();
    queue.Pop();
    
    if (i % step == 0) {
      std::cout << "kill: " << temp << std::endl;
    } else {
      queue.Push(temp);
    };
  }

  std::cout << "Last man standing: " << queue.Front() << std::endl;

  return 0;
}
