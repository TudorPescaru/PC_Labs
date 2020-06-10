#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 31

typedef struct {
    char *name;
    int age;
}person_t;

int main() {
    person_t *person;
    FILE *f = fopen("3-gigel.bin", "wb");
    int n, i, j, size;
    char c[NAME_LEN];
    scanf("%d", &n);
    person = (person_t *)calloc(n, sizeof(person_t));
    for (i = 0; i < n; i++) {
        scanf("%s %d", c, &person[i].age);
        size = strlen(c) + 1;
        person[i].name = (char *)calloc(size + 1, sizeof(char));
        strcpy(person[i].name, c);
        fwrite(&size, sizeof(int), 1, f);
        fwrite(person[i].name, size, 1, f);
        fwrite(&person[i].age, sizeof(int), 1, f);
    }
    fclose(f);
    for (i = 0; i < n; i++) {
        free(person[i].name);
    }
    free(person);
    f = fopen("3-gigel.bin", "rb");
    person = (person_t *)calloc(n, sizeof(person_t));
    for (i = 0; i < n; i++) {
        fread(&size, sizeof(int), 1, f);
        person[i].name = (char *)calloc(size + 1, sizeof(char));
        for (j = 0; j < size; j++) {
            fread(&person[i].name[j], sizeof(char), 1, f);
        }
        person[i].name[size] = '\0';
        fread(&person[i].age, sizeof(int), 1, f);
    }
    for (i = 0; i < n; i++) {
        printf("%s %d\n", person[i].name, person[i].age);
    }
    fclose(f);
    for (i = 0; i < n; i++) {
        free(person[i].name);
    }
    free(person);
    return 0;
}
