#include <stdio.h>
// person 구조체 만들기
struct person {
  char name[20];
  int age;
  float wage;
};

int main (void) {
  struct person p1 = {"asdf", 123, 3.14};

  printf("name: %s\nage: %d\nwage: %f", p1.name, p1.age, p1.wage);

  return 0;
}