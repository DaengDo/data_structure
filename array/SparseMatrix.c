#include <stdio.h>
#define MAX_TERMS 100

// 희소 행렬 (0많은 행렬)

// {
//   {0, 0, 0, 7, 0, 0},
//   {9, 0, 0, 0, 0, 8},
//   {0, 0, 0, 0, 0, 0},
//   {6, 5, 0, 0, 0, 0},
//   {0, 0, 0, 0, 0, 1},
//   {0, 0, 2, 0, 0, 0},
// };

typedef struct {
  int row;
  int col;
  int value;
} element;

typedef struct SparseMatrix {
  element data[MAX_TERMS];
  int rows;
  int cols;
  int terms; // 항 몇개 인지
} SparseMatrix;

int main () {
  SparseMatrix my_matrix = {{
      {0, 3, 7}, // 0,3 의 값 7
      {1, 0, 9}, // 1,0 의 값 9
      {1, 5, 8}, // 이하 생략
      {3, 0, 6},
      {3, 1, 5},
      {4, 5, 1},
      {5, 2, 2}
    },
    6,
    6,
    7
  };

  SparseMatrix transpose;
  transpose = matrix_transpose(my_matrix);

  return 0;
}