#include <stdio.h>
#include <stdlib.h>

// 크기가 n인 배열 array에서 임의의 인덱스(0 ~ n-1)의 값 삭제하고 한 칸씩 당기는 함수 delete() 만들기

void print_array(int* arr, int arr_size);
int* delete(int* arr, int arr_size, int delete_idx);

int main () {
  int input_size;
  printf("배열의 크기를 입력: ");
  scanf("%d", &input_size);
  if (input_size < 0 || input_size > 100) exit(1); // 입력은 0~99로 가정

  int* array = malloc(input_size * sizeof(int));
  if (array == NULL) exit(1); // 힙 메모리 부족

  // 배열 초기화
  for (int i = 0; i < input_size; i++) {
    array[i] = i;
  }

  print_array(array, input_size); // 생성한 배열 printf

  int input_location;
  printf("삭제할 위치: ");
  scanf("%d", &input_location);
  if (input_location - 1 > input_size) exit(1);

  int* deleted_arr = delete(array, input_size, input_location); // 요소 삭제한 새로운 배열 반환
  print_array(deleted_arr, input_size - 1); // delete한 배열 printf

  free(array);
  free(deleted_arr);

  return 0;
}

int* delete(int* arr, int arr_size, int delete_idx) {
  int* result_arr = malloc((arr_size - 1) * sizeof(int));

  result_arr[arr_size - 2] = arr[arr_size - 1]; // 마지막 인덱스 생성해두기
  for (int i = 0; i < arr_size - 1; i++) {
    if (i < delete_idx) {
      result_arr[i] = arr[i];
      continue;
    }
    if (i == delete_idx) {
      continue;
    }
    result_arr[i - 1] = arr[i];
  }

  return result_arr;
}

void print_array(int* arr, int arr_size){
  printf("배열 print { ");
  for (int i = 0; i < arr_size; i++) {
    if (i == arr_size - 1) {
      printf("%d ", arr[i]);
      break;
    };
    printf("%d, ", arr[i]);
  }
  printf("}\n");
}