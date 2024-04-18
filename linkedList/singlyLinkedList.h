#include <iostream>
#include <string>

template<typename T> class SinglyLinkedList {
  protected: 
    Node* first_ = nullptr;

  public: 
    struct Node {
      T item = T();
      Node* next = nullptr;
    };

    SinglyLinkedList() {}

    SinglyLinkedList(const SinglyLinkedList& list) {
      if (list.first_ == nullptr) return;
      
      Node* temp = list.first_;

      while (temp) {
        PushBack(temp->item);
        temp = temp->next;
      }      
    }

    ~SinglyLinkedList() {
      Clear();
    }

    void Clear() {
      Node* current = first_;

      while (current) {
        Node* temp = current->next;
        delete current;
        current = temp;
      }
    }

    bool IsEmpty() {
      return first_ == nullptr;
    }

    int Size() {
      int size = 0;

      Node* temp = first_;
      while (temp) {
        size += sizeof(temp->item);
        temp = temp->next;
      }

      return size;
    }

    Node* Front() {
      assert(first_);

      return first_;
    }

    Node* Back() {
      assert(first_);

      Node* temp = first_;
      while (temp->next != nullptr) {
        temp = temp->next;
      }

      return temp;
    }

    Node* Find(T item) {
      // 첫 번째로 찾은 item이 동일한 노드 포인터 반환
      Node* temp = first_;
      while (temp) {
        if (temp->item == item) return temp;
        temp = temp->next;
      }

      return temp;
    }

    void InsertBack(Node* node, T item) {
      Node* temp = node->next;
      node->next = new Node({ item, temp });
    }

    void Remove(Node* n) {
      assert(first_);

      // 삭제할 노드가 first 노드인 경우 예외처리
      if (first_ == n) {
        delete n;
        return;
      }

      Node* temp = first_;

      while (temp->next != n) {
        temp = temp->next;
      }
      temp->next = n->next;
      delete n;
    }

    void PushFront(T item) {
      Node* new_node = new Node({ item, first_ });
      first_ = new_node;
    }

    void PushBack(T item) {
      Node* temp = new Node({ item, nullptr });
      if (first_) {
        Back()->next = temp;
      } else {
        first_ = temp;
      }
    }

    void PopFront() {
      if (IsEmpty()) {
        using namespace std;
        cout << "Nothing to Pop in PopFront()" << endl;
        return;
      }

      assert(first_);

      Node* temp = first_->next;
      delete first_;
      first_ = temp;
    }

    void PopBack() {
      if (IsEmpty()) {
        using namespace std;
        cout << "Nothing to Pop in PopBack()" << endl;
        return;
      }

      assert(first_);

      Node* temp = first_;
      Node* back_node = Back();
      while (temp->next != back_node) {
        temp = temp->next;
      }

      delete back_node;
      temp->next = nullptr;
    }

    void Reverse() {
      Node* curr = first_;
      Node* prev = nullptr;
      Node* next = first_->next;
      while (1) {
        Node* temp = curr->next;
        curr->next = prev;
        if (temp == nullptr) break;
        prev = curr;
        curr = temp;
        next = temp->next;
      }
      first_ = curr;
    }

    void Print() {
      using namespace std;

      Node* current = first_;

      if (IsEmpty())
        cout << "Empty" << endl;
      else {
        cout << "Size = " << Size() << " ";

        while (current) {
          cout << current->item;

          if (current->next)
            cout << " -> ";
          else
            cout << " -> NULL";

          current = current->next;
        }
        cout << endl;
      }
    }
};