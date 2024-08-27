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
    std::cout << '(' << node->item.key << ", " << node->item.value << ") ";
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

  void InOrder(OrderType type = OrderType::RECUR) {
    if (type == OrderType::ITER) {
      IterInOrder(root);
    } else {
      RecurInOrder(root);
    }
  }
  /**
   *            5
   *       3         7
   *    1    4     6    8
   *
   * in: 3 -> 1 -> 4 -> 5 -> 7 -> 6 -> 8
   */
  void IterInOrder(Node* node) {
    if (node == nullptr) return;
    std::stack<Node*> s;
    if (node->right != nullptr) s.push(node->right);
    s.push(node);
    if (node->left != nullptr) s.push(node->left);

    while (!s.empty()) {
      Node* current = s.top();
      Visit(current);
      s.pop();
      if (current == root) continue;
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
  void IterPostOrder(Node* node) {
    if (node == nullptr) return;
    std::stack<Node*> s;
    s.push(node);
    if (node->right != nullptr) s.push(node->right);
    if (node->left != nullptr) s.push(node->left);

    while (!s.empty()) {
      Node* current = s.top();
      s.pop();
      Visit(current);
      if (current == root) continue;
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
    if (root == nullptr)
      root = new Node{item, nullptr, nullptr};
    else if (type == OrderType::RECUR)
      root = RecurInsert(root, item);
    else
      root = IterInsert(root, item);
  }
  Node* RecurInsert(Node* node, Item item) {
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
  Node* IterInsert(Node* node, Item item) {
    // TODO 일단 나중에 해보자
    return node;
  }

  void DeleteNode(K key) {
    // TODO key값 기반 node 삭제하기
    // 1. 자식이 없는 경우
    // 2. 자식이 하나인 경우
    // 3. 자식이 둘인 경우
    // 4. 위 3가지 경우로 나눠서 생각하기
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
  // using Node = BinarySearchTree<int, char>::Node;
  using Item = BinarySearchTree<int, char>::Item;
  BinarySearchTree<int, char> bst;

  /*           5
   *      3         7
   *   1    4    6     8
   * Pre  : 5 3 1 4 7 6 8
   * In   : 3 1 4 5 7 6 8
   * Post : 3 1 4 7 6 8 5
   * Level: 5 3 7 1 4 6 8
   */

  for (int i : {5, 3, 7, 1, 4, 6, 8}) {
    bst.Insert(Item{i, char('A' + i)});
  }

  std::cout << "\n(Recur)pre order: \t";
  bst.PreOrder(OrderType::RECUR);
  std::cout << "\n(Iter)pre order: \t";
  bst.PreOrder(OrderType::ITER);

  std::cout << "\n\n(Recur)in order: \t";
  bst.InOrder(OrderType::RECUR);
  std::cout << "\n(Iter)in order: \t";
  bst.InOrder(OrderType::ITER);

  std::cout << "\n\n(Recur)post order: \t";
  bst.PostOrder(OrderType::RECUR);
  std::cout << "\n(Iter)post order: \t";
  bst.PostOrder(OrderType::ITER);

  std::cout << "\n\nlevel order:\t\t";
  bst.LevelOrder();

  return 0;
}