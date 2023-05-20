#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INDEX 10
// 크기가 10인 배열 선언해서 2^0 ~ 2^9 까지 저장하고 출력하기
int main(void) {
  int* two;

  two = (int*)malloc(sizeof(int[MAX_INDEX]));

  for (int i = 0; i < MAX_INDEX; i++) {
    two[i] = pow(2, i);
    printf("%d\n", two[i]);
  }

  free(two);

  return 0;
}