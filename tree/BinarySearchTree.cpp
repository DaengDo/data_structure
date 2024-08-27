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
   *            5
   *       3         7
   *    1    4     6    8
   *
   * pre: 5 -> 3 -> 1 -> 4 -> 7 -> 6 -> 8
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
   *            5
   *       3         7
   *    1    4     6    8
   *
   * post: 3 -> 1 -> 4 -> 7 -> 6 -> 8 -> 5
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

  Node* MinKeyLeft(Node* node) {
    if (node == nullptr) return node;
    while (node->left != nullptr) {
      node = node->left;
    }
    return node;
  }

  void Remove(const K& key) {
    std::cout << "\nremove: " << key << std::endl;
    root = Remove(root, key);
  }

  Node* Remove(Node* node, const K& key) {
    if (node == nullptr) {
      return node;
    } else if (node->item.key > key) {
      node->left = Remove(node->left, key);
    } else if (node->item.key < key) {
      node->right = Remove(node->left, key);
    } else {
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

 private:
  Node* root = nullptr;
};

/**
 *            1
 *       2         3
 *    4    5     6    7
 */

int main() {
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

  bst.Remove(5);

  std::cout << "\n\nlevel order:\t\t";
  bst.LevelOrder();

  return 0;
}