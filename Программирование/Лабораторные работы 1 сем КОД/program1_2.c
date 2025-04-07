#include <locale.h>
#include <stdio.h>
#include <math.h>

void main1_2() {
    setlocale(LC_ALL, "ru_RU");

    int k, h, m, s;

    printf("¬вод: число прошедших секунд k = ");
    scanf_s("%d", &k);

    h = k / 3600;
    m = (k - 3600 * h) / 60;
    s = (k - 3600 * h - 60 * m);

    printf("–езультат: прошло часов - %d, минут - %d, секунд - %d\n", h, m, s);
}
