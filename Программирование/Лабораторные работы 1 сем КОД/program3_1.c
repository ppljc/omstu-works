#include <locale.h>
#include <stdio.h>
#include <math.h>

void main3_1() {
    setlocale(LC_ALL, "ru_RU");

    double x, y = 1.0, factorial = 1.0;

    printf("¬вод: значение x = ");
    scanf_s("%lf", &x);

    for (int i = 1; i <= 10; i++) {
        factorial *= i;
        y += pow(x, 2 * i) / factorial;
    }

    printf("–езультат: y = %.6f\n", y);
}
