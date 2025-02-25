#include <cassert>
#include <iostream>

#include "BinarySearchTree.h"

template <typename K, typename V>
class AVL : public BinarySearchTree<K, V> {
  using Base = Tree<K, V>;
  using Item = Item<K, V>;
  using Node = Node<K, V>;

 public:
  int Balance(Node* node) {
    if (node)
      return this->Height(node->left) - this->Height(node->right);
    else
      return 0;
  }

  /*
  # before
    3
      2
    a   1
          b

  # after
      2
    3   1
      a   b
  */
  Node* RotateLeft(Node* parent) {
    Node* child = parent->right;  // 2
    parent->right = child->left;  // a를 3의 자식으로
    child->left = parent;         // 2의 왼쪽을 3으로
    return child;
  }

  /*
  # before
        3
      2
    1

  # after
      2
    1   3
  */
  Node* RotateRight(Node* parent) {
    Node* child = parent->left;
    parent->left = child->right;
    child->right = parent;
    return child;
  }

  void Insert(const Item& item) { this->root_ = Insert(this->root_, item); }

  Node* Insert(Node* node, const Item& item) {
    if (!node) return new Node{item, nullptr, nullptr};

    const auto& key = item.key;

    if (key < node->item.key)
      node->left = Insert(node->left, item);
    else if (key > node->item.key)
      node->right = Insert(node->right, item);
    else {
      node->item = item;
      return node;
    }

    int balance = Balance(node);

    // balance가 0, 1, -1 이면 조절할 필요가 없다고 판단

    // LL -> Right Rotation
    if (balance > 1 && Balance(node->left) >= 0) {
      return RotateRight(node);
    }

    // RR -> Left Rotation
    if (balance < -1 && Balance(node->right) <= 0) {
      return RotateLeft(node);
    }

    // LR -> Left-Right Rotation
    if (balance > 1 && Balance(node->left) < 0) {
      node->left = RotateLeft(node->left);
      return RotateRight(node);
    }

    // RL -> Right-Left Rotation
    if (balance < -1 && Balance(node->right) > 0) {
      node->right = RotateLeft(node->right);
      return RotateRight(node);
    }

    return node;
  }

  Node* MinKeyNode(Node* node) {
    assert(node);
    while (node->left) node = node->left;
    return node;
  }

  void Remove(const K& key) {
    using namespace std;
    cout << "Remove " << key << endl;
    this->root_ = Remove(this->root_, key);
  }

  Node* Remove(Node* node, const K& key) {
    // BST와 동일
    if (!node) return node;

    if (key < node->item.key)
      node->left = Remove(node->left, key);
    else if (key > node->item.key)
      node->right = Remove(node->right, key);
    else {
      if (!node->left) {
        Node* temp = node->right;
        delete node;
        return temp;
      } else if (!node->right) {
        Node* temp = node->left;
        delete node;
        return temp;
      }

      Node* temp = MinKeyNode(node->right);
      node->item = temp->item;
      node->right = Remove(node->right, temp->item.key);
    }

    if (node == NULL) return node;

    // 균형 잡기

    int balance = Balance(node);

    // LL -> Right Rotation
    if (balance > 1 && Balance(node->left) >= 0) {
      return RotateRight(node);
    }

    // RR -> Left Rotation
    if (balance < -1 && Balance(node->right) <= 0) {
      return RotateLeft(node);
    }

    // LR -> Left-Right Rotation
    if (balance > 1 && Balance(node->left) < 0) {
      node->left = RotateLeft(node->left);
      return RotateRight(node);
    }

    // RL -> Right-Left Rotation
    if (balance < -1 && Balance(node->right) > 0) {
      node->right = RotateLeft(node->right);
      return RotateRight(node);
    }

    return node;
  }
};
