#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE 10

int main(void){
  int* p;

  p = (int *)malloc(SIZE * sizeof(int));
  
  if (p == NULL) {
    fprintf(stderr, "메모리 부족 ㅠㅠ");
    exit(1);
  }

  int i = 0;
  while(i++ < SIZE) {
    p[i] = i;
    printf("%d\n", p[i]);
  }

  free(p);

  return 0;
}