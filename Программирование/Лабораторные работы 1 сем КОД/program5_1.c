#include <locale.h>
#include <stdio.h>
#include <math.h>

#define Pi 3.14159265358979323846
#define n 20
#define a 0
#define b 2*Pi

void main5_1() {
    setlocale(LC_ALL, "ru_RU");

    double x, y1, y2, step = (b - a) / (n - 1);
    int i = 0;

    printf("Таблица значений функций:\n");
    printf("---------------------------------------------\n");
    printf("|    x    |        y1       |        y2     |\n");
    printf("---------------------------------------------\n");

    do {
        x = i * step;
        y1 = 5 - 3 * cos(x);
        y2 = sqrt(1 + pow(sin(x), 2));
        printf("| %7.3f | %14.6f | %14.6f |\n", x, y1, y2);
        i++;
    } while (i < n);

    printf("---------------------------------------------\n");
}
