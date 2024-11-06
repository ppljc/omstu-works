#include <locale.h>
#include <stdio.h>
#include <math.h>

#define a 1.3
#define b 6.5

void main() {
    setlocale(LC_ALL, "ru_RU");
    double t, z;

    printf("Введите t в пределах [0.5, 3]: ");
    scanf_s("%lf", &t);

    (0.5 <= t && t <= 3.0) ? ((t < a) ? printf("Результат: %lf", a * pow(t, 2.0) - b * pow(t + 1.0, 0.5)) : ((a <= t && t <= b) ? printf("Результат: %lf", a - b) : printf("Результат: %lf", a * pow(t, 2.0 / 3.0) - pow(t + 1.0, 1.0 / 3.0)))) : printf("Вы ввели t не в указанных пределах!");
}