#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 31

typedef struct{
    char *name;
    int age;
} person_t;

int main() {
    person_t person;
    FILE *f = fopen("2-gigel.bin", "wb");
    int size, i;
    char c[NAME_LEN];
    scanf("%s %d", c, &person.age);
    size = strlen(c) + 1;
    person.name = (char *)calloc(size + 1, sizeof(char));
    strcpy(person.name, c);
    fwrite(&size, sizeof(int), 1, f);
    fwrite(person.name, size, 1, f);
    fwrite(&person.age, sizeof(int), 1, f);
    fclose(f);
    free(person.name);
    memset(&person.age, 0, sizeof(int));
    f = fopen("2-gigel.bin", "rb");
    person.name = (char *)calloc(size + 1, sizeof(char));
    fread(&size, sizeof(int), 1, f);
    for (i = 0; i < size; i++) {
        fread(&person.name[i], sizeof(char), 1, f);
    }
    person.name[size] = '\0';
    fread(&person.age, sizeof(int), 1, f);
    printf("%s %d\n", person.name, person.age);
    free(person.name);
    fclose(f);
    return 0;
}
