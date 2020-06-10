#include <stdio.h>

void address_swap(int **pa, int **pb) {
    int *aux;
    aux = *pa;
    *pa = *pb;
    *pb = aux;
}

int main() {
    int a, b, *pa, *pb;
    scanf("%d %d", &a, &b);
    pa = &a;
    pb = &b;
    printf("%x %x\n", pa, pb);
    address_swap(&pa, &pb);
    printf("%x %x\n", pa, pb);
    return 0;
}
