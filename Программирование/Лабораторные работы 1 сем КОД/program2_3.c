#include <locale.h>
#include <stdio.h>
#include <math.h>

#define a 1.3
#define b 6.5

void main2_3() {
    setlocale(LC_ALL, "ru_RU");

    double t;

    printf("Ввод: в пределах [0.5, 3] t = ");
    scanf_s("%lf", &t);

    (0.5 <= t && t <= 3.0) ? ((t < a) ? printf("Результат: z = %lf\n", a * pow(t, 2.0) - b * pow(t + 1.0, 0.5)) : ((a <= t && t <= b) ? printf("Результат: z = %lf\n", a - b) : printf("Результат: z = %lf\n", a * pow(t, 2.0 / 3.0) - pow(t + 1.0, 1.0 / 3.0)))) : printf("Вы ввели t не в указанных пределах!\n");
}
