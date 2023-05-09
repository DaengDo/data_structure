// 단순 2차원 배열로 행렬을 표현할 때, 전치 행렬 구하기
#include <stdio.h>
#define ROWS 3
#define COLS 3

int main () {
  int matrix[ROWS][COLS] = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };

  int i, j, temp;
  // 로그
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      printf("%d, ", matrix[i][j]);
    }
    printf("\n");
  }
  // 전치 행렬 변환
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      if (i == j) break;
      temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }

  printf("\n");
  // 변환한 행렬 로그
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      printf("%d, ", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}
