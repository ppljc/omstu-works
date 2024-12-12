#include <locale.h>
#include <stdio.h>

void main2() {
    setlocale(LC_ALL, "ru_RU");

    double D;
    int q, t;

    scanf_s("%lf", &D);
    scanf_s("%d", &q);
    scanf_s("%d", &t);

    printf("0.");
    for (int i = 0; i < t; i++) {
        D *= q;
        int b = (int)D;
        printf("%c", (b < 10) ? '0' + b : 'A' + (b - 10));
        D -= b;
    }
}
