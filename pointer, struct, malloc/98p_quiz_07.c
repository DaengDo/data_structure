#include <stdio.h>
// 복소수를 구조체로 표현하고, 복소수 a와 b를 받아서 a+b 계산하는 함수 작성
typedef struct complexTag {
  int real;
  float imaginary;
} Complex;

Complex add_complex(Complex a, Complex b);

int main () {
  Complex a = { 10, 1.0 }, b = { 3, 2.0 };

  Complex c = add_complex(a, b);

  printf("The result is: %d + %fi\n", c.real, c.imaginary);

  return 0;
}

Complex add_complex (Complex a, Complex b) {
  Complex result;

  result.real = a.real + b.real;
  result.imaginary = a.imaginary + b.imaginary;

  return result;
}