#include <stdio.h>
#include <locale.h>

float minmax(float a, float b, float c, float* min) {
    float max = 0;
    if (a > b) {
        max = a;
        *min = b;
    }
    else {
        *min = a;
        max = b;
    }
    if (*min > c)
        *min = c;
    if (max < c)
        max = c;
    return max;
}

void main6_2b() {
    setlocale(LC_ALL, "ru_RU");

    float A, D, E, X, Y, Z, min1, min2;

    scanf_s("%f %f %f %f %f %f", &A, &D, &E, &X, &Y, &Z);

    float w = (minmax(X, Y, Z, &min1) - min1) / (minmax(A, D, E, &min2) + min2);

    printf("%.2f", w);
}