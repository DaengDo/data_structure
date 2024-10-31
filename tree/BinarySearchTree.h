#include <iostream>

#include "tree.h"

template <typename K, typename V>
class BinarySearchTree : public Tree<K, V> {
  using Base = Tree<K, V>;
  using Item = Item<K, V>;
  using Node = Node<K, V>;

 public:
  BinarySearchTree(Node* root = nullptr) { this->root_ = root; }

  ~BinarySearchTree() {
    // Tree 의 소멸자 호출되니까 필요없음
    // if (this->root_ != nullptr) {
    //   DeleteTree();
    // }
  }

  void RecurInsert(const Item& item) {
    if (this->root_ == nullptr) {
      this->root_ = new Node{item, nullptr, nullptr};
    }
    this->root_ = RecurInsert(this->root_, item);
  }
  Node* RecurInsert(Node* node, const Item& item) {
    if (node == nullptr) {
      node = new Node{item, nullptr, nullptr};
    } else if (node->item.key > item.key) {
      node->left = RecurInsert(node->left, item);
    } else if (node->item.key < item.key) {
      node->right = RecurInsert(node->right, item);
    } else {
      node->item.value = item.value;
    }
    return node;
  }

  void IterInsert(Item& item) {
    if (this->root_ == nullptr) {
      this->root_ = new Node{item, nullptr, nullptr};
      return;
    }

    if (this->root_.item.key == item.key) {
      this->root_.item.value = item.value;
      return;
    }

    Node* parent = nullptr;
    Node* current = this->root_;

    while (true) {
      if (current == nullptr) {
        Node* new_node = new Node{item, nullptr, nullptr};
        if (parent->item.key > item.key) {
          parent->left = new_node;
        } else {
          parent->right = new_node;
        }
        break;
      }

      if (current->item.key == item.key) {
        current->item.value = item.value;
        break;
      }

      if (parent->item.key > item.key) {
        current = parent->left;
      } else {
        current = parent->right;
      }
      parent = current;
    }
  }

  Item* RecurGet(const K& key) { return RecurGet(this->root_, key); }
  Item* RecurGet(Node* node, const K& key) {
    if (node == nullptr) {
      return nullptr;
    } else if (node->item.key > key) {
      return RecurGet(node->left, key);
    } else if (node->item.key < key) {
      return RecurGet(node->right, key);
    } else {
      return &node->item;
    }
  }

  Item* IterGet(K key) {
    Node* node = this->root_;

    while (true) {
      if (node == nullptr) {
        return nullptr;
      } else if (node->item.key > key) {
        node = node->left;
      } else if (node->item.key < key) {
        node = node->right;
      } else {
        return &node->item;
      }
    }
  }

  Node* MinKeyLeft(Node* node) {
    if (node == nullptr) return node;
    while (node->left != nullptr) {
      node = node->left;
    }
    return node;
  }

  void Remove(const K& key) { this->root_ = Remove(this->root_, key); }

  Node* Remove(Node* node, const K& key) {
    if (node == nullptr) {
      std::cout << "not found: " << key << '\n';
      return node;
    } else if (node->item.key > key) {
      node->left = Remove(node->left, key);
    } else if (node->item.key < key) {
      node->right = Remove(node->left, key);
    } else {
      std::cout << "remove: " << key << '\n';
      // 삭제할 노드 찾음
      if (node->left == nullptr) {
        // 1) left가 없을 때는 right 포인터를 전달
        Node* temp = node->right;
        delete node;
        return temp;
      } else if (node->right == nullptr) {
        // 2) right가 없을 때는 left 포인터를 전달
        Node* temp = node->left;
        delete node;
        return temp;
      } else {
        // 3) 자식이 둘이면 오른쪽 서브 트리의 가장 작은 값을 현재 위치로 격상
        Node* temp = MinKeyLeft(node->right);
        node->item = temp->item;
        // 오른쪽 서브 트리의 가장 작은 값`MinKeyLeft()`을 트리에서 제거
        node->right = Remove(node->right, temp->item.key);
      }
    }
    return node;
  }
};
