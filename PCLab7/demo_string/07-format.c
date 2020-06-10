#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 1000

void sprintf_example() {
    char msg[NMAX];

    printf("%s-%d\n", "ana", 1);     // afiseaza la stdout "ana-1"
    sprintf(msg, "%s-%d", "ana", 1); // salveaza in msg    "ana-1"

    printf("msg: \"%s\"\n", msg);    // putem afisa msg pentru verificare
}

void snprintf_example() {
    char msg[NMAX];

    printf("%s-%d\n", "ana", 1);             // afiseaza la stdout "ana-1"
    snprintf(msg, NMAX, "%s-%d", "ana", 1);  // salveaza in msg    "ana-1"

    printf("msg: \"%s\"\n", msg); // putem afisa msg pentru verificare
}

int main() {
    sprintf_example();
    snprintf_example();
    return 0;
}

// Daca rulati checkerul de coding style, veti observa urmatoarea eroare:
// 07-format.c:10:  Never use sprintf. Use snprintf instead.
// Cele 2 functii au logica similara, diferenta fiind ca snprintf primeste
// ca parametru dimensiunea bufferului, prin urmare poate verifica ca
// outputul incape in buffer.
//
// Concluzie: Mereu vom folosi snprintf!

