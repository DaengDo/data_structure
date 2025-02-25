#include "tree.h"

int main() {
  using Node = Tree<int, char>::Node;

  // Node* n7 = new Node{{7, 'B'}, nullptr, nullptr};
  // Node* n5 = new Node{{5, 'C'}, nullptr, nullptr};
  // Node* n6 = new Node{{6, 'D'}, n5, n7};
  // Node* n1 = new Node{{1, 'E'}, nullptr, nullptr};
  // Node* n3 = new Node{{3, 'F'}, nullptr, nullptr};
  // Node* n2 = new Node{{2, 'G'}, n1, n3};
  // Node* n4 = new Node{{4, 'H'}, n2, n6};

  Node* n7 = new Node{{7, 'B'}, nullptr, nullptr};
  Node* n5 = new Node{{5, 'C'}, nullptr, nullptr};
  Node* n4 = new Node{{4, 'H'}, n7, n5};
  Node* n9 = new Node{{9, 'D'}, nullptr, nullptr};
  Node* n2 = new Node{{2, 'F'}, n4, n9};
  Node* n8 = new Node{{8, 'G'}, nullptr, nullptr};
  Node* n6 = new Node{{6, 'G'}, nullptr, nullptr};
  Node* n3 = new Node{{3, 'G'}, n8, n6};
  Node* n1 = new Node{{1, 'E'}, n2, n3};

  Tree<int, char> tree(n1);

  tree.Print2D();

  tree.RecurPreOrder();
  tree.RecurInOrder();
  tree.RecurPostOrder();
  tree.LevelOrder();

  return 0;
}