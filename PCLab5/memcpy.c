#include <stdio.h>

#define NMAX 100

void my_memcpy(void *dst, const void *src, int num) {
    char *pdst = (char *)dst;
    const char *psrc = (const char *)src;
    while (num) {
        *(pdst++) = *(psrc++);
        num--;
    }
}

int main() {
    int a, b, k, n;
    double x, y;
    int i[NMAX], j[NMAX];
    char c[NMAX], s[NMAX];
    scanf("%d", &a);
    scanf("%lf", &x);
    scanf("%d", &n);
    for (k = 0; k < n; k++) {
        scanf("%d", &i[k]);
    }
    scanf("%s", c);
    my_memcpy(&b, &a, sizeof(a));
    printf("%d\n", b);
    my_memcpy(&y, &x, sizeof(x));
    printf("%f\n", y);
    my_memcpy(j, i, sizeof(i));
    for (k = 0; k < n; k++) {
        printf("%d ", j[k]);
    }
    printf("\n");
    my_memcpy(s, c, sizeof(c));
    printf("%s\n", s);
}
