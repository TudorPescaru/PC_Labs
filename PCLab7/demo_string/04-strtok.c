#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 1000

int main() {
    // citire propozitie de la tastatura
    char p[NMAX];
    fgets(p, NMAX, stdin);
    p[ strlen(p) - 1 ] = '\0';

    // vom folosi strtok sa spargem propozitia in cuvinte
    // numaram cate cuvinte am gasit
    int n = 0;

    char *delim = " .:,?\n\t;";
    char *token = strtok(p, delim);
    while (token) {
        printf("token = \"%s\"\n", token);

        ++n;
        token = strtok(NULL, delim);
    }

    printf("%d cuvinte gasite\n", n);

    return 0;
}

// gcc 04-strtok.c -o 04-strtok && ./04-strtok
// Ana are mere, pere si altele.
// token = "Ana"
// token = "are"
// token = "mere"
// token = "pere"
// token = "si"
// token = "altele"
// 6 cuvinte gasite
