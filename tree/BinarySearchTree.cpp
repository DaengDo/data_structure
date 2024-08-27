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

  Node* MinKeyLeft(Node* node) {
    if (node == nullptr) return node;
    while (node->left != nullptr) {
      node = node->left;
    }
    return node;
  }

  void DeleteNode(K key) {
    // TODO key값 기반 node 삭제하기
    // 해당 키의 노드를 찾기
    // 노드를 찾으면 삭제 시작, 못찾으면 그대로 종료
    // 1. 자식이 없는 경우 -> 그냥 삭제
    // 2. 자식이 하나인 경우 -> 자식 포인터가 current의 부모를 가르키도록 수정
    // 3. 자식이 둘인 경우 -> MinKeyLeft가 삭제할 노드의 자리로 오도록 수정
    Node* current = root;
    Node* parent = nullptr;
    while (current != nullptr) {
      if (current->item.key > key) {
        current = current->left;
        parent = current;
      } else if (current->item.key < key) {
        current = current->right;
        parent = current;
      } else {
        break;
      }
    }
    if (current == nullptr) return;  // 삭제할 대상 없음

    // 자식이 없는 경우
    if (current->left == nullptr && current->right == nullptr) {
      // 터미널 노드 삭제 및 부모 포인터 초기화
      if (parent == nullptr) {
        root = nullptr;
        delete current;
      } else if (parent->item.key > key) {
        parent->left = nullptr;
        delete current;
      } else {
        parent->right = nullptr;
        delete current;
      }
      // 자식이 둘 다 있는 경우
    } else if (current->left != nullptr && current->right != nullptr) {
      // current->right 의 MinKeyLeft를 호출해서 걔를 삭제할 노드 자리로 격상
      Node* nodeToSwap = MinKeyLeft(current);
      if (parent == nullptr) {
        root = nodeToSwap;
      } else if (parent->item.key > key) {
        parent->left = nodeToSwap;
      } else {
        parent->right = nodeToSwap;
      }
      // MinKeyLeft의 부모 요소 포인터도 초기화 해야 하는데 어떻게 하지?
    }
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