#include "BinarySearchTree.h"

int main() {
  BinarySearchTree<int, char> bst;

  for (auto i : {5, 3, 7, 1, 4, 6, 8}) {
    bst.RecurInsert(Item<int, char>{i, (char)('A' + i)});
  }

  bst.Print2D();

  return 0;
}