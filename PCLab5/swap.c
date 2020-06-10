#include <stdio.h>

void my_swap(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    my_swap(&a, &b);
    printf("%d %d\n", a, b);
    return 0;
}
