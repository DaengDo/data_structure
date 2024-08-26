#include <iostream>
#include <queue>
#include <stack>

enum class OrderType { RECUR, ITER };

template <typename K, typename V>
class BinarySearchTree {
 public:
  struct Item {
    K key = K();
    V value = V();
  };

  struct Node {
    Item item = new Item{K(), V()};
    Node* left = nullptr;
    Node* right = nullptr;
  };

  BinarySearchTree(Node* newRoot = nullptr) { root = newRoot; }

  ~BinarySearchTree() {
    if (root != nullptr) DeleteTree(root);
  }

  void DeleteTree(Node* node) {
    if (node->left != nullptr) DeleteTree(node->left);
    if (node->right != nullptr) DeleteTree(node->right);
    delete node;
  }

  void Visit(Node* node) {
    std::cout << node->item.key << ' ' << node->item.value << std::endl;
  }

  /**
   *            1
   *       2         3
   *    4    5     6    7
   *
   * pre: 1 -> 2 -> 4 -> 5 -> 3 -> 6 -> 7
   */
  void PreOrder(OrderType type = OrderType::RECUR) {
    if (type == OrderType::ITER) {
      IterPreOrder(root);
    } else {
      RecurPreOrder(root);
    }
  }
  void IterPreOrder(Node* node) {
    std::stack<Node*> s;
    s.push(node);
    while (!s.empty()) {
      Node* current = s.top();
      s.pop();
      Visit(current);
      if (current->right != nullptr) s.push(current->right);
      if (current->left != nullptr) s.push(current->left);
    }
  }
  void RecurPreOrder(Node* node) {
    if (node == nullptr) return;
    Visit(node);
    RecurPreOrder(node->left);
    RecurPreOrder(node->right);
  }

  /**
   *            1
   *       2         3
   *    4    5     6    7
   *
   * in: 2 -> 4 -> 5 -> 1 -> 3 -> 6 -> 7
   */
  void InOrder(OrderType type = OrderType::RECUR) {
    if (type == OrderType::ITER) {
      IterInOrder(root);
    } else {
      RecurInOrder(root);
    }
  }
  void IterInOrder(Node* node) {
    if (node != nullptr) return;
    std::stack<Node*> s;
    if (node->right != nullptr) s.push(node->right);
    s.push(node);
    if (node->left != nullptr) s.push(node->left);

    while (!s.empty()) {
      Node* current = s.top();
      s.pop();
      Visit(current);
      if (current->right != nullptr) s.push(current->right);
      if (current->left != nullptr) s.push(current->left);
    }
  }
  void RecurInOrder(Node* node) {
    if (node == nullptr) return;
    RecurPreOrder(node->left);
    Visit(node);
    RecurPreOrder(node->right);
  }

  /**
   *            1
   *       2         3
   *    4    5     6    7
   *
   * post: 2 -> 4 -> 5 -> 3 -> 6 -> 7 -> 1
   */
  void PostOrder(OrderType type = OrderType::RECUR) {
    if (type == OrderType::ITER) {
      IterPostOrder(root);
    } else {
      RecurPostOrder(root);
    }
  }
  void IterPostOrder() {
    if (node != nullptr) return;
    std::stack<Node*> s;
    s.push(node);
    if (node->right != nullptr) s.push(node->right);
    if (node->left != nullptr) s.push(node->left);

    while (!s.empty()) {
      Node* current = s.top();
      s.pop();
      Visit(current);
      if (current->right != nullptr) s.push(current->right);
      if (current->left != nullptr) s.push(current->left);
    }
  }
  void RecurPostOrder(Node* node) {
    if (node == nullptr) return;
    RecurPreOrder(node->left);
    RecurPreOrder(node->right);
    Visit(node);
  }

  void LevelOrder() {
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
      Node* front = q.front();
      if (front->left != nullptr) q.push(front->left);
      if (front->right != nullptr) q.push(front->right);
      Visit(front);
      q.pop();
    }
  }

  void Insert(Item item, OrderType type = OrderType::RECUR) {
    // TODO
    if (root == nullptr)
      root = new Node{item, nullptr, nullptr};
    else if (type == OrderType::RECUR)
      root = RecurInsert(root, item);
    else
      root = IterInsert(root, item);
  }
  Node* RecurInsert(Node* node, Item item) {
    // TODO
    if (node == nullptr) {
    }
    if (node->item.key == item.key) {
      node->item.value = item.value;
      return node;
    }
    if (node->item.key > item.key) {
      node->left = RecurInsert(node->left, item);
    } else {
      node->right = RecurInsert(node->right, item);
    }
  }
  Node* IterInsert(Node* node, Item item) {
    // TODO
  }

  void DeleteNode() {
    // TODO
  }

 private:
  Node* root = nullptr;
};

/**
 *            1
 *       2         3
 *    4    5     6    7
 */

int main() {
  // using Node = BinarySearchTree<char, int>::Node;
  // using Item = BinarySearchTree<char, int>::Item;
  // BinarySearchTree<char, int> bst;

  return 0;
}