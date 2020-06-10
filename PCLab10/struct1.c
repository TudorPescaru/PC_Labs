#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 31

typedef struct __attribute__((__packed__)) {
    char name[NAME_LEN];
    int age;
}person_t;

int main() {
    FILE *f = fopen("1-gigel.bin", "wb");
    person_t person;
    for (int i = 0; i < NAME_LEN; i++) {
        person.name[i] = 0;
    }
    scanf("%s %d", person.name, &person.age);
    fwrite(&person, sizeof(person_t), 1, f);
    fclose(f);
    memset(&person, 0 , sizeof(person_t));
    f = fopen("1-gigel.bin", "rb");
    fread(&person, sizeof(person_t), 1, f);
    printf("%s %d\n", person.name, person.age);
    return 0;
}
