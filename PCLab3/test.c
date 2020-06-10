#include<stdio.h>

void sum(int a, int b, int s) {
  s = a + b;
  printf("Suma este %d\n", s);
}

int main() {
  int s;
  sum(2, 3, s);
  return 0;
}
