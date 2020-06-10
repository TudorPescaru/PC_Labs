#include <stdio.h>

#define NMAX 100

int my_strlen(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

int main() {
    char s[NMAX];
    scanf("%s", s);
    printf("%d\n", my_strlen(s));
    return 0;
}
