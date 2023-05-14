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

void print_matrix (SparseMatrix input_matrix) {
  int i, j;
  for (i = 0; i < input_matrix.terms; i ++) {
    printf("{%d, %d, %d}\n", input_matrix.data[i].row, input_matrix.data[i].col, input_matrix.data[i].value);    
  }

  printf("print done\n");
}

SparseMatrix matrix_transpose(SparseMatrix input_matrix) {
  SparseMatrix output_matrix;

  output_matrix.cols = input_matrix.cols;
  output_matrix.rows = input_matrix.rows;
  output_matrix.terms = input_matrix.terms;

  int i, j;
  element temp;

  // input_matrix를 전치행렬로 변환한 새로운 output_matrix 생성
  for (i = 0; i < input_matrix.terms; i++) {
    output_matrix.data[i].col = input_matrix.data[i].row;
    output_matrix.data[i].row = input_matrix.data[i].col;
    output_matrix.data[i].value = input_matrix.data[i].value;
  }

  // output_matrix 행 기준 버블 정렬
  for (i = 0; i < output_matrix.terms; i++) {
    for(j = 0; j < output_matrix.terms - 1 - i; j++) {
      if (output_matrix.data[j].row > output_matrix.data[j + 1].row) {
        temp = output_matrix.data[j];
        output_matrix.data[j] = output_matrix.data[j + 1];
        output_matrix.data[j + 1] = temp;
      }
    }
  }

  // output_matrix 열 기준 버블 정렬
  for (i = 0; i < output_matrix.terms; i++) {
    for(j = 0; j < output_matrix.terms - 1 - i; j++) {
      if (output_matrix.data[j].row != output_matrix.data[j + 1].row) {
        // 행이 동일하지 않으면 정렬할 대상이 아님 (이미 행 정렬은 위에서 함)
        continue;
      }

      if (output_matrix.data[j].col > output_matrix.data[j + 1].col) {
        temp = output_matrix.data[j];
        output_matrix.data[j] = output_matrix.data[j + 1];
        output_matrix.data[j + 1] = temp;
      }
    }
  }

  return output_matrix;
}

int main () {
  SparseMatrix my_matrix = {{
      {0, 3, 7}, // (0,3) 의 값 7
      {1, 0, 9}, // (1,0) 의 값 9
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

  print_matrix(my_matrix);
  print_matrix(transpose);

  return 0;
}