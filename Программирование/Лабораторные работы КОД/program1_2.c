#include <locale.h>
#include <stdio.h>
#include <math.h>

void main() {
    setlocale(LC_ALL, "ru_RU");
    int k, h, m, s;

    printf("k = ");
    scanf_s("%i", &k);

    h = k / 3600;
    m = (k - 3600 * h) / 60;
    s = (k - 3600 * h - 60 * m);

    printf("h = %i, m = %i, s = %i", h, m, s);
}