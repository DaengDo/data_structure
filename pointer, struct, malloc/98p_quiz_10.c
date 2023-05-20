#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 1개의 정수와 최대 크기가 20인 문자열로 이뤄진 구조체 저장할 수 있도록 동적 메모리 할당 받고,
// 정수 100과 문자열 "just testing" 저장하고 메모리 반납하기

typedef struct {
    int number;
    char str[20];
} Test;

int main() {
  Test* myStruct = malloc(sizeof(Test));
  if (myStruct == NULL) exit(1);

  myStruct->number = 100;
  strncpy(myStruct->str, "just testing", sizeof(myStruct->str));

  printf("숫자: %d\n", myStruct->number);
  printf("문자: %s\n", myStruct->str);

  free(myStruct);

  return 0;
}
