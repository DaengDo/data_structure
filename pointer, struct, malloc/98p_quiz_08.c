#include <stdio.h>
#include <stdlib.h>

// 크기가 n인 배열 array에서 임의의 위치 loc에 정수 value 삽입하는 함수 insert() 만들기
// loc에 숫자 넣어지면 그 뒤 숫자는 한 칸씩 밀려야됨

void print_array(int* arr, int arr_size);
int* insert(int* arr, int arr_size, int insert_idx, int insert_val);

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

  int input_location, input_value;
  printf("위치: ");
  scanf("%d", &input_location);
  printf("값: ");
  scanf("%d", &input_value);
  if (input_location - 1 > input_size) exit(1);

  int* inserted_arr = insert(array, input_size, input_location, input_value); // 새로운 배열 반환
  print_array(inserted_arr, input_size + 1); // insert한 배열 printf

  free(array);
  free(inserted_arr);

  return 0;
}

int* insert(int* arr, int arr_size, int insert_idx, int insert_val) {
  int* result_arr = malloc((arr_size + 1) * sizeof(int));
  int temp = arr[insert_idx];

  for (int i = 0; i < arr_size + 1; i++) {
    if (i < insert_idx) {
      result_arr[i] = arr[i];
      continue;
    }
    if (i == insert_idx) {
      result_arr[i] = insert_val;
      result_arr[i + 1] = arr[i];
      continue;
    }
    result_arr[i + 1] = arr[i];    
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