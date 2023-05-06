#include <stdio.h>

int main () {
  // 실제 메모리에는 선형으로 저장된다.
  int arr[2][3] = {
    { 0, 1, 2 },
    { 3, 4, 5 }
  };

  int i, j;

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      printf("arr[%d][%d]: %d\taddress: %p\n", i, j, arr[i][j], &arr[i][j]);
    } 
  }

  return 0;
}