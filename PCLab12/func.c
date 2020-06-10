#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

void listf(double (*fp)(double), double min, double max, double pos) {
    for (double x = min; x <= max; x += pos) {
        double y = (*fp)(x);
        printf("%lf %lf\n", x, y);
    }
}

void list_ints(int first, ...) {
    if (first == -1) {
        return;
    }
    va_list args;
    va_start(args, first);
    int current = first;
    do {
        printf("%d\n", current);
        current = va_arg(args, int);
    } while (current >= 0);
    printf("\n");
    va_end(args);
}

int cmmdc(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int gcd(int first, ...) {
    if (first == -1) {
        return -1;
    }
    va_list args;
    va_start(args, first);
    int current = first, next, r;
    next = current;
    while (next >= 0) {
        current = cmmdc(current, next);
        next = va_arg(args, int);
    }
    va_end(args);
    return current;
}

int main() {
    double (*fp[])(double) = {sin, cos, exp, log10, sqrt, fabs};
    int end = sizeof(fp)/sizeof(fp[0]);
    printf("%d", end);
    for (int i = 0; i < end; i++) {
        printf("\n");
        listf(*fp[i], 0.0, 2.0 * M_PI, M_PI / 10);
    }
    printf("%d\n", gcd(5, 10, -1));
    printf("%d\n", gcd(5, 10, 2, 100, -1));
    printf("%d\n", gcd(500, 10, 25, 75, -1));
    printf("%d\n", gcd(1024, 48, 64, 256, 2048, -1));
    return 0;
}
