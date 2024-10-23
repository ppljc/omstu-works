#include <locale.h>
#include <stdio.h>
#include <math.h>

#define a 1.3
#define b 6.5

void main2_1() {
    setlocale(LC_ALL, "ru_RU");
    double t, z;

    printf("Введите t в пределах [0.5, 3]: ");
    scanf_s("%lf", &t);

    if (0.5 <= t && t <= 3.0) {
        if (t < a)
            z = a * pow(t, 2.0) - b * pow(t + 1.0, 0.5);
        else if (a <= t && t <= b)
            z = a - b;
        else // такого при текущих исходных данных не может быть
            z = a * pow(t, 2.0 / 3.0) - pow(t + 1.0, 1.0 / 3.0);
        printf("Результат: %lf", z);
    }
    else
        printf("Вы ввели t не в указанных пределах!");
}