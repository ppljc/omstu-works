#include <locale.h>
#include <stdio.h>
#include <math.h>

<<<<<<< Updated upstream
void main() {
=======
void main4_1() {
>>>>>>> Stashed changes
    setlocale(LC_ALL, "ru_RU");

    double a, x = 1.0, z;

    printf("Ввод: значение a (например, 0.5 или 1.0) = ");
    scanf_s("%lf", &a);

    double dx = a / 2.0;

    printf("Таблица значений функции z\n");
    printf("----------------------------\n");
    printf("|    x    |        z       |\n");
    printf("----------------------------\n");

    while (x <= 4.0) {
        if (x >= 1.0 && x <= 2.5)
            z = pow(a * (x - a), 1.5);
        else
            z = (a / 2) * (exp(x / a) + exp(-x / a));

        printf("| %7.3f | %14.6f |\n", x, z);

        x += dx;
    }

    printf("----------------------------\n");
}
