#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

typedef int (*cmp_t)(const void*, const void*);

void sort(void* v, size_t num, size_t size, cmp_t cmp) {
    char s[size];
    for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
            if (cmp((v + i * size), (v + j * size)) > 0) {
                memcpy(s, (v + j * size), size);
                memcpy((v + j * size), (v + i * size), size);
                memcpy((v + i * size), s, size);
            }
        }
    }
}

int cmp_int(const void* first, const void* second) {
    int f = *(int *) first;
    int s = *(int *) second;
    if (f < s) {
        return -1;
    }
    if (f > s) {
        return +1;
    }
    return 0;
}

int cmp_db(const void* first, const void* second) {
    double f = *(double *) first;
    double s = *(double *) second;
    if (f < s) {
        return -1;
    }
    if (f > s) {
        return +1;
    }
    return 0;
}

int cmp_ch(const void* first, const void* second) {
    return strcmp(first, second);
}

int cmp_chstar(const void* first, const void* second) {
    char* f = *(char **) first;
    char* s = *(char **) second;
    if (f < s) {
        return -1;
    }
    if (f > s) {
        return +1;
    }
    return 0;
}

int main() {
    int *v, n;
    scanf("%d", &n);
    v = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v, n, sizeof(int), cmp_int);
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    free(v);

    double *w, m;
    scanf("%lf", &m);
    w = (double*)malloc(m * sizeof(double));
    for (int i = 0; i < m; i++) {
        scanf("%lf", &w[i]);
    }
    sort(w, m, sizeof(double), cmp_db);
    for (int i = 0; i < m; i++) {
        printf("%.2lf ", w[i]);
    }
    printf("\n");
    free(w);

    char *c;
    int l;
    scanf("%d", &l);
    c = (char*)malloc(l * sizeof(char));
    for (int i = 0; i < m; i++) {
        scanf("%c", &c[i]);
    }
    sort(w, m, sizeof(double), cmp_db);
    for (int i = 0; i < m; i++) {
        printf("%c ", c[i]);
    }
    printf("\n");
    free(c);
    return 0;
}
