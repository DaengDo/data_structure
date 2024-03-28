#include <iostream>
#include "./stack.hh"

Stack<char> tower[3];

void PrintTowers () {
  std::cout << "Towers" << std::endl;
  for (int i = 0; i < 3; i++){
    std::cout << i << ": ";
    tower[i].Print();
  }
}

int main () {
  int num_disks = 3;
  for (int i = 0; i < num_disks; i++) {
    tower[0].Push('A' + i);
  }

  PrintTowers();

  return 0;
}