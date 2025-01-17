#include <stdio.h>
#include <locale.h>

float min(float a, float b, float c) {
    float MIN = a;
    if (MIN > b)
        MIN = b;
    if (MIN > c)
        MIN = c;
    return MIN;
}

float max(float a, float b, float c) {
    float MAX = a;
    if (MAX < b)
        MAX = b;
    if (MAX < c)
        MAX = c;
    return MAX;
}

void main6_2a() {
    setlocale(LC_ALL, "ru_RU");

    float A, D, E, X, Y, Z;

    scanf_s("%f %f %f %f %f %f", &A, &D, &E, &X, &Y, &Z);

    float w = (max(X, Y, Z) - min(X, Y, Z)) / (max(A, D, E) + min(A, D, E));

    printf("%.2f", w);
}