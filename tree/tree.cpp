#include <iostream>

template<typename T>
class BinaryTree {
  public:
    struct Node {
      T item = T();
      Node* left = nullptr;
      Node* right = nullptr;
    };

    BinaryTree() {}

    BinaryTree(Node* root) {
      root_ = root;
    }

    ~BinaryTree(){
      DeleteTree(root_);
    }

    void DeleteTree (Node* node) {
      if (!node) return;
      DeleteTree(node->left);
      DeleteTree(node->right);
      delete node;
    }

    void Visit(Node* node) {
      std::cout << ' ' <<node->item << ' ' ;
    }

    void PreOrder () {
      RecurPreOrder(root_);
      std::cout << '\n';
    }

    void RecurPreOrder (Node* node) {
      if (!node) return;
      Visit(node);
      RecurPreOrder(node->left);
      RecurPreOrder(node->right);
    }

    void InOrder () {
      RecurInOrder(root_);
      std::cout << '\n';
    }

    void RecurInOrder (Node* node) {
      if (!node) return;
      RecurInOrder(node->left);
      Visit(node);
      RecurInOrder(node->right);
    }

    void PostOrder () {
      RecurPostOrder(root_);
      std::cout << '\n';
    }

    void RecurPostOrder (Node* node) {
      if (!node) return;
      RecurPostOrder(node->left);
      RecurPostOrder(node->right);
      Visit(node);
    }

    int Height () {
      return Height(root_);
    }

    int Height (Node* node) {
      if (!node) return 0;
      return 1 + std::max(Height(node->left), Height(node->right));
    }

    void LevelOrder () {}

  private:
    Node* root_ = nullptr;
};

int main () {
  // 1 2 3 4 5 6
  BinaryTree<int>::Node* n1 = new BinaryTree<int>::Node{ 1, nullptr, nullptr };
  BinaryTree<int>::Node* n3 = new BinaryTree<int>::Node{ 3, nullptr, nullptr };
  BinaryTree<int>::Node* n2 = new BinaryTree<int>::Node{ 2, n1, n3 };
  BinaryTree<int>::Node* n5 = new BinaryTree<int>::Node{ 5, nullptr, nullptr };
  BinaryTree<int>::Node* n7 = new BinaryTree<int>::Node{ 7, nullptr, nullptr };
  BinaryTree<int>::Node* n6 = new BinaryTree<int>::Node{ 6, n5, n7 };
  BinaryTree<int>::Node* n4 = new BinaryTree<int>::Node{ 4, n2, n6 };

  BinaryTree<int> binaryTree(n4);

  binaryTree.PreOrder();
  binaryTree.InOrder();
  binaryTree.PostOrder();

  return 0;
}