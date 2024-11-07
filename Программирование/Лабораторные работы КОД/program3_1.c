#include <locale.h>
#include <stdio.h>
#include <math.h>

void main3_1() {
    setlocale(LC_ALL, "ru_RU");
    double x, y = 1.0;

    printf("Введите значение X: ");
    scanf_s("%lf", &x);

    for (int i = 1; i <= 10; i++) {
        int factorial = 1;
        for (int j = 2; j <= i; j++) {
            factorial *= j;
        }
        y += pow(x, 2 * i) / factorial;
    }

    printf("Результат Y = %.6f\n", y);
}
