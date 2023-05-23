#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty () {
  return top == -1;
}

int is_full () {
  return top == (MAX_STACK_SIZE - 1);
}

element peek () {
  if (is_empty()) {
    fprintf(stderr, "스택 비어있어서 top이 없음!\n");
    exit(1);
  }
  return stack[top];
}

void push (element item) {
  if (is_full()) {
    fprintf(stderr, "스택 꽉 차서 더 못넣음!\n");
    exit(1);
  }

  stack[++top] = item;
}

element pop () {
  if (is_empty()) {
    fprintf(stderr, "스택 비어서 삭제를 못함!\n");
    exit(1);
  }

  return stack[top--];
}

int main () {
  push(1);
  push(2);
  push(3);

  printf("%d\n", peek());

  printf("%d\n", pop());
  printf("%d\n", pop());
  printf("%d\n", pop());

  printf("%d\n", peek());

  return 0;
}