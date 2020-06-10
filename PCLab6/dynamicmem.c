#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void read_vector(int *n, int **v) {
    int i;
    scanf("%d", n);
    *v = (int *)malloc((*n) * sizeof(int));
    for (i = 0; i < (*n); i++) {
        scanf("%d", &(*v)[i]);
    }
}

void write_vector(int n, int *v) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void read_matrix(int *n, int **m, int ***mat) {
    int i, j;
    read_vector(n, m);
    (*mat) = (int **)malloc(*n * sizeof(int*));
    for (i = 0; i < (*n); i++) {
        (*mat)[i] = (int *)malloc((*m)[i] * sizeof(int));
        for (j = 0; j < (*m)[i]; j++) {
            scanf("%d", &(*mat)[i][j]);
        }
    }
}

void write_matrix(int n, int *m, int **mat) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m[i]; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void dynamic_write(int *max, int *n, int **x) {
    int i = 0, j = 0;
    while (i < *n) {
        if (*n >= *max) {
            *x = (int *)realloc(*x, ((*max)*2)*sizeof(int));
        }
        *max = *max*2;
        i++;
    }
    *max = *n;
}

void dynamic_erase(int *max, int *n, int **x) {
    while (*n <= 0.3*(*max)) {
        *x = (int *)realloc(*x, ((*max)/2)*sizeof(int));
    }
}

int main() {
    int n, *v, *m, **mat, *x, i, j, max;
    read_vector(&n, &v);
    write_vector(n, v);
    read_matrix(&n, &m, &mat);
    write_matrix(n, m, mat);
    x = (int *)malloc(sizeof(int));
    max = 1;
    srand(time(0));
    for (i = 0; i < 100; i++) {
        int nr = rand() % 10000;
        dynamic_write(&max, &nr, &x);
        dynamic_erase(&max, &nr, &x);
    }
    return 0;
}
