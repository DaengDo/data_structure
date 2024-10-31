#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>

template <typename K, typename V>
struct Item {
  K key = K();
  V value = V();
};

template <typename K, typename V>
struct Node {
  Item<K, V> item;
  Node* left = nullptr;
  Node* right = nullptr;
};

template <typename K, typename V>
class Tree {
 public:
  using Item = Item<K, V>;
  using Node = Node<K, V>;

  Tree(Node* root = nullptr) { root_ = root; }

  ~Tree() { DeleteTree(root_); }

  void DeleteTree() { DeleteTree(root_); }
  void DeleteTree(Node* node) {
    if (node == nullptr) return;
    DeleteTree(node->left);
    DeleteTree(node->right);
    delete node;
  }

  void Visit(Node* node) {
    if (node == nullptr) {
      std::cout << "can't visit nullptr\n";
    } else {
      std::cout << '(' << node->item.key << ", " << node->item.value << ") -> ";
    }
  }

  // MARK: pre order
  void IterPreOrder() {}
  void IterPreOrder(Node* node) {}
  void RecurPreOrder() {
    std::cout << "--Pre Order--\n\t";
    RecurPreOrder(root_);
    std::cout << '\n';
  }
  void RecurPreOrder(Node* node) {
    if (node == nullptr) return;
    Visit(node);
    RecurPreOrder(node->left);
    RecurPreOrder(node->right);
  }

  // MARK: in order
  void IterInOrder() {}
  void IterInOrder(Node* node) {}
  void RecurInOrder() {
    std::cout << "--In Order--\n\t";
    RecurInOrder(root_);
    std::cout << '\n';
  }
  void RecurInOrder(Node* node) {
    if (node == nullptr) return;
    RecurInOrder(node->left);
    Visit(node);
    RecurInOrder(node->right);
  }

  // MARK: post order
  void IterPostOrder() {}
  void IterPostOrder(Node* node) {}
  void RecurPostOrder() {
    std::cout << "--Post Order--\n\t";
    RecurPostOrder(root_);
    std::cout << '\n';
  }
  void RecurPostOrder(Node* node) {
    if (node == nullptr) return;
    RecurPostOrder(node->left);
    RecurPostOrder(node->right);
    Visit(node);
  }

  // MARK: level order
  void LevelOrder() {
    std::cout << "--Level Order--\n\t";
    LevelOrder(root_);
    std::cout << '\n';
  }
  void LevelOrder(Node* node) {
    if (node == nullptr) return;
    std::queue<Node*> queue;

    queue.push(node);

    while (!queue.empty()) {
      Node* current = queue.front();
      queue.pop();

      if (current->left != nullptr) queue.push(current->left);
      if (current->right != nullptr) queue.push(current->right);

      Visit(current);
    }
  }

  int Height() { return Height(root_); }
  int Height(Node* node) {
    if (node == nullptr) return 0;

    return 1 + std::max(Height(node->left), Height(node->right));
  }

  void Print2D();
  void PrintLevel(int n);
  void DisplayLevel(Node* p, int lv, int d);

 protected:
  Node* root_ = nullptr;
};

// template <typename K, typename V>
// class AVL : public BinarySearchTree<K, V> {};

// https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
template <typename K, typename V>
void Tree<K, V>::Print2D() {
  using namespace std;
  cout << "Height = " << Height() << endl;
  int i = 0;
  while (i < Height()) {
    PrintLevel(i);
    i++;
    cout << endl;
  }
  cout << endl;
}

template <typename K, typename V>
void Tree<K, V>::PrintLevel(int n) {
  using namespace std;
  Node* temp = root_;
  int val = (int)pow(2.0, Height() - n + 1.0);
  cout << setw(val) << "";
  DisplayLevel(temp, n, val);
}

template <typename K, typename V>
void Tree<K, V>::DisplayLevel(Node* p, int lv, int d) {
  using namespace std;
  int disp = 2 * d;
  if (lv == 0) {
    if (p == NULL) {
      cout << "   ";
      cout << setw(disp - 3) << "";
      return;
    } else {
      int result = ((p->item.key <= 1) ? 1 : (int)log10(p->item.key) + 1);
      cout << " " << p->item.key << p->item.value << " ";
      cout << setw(static_cast<streamsize>(disp) - result - 2) << "";
    }
  } else {
    if (p == NULL && lv >= 1) {
      DisplayLevel(NULL, lv - 1, d);
      DisplayLevel(NULL, lv - 1, d);
    } else {
      DisplayLevel(p->left, lv - 1, d);
      DisplayLevel(p->right, lv - 1, d);
    }
  }
}
