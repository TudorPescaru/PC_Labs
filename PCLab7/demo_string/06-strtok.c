// la fel ca 04-strtok, insa stocarea se va face intr-un vector
// vectorul este alocat dinamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 1000
#define WMAX 100

int main() {
    // citim fraza
    char p[NMAX];
    fgets(p, NMAX, stdin);

    // in words salvam cuvintele, cu n le numaram
    int n = 0;
    char **words = NULL;

    char *delim = " .:,?\n\t;";
    char *token = strtok(p, delim);
    while (token) {
        // dorim sa folosim words[n]
        // reallocam vectorul a.i. sa existe elementul respectiv
        words = (char**) realloc(words, (n + 1) * sizeof(char *));
        if (!words) {
            // malloc failed
            return -1;
        }

        words[n] = (char *) strdup(token);
        if (!words[n]) {
            // strdup -> malloc -> return NULL
            return -1;
        }

        ++n;
        token = strtok(NULL, delim);
    }

    printf("n = %d\n", n);
    for (int i = 0; i < n; ++i) {
        printf("%s\n", words[i]);
        free(words[i]);
    }
    free(words);

    return 0;
}

// gcc 06-strtok.c -o 06-strtok && ./06-strtok
// Ana are mere, pere si altele.
// n = 6
// Ana
// are
// mere
// pere
// si
// altele
