#include <locale.h>
#include <stdio.h>
#include <math.h>

#define a 1.5
#define b -1.2

double calculate_y(double x) {
    return exp(-a * x) * cbrt(a * x + b * sin(2 * x));
}

void main8_1() {
    setlocale(LC_ALL, "ru_RU");

    double x, y;

    printf("¬вод: x = ");
    scanf_s("%lf", &x);

    y = calculate_y(x);

    printf("–езультат: y = %f\n", y);
}
