#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SWAP(a, b, c) char aux[c]; memcpy(aux, a, c); memcpy(a, b, c); memcpy(b, aux, c);

int intcomp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(int argc, char *argv[]) {
    int i, j;
    printf("%d\n", argc - 1);
    for (i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    printf("\n");
    if (argc < 3) {
        printf("Eroare!\n");
        return 0;
    }
    for (i = 1; i < argc; i++) {
        for (j = 0; j < strlen(argv[i]); j++) {
            if (isdigit(argv[i][j]) == 0) {
                printf("Eroare!\n");
                return 0;
            }
        }
    }
    int val[argc];
    for (i = 0; i < argc - 1; i++) {
        val[i] = atoi(argv[i + 1]);
    }
    qsort(val, argc - 1, sizeof(int), intcomp);
    for (i = 0; i < argc - 1; i++) {
        printf("%d ", val[i]);
    }
    printf("\n");
    for (i = 0; i < argc - 1; i++) {
        val[i] = atoi(argv[i + 1]);
    }
    #ifdef SORT_ASC
    for ( i = 0; i < argc; i++) {
        for ( j = 0; j < argc - 2; j++) {
            if (val[j] > val[j + 1]) {
                SWAP(&val[j], &val[j + 1], sizeof(int));
            }
        }
    }
    for (i = 0; i < argc - 1; i++) {
        printf("%d ", val[i]);
    }
    printf("\n");
    #else
    #ifdef SORT_DESC
    for (i = 0; i < argc; i++) {
        for ( j = 0; j < argc - 2; j++) {
            if (val[j] < val[j + 1]) {
                SWAP(&val[j], &val[j + 1], sizeof(int));
            }
        }
    }
    for (i = 0; i < argc - 1; i++) {
        printf("%d ", val[i]);
    }
    printf("\n");
    #else
    printf("Eroare!");
    #endif
    #endif
    return 0;
}
