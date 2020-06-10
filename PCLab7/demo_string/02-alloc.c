#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // se citeste dimensiune unui sir de caractere
    // pentru a se prealoca dinamic memoria
    int n;
    scanf("%d", &n);

    // se va aloca loc si pentru '\0'
    char *s = (char *) malloc((n + 1) * sizeof(char));
    if (s == NULL) {
        return -1;
    }
    scanf("%s", s);
    printf("%s (strlen => %lu)\n", s, strlen(s));

    free(s);
    return 0;
}

// gcc 02-alloc.c -o 02-alloc && ./02-alloc
// gigel
// gigel (strlen => 5)
