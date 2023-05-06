#include <stdio.h>

int main () {
  // ADT
  int arr[6] = { 0, 1, 2, 3, 4, 5 }; // create()
  arr[1] = 100; // set()
  arr[1]; // get()

  int* ptr_arr1 = &arr[1];

  // index 0 주소
  printf("&arr: \t\t%p\n", &arr);
  printf("&arr[0]: \t%p\n", &arr[0]);

  printf("\n");

  // index 1 주소
  printf("&arr[1]: \t%p\n", &arr[1]);
  printf("&arr[0] + 1: \t%p\n", &arr[0] + 1);

  return 0;
}