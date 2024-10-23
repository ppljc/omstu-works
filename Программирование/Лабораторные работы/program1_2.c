#include <locale.h>
#include <stdio.h>
#include <math.h>

void main1_2() {
    setlocale(LC_ALL, "ru_RU");
    int k, h, m, s;

    printf("Введите прошедшее количество секунд: ");
    scanf_s("%i", &k);

    h = k / 3600;
    m = (k - 3600 * h) / 60;
    s = (k - 3600 * h - 60 * m);

    printf("За это время прошло часов: %i; минут: %i; секунд: %i;", h, m, s);
}