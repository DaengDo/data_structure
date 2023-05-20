#include <stdio.h>
// typedef 사용해서 int형 real과 float형 imaginary 맴버로 갖는 complex 구조체 만들고,
// c1, c2 변수 초기화하기
typedef struct complexTag {
  int real;
  float imaginary;
} complex;

int main () {
  complex c1, c2 = { 10, 1.0 };
  c1.real = 1;
  c1.imaginary = 2.0;

  return 0;
}