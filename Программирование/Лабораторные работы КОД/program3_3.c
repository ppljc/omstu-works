#include <locale.h>
#include <stdio.h>
#include <math.h>

#define Pi 3.14159265358979323846
#define n 20
#define a 0
#define b 2*Pi

void main3_3() {
    setlocale(LC_ALL, "ru_RU");
    double x, y;
    double step = (b - a) / (n - 1);

    printf("Таблица значений функции y = (1 + (sin(x))^2)^0.5\n");
    printf("----------------------------\n");
    printf("|    x    |        y       |\n");
    printf("----------------------------\n");

    for (int i = 0; i < n; i++) {
        x = i * step;
        y = sqrt(1 + pow(sin(x), 2));
        printf("| %7.3f | %14.6f |\n", x, y);
    }

    printf("----------------------------\n");
}