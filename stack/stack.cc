#include <iostream>
#include "./stack.hh"

int main () {
  Stack<int> stack1;

  for (int i = 0; i < 3; i ++){    
    stack1.Push(i);
  }

  for (int i = 0; i < 3; i ++){
    const int item = stack1.Top();
    std::cout << item << std::endl;
    stack1.Pop();
  }

  Stack<char> stack2;

  const char str[] = "Hello, World!";
  const int size = sizeof(str) - 1;

  for (int i = 0; i < size; i++) {
    stack2.Push(str[i]);
  }

  while (!stack2.IsEmpty()) {
    std::cout << stack2.Top();
    stack2.Pop();
  }

  return 0;
}