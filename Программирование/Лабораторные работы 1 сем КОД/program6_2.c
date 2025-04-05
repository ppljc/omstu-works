#include <locale.h>
#include <stdio.h>
#include <math.h>

#define Pi 3.14159265358979323846
#define n 20
#define a 0
#define b 2 * Pi

void main6_2() {
    setlocale(LC_ALL, "ru_RU");

    double x[n], y1[n], y2[n];
    double step = (b - a) / (n - 1);

    for (int i = 0; i < n; i++) {
        x[i] = i * step;
        y1[i] = 5 - 3 * cos(x[i]);
        y2[i] = sqrt(1 + pow(sin(x[i]), 2));
    }

    printf("Таблица значений функций:\n");
    printf("---------------------------------------------\n");
    printf("|    x    |        y1       |        y2     |\n");
    printf("---------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("| %7.3f | %14.6f | %14.6f |\n", x[i], y1[i], y2[i]);
    }

    printf("---------------------------------------------\n");
}
