#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 1000

int main() {
    // se citeste o propozitie de la tastatura
    char p[NMAX];
    fgets(p, NMAX, stdin);
    p[ strlen(p) - 1 ] = '\0'; // elmininam '\n'

    // se citeste un alt cuvant
    char word[NMAX];
    scanf("%s", word);

    // se va afisa toate aparitiile lui word in p
    char *str = strstr(p, word);
    while (str) {
        printf("pos = %d\n", (int) (str - p));
        str = strstr(str + 1, word);
    }

    return 0;
}


// gcc 03-strfind.c -o strfind && ./03-strfind
// Ana are mere, are pere, are de toate ...
// are
// pos = 4
// pos = 14
// pos = 24
