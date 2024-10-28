#include <locale.h>
#include <stdio.h>
#include <math.h>

#define a 1.5
#define b -1.2

void main1_1() {
    setlocale(LC_ALL, "ru_RU");
    double x, x1 = 1.0, x2 = 2.0, y;

    for (x = x1; x <= x2 + 0.1; x += 0.1) {
        y = exp(-a * x) * cbrt(a * x + b * sin(2 * x));
        printf("x = %f, y = %f\n", x, y);
    }
}