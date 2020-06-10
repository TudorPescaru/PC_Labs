#include <stdio.h>
#include <stdlib.h>

int is_even(int n) {
    return (n & 1) ? 0 : 1;
}

int pow2(int n) {
    return 1 << n;
}

int flip_bits(int n) {
    return ~n;
}

void print_bits(int n) {
    int size = 8 * sizeof(int);
    unsigned long max_pow = 1 << (size - 1);
    for (long i = 0; i < size; i++) {
        printf("%u ", (n & max_pow) ? 1 : 0);
        n = n << 1;
    }
    printf("\n");
}

int is_power2(int n) {
    return n & (n - 1) ? 0 : 1;
}

int main() {
    int n;
    scanf("%d", &n);
    print_bits(n);
    return 0;
}
