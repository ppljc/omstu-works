#include <locale.h>
#include <stdio.h>
#include <math.h>

void main4_3() {
    setlocale(LC_ALL, "ru_RU");

    double a, x = 1.0, z;

    printf("Ввод: значение a (например, 0.5 или 1.0) = ");
    scanf_s("%lf", &a);

    double dx = a / 2.0;

    printf("Таблица значений функции Z\n");
    printf("-----------------------------\n");
    printf("|    x    |        Z        |\n");
    printf("-----------------------------\n");

    for (x = 1.0; x <= 4.0; x += dx) {
        if (x >= 1.0 && x <= 2.5)
            z = pow(a * (x - a), 1.5);
        else
            z = (a / 2) * (exp(x / a) + exp(-x / a));

        printf("| %7.3f | %14.6f |\n", x, z);
    }

    printf("-----------------------------\n");
}