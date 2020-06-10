#include <stdio.h>

#define NMAX 100

void read(int *dim, int *v) {
    int i;
    scanf("%d", dim);
    for (i = 0; i < *dim; i++) {
        scanf("%d", &v[i]);
    }
}

int main() {
    int dim, v[NMAX], i;
    read(&dim, v);
    for (i = 0; i < dim; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}
