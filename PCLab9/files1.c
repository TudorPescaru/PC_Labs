#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *f = fopen("a.in", "w");
    char name[11], group[6];
    int age, size1, size2;
    scanf("%s %d %s", name, &age, group);
    fprintf(f, "%s %d %s", name, age, group);
    fclose(f);
    f = fopen("a.in", "r");
    fscanf(f, "%s %d %s", name, &age, group);
    printf("%s %d %s\n", name, age, group);
    fclose(f);
    f = fopen("ab.in", "wb");
    size1 = strlen(name);
    size2 = strlen(group);
    fwrite(&size1, sizeof(int), 1, f);
    fwrite(name, sizeof(char), size1, f);
    fwrite(&age, sizeof(int), 1, f);
    fwrite(&size2, sizeof(int), 1, f);
    fwrite(group, sizeof(char), size2, f);
    fclose(f);
    strcpy(name, " ");
    strcpy(group, " ");
    age = 0;
    size1 = 0;
    size2 = 0;
    f = fopen("ab.in", "rb");
    fread(&size1, sizeof(int), 1, f);
    fread(name, sizeof(char), size1, f);
    fread(&age, sizeof(int), 1, f);
    fread(&size2, sizeof(int), 1, f);
    fread(group, sizeof(char), size2, f);
    printf("%s %d %s\n", name, age, group);
    fclose(f);
}
