#include <stdio.h>

#define SET_SIZE 100

typedef unsigned char SET[SET_SIZE];

void insert_in_set(SET s, unsigned int n) {
    s[n >> 3] += 1 << (n & 7);
}

void delete_from_set(SET s, unsigned int n) {
    s[n >> 3] -= 1 << (n & 7);
}

int is_in_set(SET s, unsigned int n) {
    if (s[n >> 3] & (1 << (n & 7))) {
        return 1;
    } else {
        return 0;
    }
}

void delete_all_from_set(SET s) {
    for (int i = 0; i < SET_SIZE; i++) {
        s[i] = 0;
    }
}

int card_set(SET s) {
    int nr = 0;
    for (int i = 0; i < SET_SIZE; i++) {
        if (s[i] != 0) {
            for (int j = 0; j < 8; j++) {
                if (s[i] & (1 << j)) {
                    nr++;
                }
            }
        }
    }
    return nr;
}

int is_empty_set(SET s) {
    for (int i = 0; i < SET_SIZE; i++) {
        if (s[i] != 0) {
            return 0;
        }
    }
    return 1;
}

int read_set(SET s) {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert_in_set(s, n);
    }
    return n;
}

void print_set(SET s) {
    for (int i = 0; i < SET_SIZE; i++) {
        for (int j = 0; j < 8; j++) {
            if(s[i] & (1 << j)) {
                printf("%d ", (i * 8) + j);
            }
        }
    }
    printf("\n");
}

void merge_set(SET a, SET b, SET c) {
    for (int i = 0; i < SET_SIZE; i++) {
        for (int j = 0; j < 8; j++) {
            if(a[i] & (1 << j)) {
                insert_in_set(c, 8 * i + j);
            }
            if(b[i] & (1 << j)) {
                insert_in_set(c,  8 * i + j);
            }
        }
    }
}

void intersect_set(SET a, SET b, SET c) {
    for (int i = 0; i < SET_SIZE; i++) {
        for (int j = 0; j < 8; j++) {
            if((a[i] & (1 << j)) && (a[i] & (1 << j))) {
                insert_in_set(c, 8 * i + j);
            }
        }
    }
}

int main() {
    SET s = {0};
    SET a = {0};
    SET b = {0};
    SET c = {0};
    unsigned int n;
    scanf("%u", &n);
    insert_in_set(s, n);
    printf("%d\n", is_in_set(s, n));
    // printf("%d\n", card_set(s));
    // delete_from_set(s, n);
    // printf("%d\n", read_set(s));
    printf("%d\n", is_empty_set(s));
    print_set(s);
}
