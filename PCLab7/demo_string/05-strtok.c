// la fel ca 04-strtok, insa stocarea se va face intr-un vector
// vectorul este alocat static (maxim 100 cuvinte)
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
    char *words[WMAX];

    char *delim = " .:,?\n\t;";
    char *token = strtok(p, delim);
    while (token) {
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

    return 0;
}

// gcc 05-strtok.c -o 05-strtok && ./05-strtok
// Ana are mere, pere si altele.
// n = 6
// Ana
// are
// mere
// pere
// si
// altele
