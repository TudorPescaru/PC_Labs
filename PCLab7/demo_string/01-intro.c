#include <stdio.h>
#define NMAX 100

void sample_str() {
    // doua modalitati de initializare a unui vector cu sirul "ana"
    char a[NMAX] = {'a', 'n', 'a', '\0'};
    char b[NMAX] = "ana";

    printf("a = %s\n", a);
    printf("b = %s\n", b);

    // citire de la tastatura
    char c[NMAX];
    scanf("%s", c);
    printf("c = %s\n", c);
}

void crash_example() {
    // alocam si sa initializam un string
    char x[NMAX] = "ana_x";

    // y va pointa catre un string constant
    char *y = "ana_y";

    printf("%s %s\n", x, y);
    x[0] = 'i'; // permis
    y[0] = 'i'; // nu este permis, intrucat y pointeaza
                // catre o zona constanta
    printf("%s %s\n", x, y);

}

int main() {
    sample_str();
    // crash_example();
    return 0;
}

// gcc 01-intro.c -o 01-intro && ./01-intro
// a = ana
// b = ana
// gigel
// c = gigel
//
