#include "tree.h"

int main() {
  using Node = Tree<int, char>::Node;

  Node* n7 = new Node{{7, 'B'}, nullptr, nullptr};
  Node* n5 = new Node{{5, 'C'}, nullptr, nullptr};
  Node* n6 = new Node{{6, 'D'}, n5, n7};
  Node* n1 = new Node{{1, 'E'}, nullptr, nullptr};
  Node* n3 = new Node{{3, 'F'}, nullptr, nullptr};
  Node* n2 = new Node{{2, 'G'}, n1, n3};
  Node* n4 = new Node{{4, 'H'}, n2, n6};

  Tree<int, char> tree(n4);

  tree.Print2D();

  tree.RecurPreOrder();
  tree.RecurInOrder();
  tree.RecurPostOrder();
  tree.LevelOrder();

  return 0;
}