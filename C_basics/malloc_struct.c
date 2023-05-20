#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentTag {
  char name[10];
  int age;
  double gpa;
} student;

int main (void) {
  student *s;

  s = (student *) malloc(sizeof(student));

  if (s == NULL) {
    fprintf(stderr, "메모리 부족 ㅜㅜ\n");
    exit(1);
  }

  strcpy(s->name, "kang");
  s->age = 20;
  s->gpa = 1.0;

  printf("s.name: %s\ns.age: %d\ns.gpa: %lf\n", s->name, s->age, s->gpa);

  free(s);

  return 0;
}