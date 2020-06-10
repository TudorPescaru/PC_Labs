#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studenti {
        char *nume;
        char grupa[6];
        double medie;
} studenti;

int cmp(const void *p, const void *q) {
        studenti x = *(studenti *)p, y = *(studenti *)q;
        return strcmp(x.nume, y.nume);
}

int main() {
        studenti stud[100];
        int n, i, j;
        char c[30];
        scanf("%d", &n);
        fgets(c, 30, stdin);
        for (i = 0; i < n; i++) {
                fgets(c, 30, stdin);
                c[strlen(c) - 1] = 0;
                stud[i].nume = (char *)malloc(strlen(c)+1 * sizeof(char));
                strcpy(stud[i].nume, c);
                fgets(stud[i].grupa, 6, stdin);
                stud[i].grupa[strlen(stud[i].grupa) - 1] = 0;
                scanf("%lf", &stud[i].medie);
                fgets(c, 30, stdin);
        }
        qsort(stud, n, sizeof(stud[0]), cmp);
        for (i = 0; i < n; i++) {
                printf("%s, %s, %.2f\n", stud[i].nume, stud[i].grupa, stud[i].medie);
        }
        return 0;
}