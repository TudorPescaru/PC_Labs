#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindrom(char s[]) {
    int i, j, ok = 1;
    char pali[strlen(s)];
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == ' ') {
            for (j = i; j < strlen(s); j++) {
                s[j] = s[j + 1];
            }
        }
    }
    i = 0;
    while (i < strlen(s)) {
        pali[i] = s[strlen(s) - 1 - i];
        i++;
    }
    pali[i] = '\0';
    for (i = 0; i < strlen(s); i++) {
        if (s[i] != pali[i]) {
            ok = 0;
        }
    }
    return ok;
}

void alloc(int *n, char ***v) {
    int i;
    (*v) = (char **)malloc((*n) * sizeof(char*));
    for (i = 0; i <= (*n); i++) {
        (*v)[i] = (char *)malloc(100);
    }
}

void sort_strings(int n, char **v) {
    int i, j, k;
    char aux[100];
    for (i = 1; i < n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (strlen(v[i]) > strlen(v[j])) {
                strcpy(aux, v[i]);
                strcpy(v[i], v[j]);
                strcpy(v[j], aux);
            } else {
                if (strlen(v[i]) == strlen(v[j])) {
                    for (k = 0; k < strlen(v[i]); k++) {
                        if (v[i][k] > v[j][k]) {
                            strcpy(aux, v[i]);
                            strcpy(v[i], v[j]);
                            strcpy(v[j], aux);
                        }
                    }
                }
            }
        }
    }
    for (i = 1; i <= n; i++) {
        printf("%s ", v[i]);
    }
    printf("\n");
}

int count_read_words(char *s) {
    int count = 0, i, ok;
    char *word;
    word = strtok(s," ");
    while (word != NULL) {
        ok = 1;
        for (i = 0; i < strlen(word); i++) {
            if((word[i] < 65 || word[i] > 90) && (word[i] < 97 || word[i] > 122)) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            count++;
        }
        word = strtok(NULL, " ");
    }
    return count;
}

int count_occurrences(char *s, char *word) {
    int occ = 0;
    char *count;
    count = strstr(s, word);
    while (s != NULL && count != NULL) {
        occ++;
        count = strstr(count + strlen(word), word);
    }
    return occ;
}

struct student{
    char nume[100];
    char prenume[100];
    int varsta;
} st;

int main() {
    int n, i, j;
    char s[100], **v, word[100];
    fgets(s, 100, stdin);
    s[strlen(s) - 1] = 0;
    printf("%d\n", palindrom(s));
    scanf("%d", &n);
    alloc(&n, &v);
    fgets(v[0], 100, stdin);
    for (i = 1; i <= n; i++) {
        fgets(v[i], 100, stdin);
        v[i][strlen(v[i]) - 1] = 0;
    }
    sort_strings(n, v);
    fgets(s, 100, stdin);
    s[strlen(s) - 1] = 0;
    printf("%d\n", count_read_words(s));
    fgets(s, 100, stdin);
    s[strlen(s) - 1] = 0;
    fgets(word, 100, stdin);
    word[strlen(word) - 1] = 0;
    printf("%d\n", count_occurrences(s,word));
    scanf("%d", &n);
    return 0;
}
