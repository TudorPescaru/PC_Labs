#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, *v, x;
    FILE *f = fopen("b.in", "w");
    scanf("%d", &n);
    v = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        fprintf(f, "%d ", x);
    }
    fclose(f);
    f = fopen("b.in", "r");
    i = 0;
    while(fscanf(f, "%d", &x) == 1) {
        printf("%d ", x);
        v[i] = x;
        i++;
    }
    printf("\n");
    fclose(f);
    f = fopen("bb.in", "wb");
    fwrite(v, sizeof(int), n, f);
    fclose(f);
    free(v);
    n = 0;
    f = fopen("bb.in", "rb");
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    n = n / sizeof(int);
    printf("%d\n", n);
    fseek(f, 0, SEEK_SET);
    v = (int *)calloc(n, sizeof(int));
    fread(v, sizeof(int), n, f);
    for (i = 0; i < n ; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    free(v);
}
