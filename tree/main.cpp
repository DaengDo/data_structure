#include <iostream>
#include <cstring>
#include <cassert>
#include <queue>
#include <stack>

enum OrderType {
  RECURSIVE,
  ITERATIVE,
};

template<typename T>
class BinaryTree {
  public:
    struct Node {
      T item = T();
      Node* left = nullptr;
      Node* right = nullptr;
    };

    BinaryTree(Node* node = new Node({ T(), nullptr, nullptr })) {
      root_ = node;
    }

    ~BinaryTree() {
      DeleteTree(root_);
    }

    void DeleteTree (Node* node) {
      if (!node) return;
      DeleteTree(node->left);
      DeleteTree(node->right);
      delete node;
    }

    void Visit (Node* node) {
      std::cout << node->item << std::endl;
    }

    void PreOrder (OrderType type = OrderType::RECURSIVE) {
      if (type == OrderType::RECURSIVE) {
        RecurPreOrder(root_);
      } else {
        IterPreOrder(root_);
      }
    }

    void RecurPreOrder (Node* node) {
      if (!node) return;
      Visit(node);
      RecurPreOrder(node->left);
      RecurPreOrder(node->right);
    }

    void IterPreOrder (Node* node) {
      std::stack<Node*> s;
      s.push(node);
      while (!s.empty()) {
        Node* top = s.top();
        Visit(top);
        s.pop();
        if (top->right) s.push(top->right);
        if (top->left) s.push(top->left);
      }
    }

    void InOrder (OrderType type = OrderType::RECURSIVE) {
      if (type == OrderType::RECURSIVE) {
        RecurInOrder(root_);
      } else {
        IterInOrder(root_);
      }
    }

    void RecurInOrder (Node* node) {
      if (!node) return;
      RecurInOrder(node->left);
      Visit(node);
      RecurInOrder(node->right);
    }

    void IterInOrder (Node* node) {
      std::stack<Node*> s;
      bool isLeftVisited = false;
      s.push(node);
      while(!s.empty()) {
        Node* top = s.top();
        if (top->left && !isLeftVisited) {
          s.push(top->left);
          isLeftVisited = false;
          continue;
        }
        Visit(top);
        if (!isLeftVisited) isLeftVisited = true;
        s.pop();
        if (top->right) {
          s.push(top->right);
          isLeftVisited = false;
        }
      }
    }

    void PostOrder (OrderType type = OrderType::RECURSIVE) {
      if (type == OrderType::RECURSIVE) {
        RecurPostOrder(root_);
      } else {
        IterPostOrder(root_);
      }
    }

    void RecurPostOrder (Node* node) {
      if (!node) return;
      RecurPostOrder(node->left);
      RecurPostOrder(node->right);
      Visit(node);
    }

    void IterPostOrder (Node* node) {
      std::stack<Node*> s1;
      std::stack<Node*> s2;
      s1.push(node);
      while (!s1.empty()) {
        Node* top = s1.top();
        s1.pop();
        s2.push(top);
        if (top->left) s1.push(top->left);
        if (top->right) s1.push(top->right);
      }

      while (!s2.empty()) {
        Visit(s2.top());
        s2.pop();
      }
    }

    void LevelOrder (Node* node = nullptr) {
      std::queue<Node*> q;
      if (!node) node = root_;
      q.push(node);
      while (!q.empty()) {
        Node* front = q.front();
        Visit(front);
        if (front->left) q.push(front->left);
        if (front->right) q.push(front->right);
        q.pop();
      }
    }

  private:
    Node* root_ = nullptr;
};

int main () {
  using Node = BinaryTree<char>::Node;
  Node* nodeD = new Node({ 'D', nullptr, nullptr });
  Node* nodeE = new Node({ 'E', nullptr, nullptr });
  Node* nodeF = new Node({ 'F', nullptr, nullptr });
  Node* nodeG = new Node({ 'G', nullptr, nullptr });
  Node* nodeB = new Node({ 'B', nodeD, nodeE });
  Node* nodeC = new Node({ 'C', nodeF, nodeG });
  Node* nodeA = new Node({ 'A', nodeB, nodeC });

  BinaryTree<char> tree(nodeA);

  std::cout << "PreOrder - RECURSIVE" << std::endl;
  tree.PreOrder(OrderType::RECURSIVE);
  std::cout << "PreOrder - ITERATIVE" << std::endl;
  tree.PreOrder(OrderType::ITERATIVE);

  std::cout << "InOrder - RECURSIVE" << std::endl;
  tree.InOrder(OrderType::RECURSIVE);
  std::cout << "InOrder - ITERATIVE" << std::endl;
  tree.InOrder(OrderType::ITERATIVE);

  std::cout << "PostOrder - RECURSIVE" << std::endl;
  tree.PostOrder(OrderType::RECURSIVE);
  std::cout << "PostOrder - ITERATIVE" << std::endl;
  tree.PostOrder(OrderType::ITERATIVE);

  std::cout << "LevelOrder" << std::endl;
  tree.LevelOrder();

  return 0;
}