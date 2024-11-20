#include <locale.h>
#include <stdio.h>
#include <math.h>

void main1() {
    setlocale(LC_ALL, "ru_RU");
    double a, x = 1.0, z;

    printf("Введите значение a (например, 0.5 или 1.0): ");
    scanf_s("%lf", &a);

    double dx = a / 2.0;
    printf("%lf", dx);

    printf("Таблица значений функции Z\n");
    printf("-----------------------------\n");
    printf("|    x    |        Z        |\n");
    printf("-----------------------------\n");

    while (x <= 4.0) {
        if (x >= 1.0 && x <= 2.5) {
            z = pow(a * (x - a), 1.5);
        }
        else if (x > 2.5 && x <= 4.0) {
            z = (a / 2) * (exp(x / a) + exp(-x / a));
        }
        else {
            printf("Значение x вне диапазона 1 <= x <= 4\n");
            break;
        }

        printf("| %7.3f | %14.6f |\n", x, z);
        
        x += dx;
    }

    printf("-----------------------------\n");
}