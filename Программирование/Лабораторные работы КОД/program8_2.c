#include <locale.h>
#include <stdio.h>
#include <math.h>

#define Pi 3.14159265358979323846
#define n 20
#define a 0
#define b 2 * Pi

void calculate_values(double values[3][n]) {
    double step = (b - a) / (n - 1);
    for (int i = 0; i < n; i++) {
        values[0][i] = i * step;
        values[1][i] = 5 - 3 * cos(values[0][i]);
        values[2][i] = sqrt(1 + pow(sin(values[0][i]), 2));
    }
}

void main8_2() {
    setlocale(LC_ALL, "ru_RU");

    double values[3][n];

    calculate_values(values);

    printf("Таблица значений функций:\n");
    printf("---------------------------------------------\n");
    printf("|    x    |        y1       |        y2     |\n");
    printf("---------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("| %7.3f | %14.6f | %14.6f |\n", values[0][i], values[1][i], values[2][i]);
    }

    printf("---------------------------------------------\n");
}
