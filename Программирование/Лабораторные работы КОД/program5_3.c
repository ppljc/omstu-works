#include <locale.h>
#include <stdio.h>
#include <math.h>

void main5_3() {
    setlocale(LC_ALL, "ru_RU");

    double a, x = 1.0, z;

    printf("����: �������� a (��������, 0.5 ��� 1.0) = ");
    scanf_s("%lf", &a);

    double dx = a / 2.0;

    printf("������� �������� ������� z\n");
    printf("----------------------------\n");
    printf("|    x    |        z       |\n");
    printf("----------------------------\n");

    do {
        if (x >= 1.0 && x <= 2.5)
            z = pow(a * (x - a), 1.5);
        else
            z = (a / 2) * (exp(x / a) + exp(-x / a));

        printf("| %7.3f | %14.6f |\n", x, z);

        x += dx;
    } while (x <= 4.0);

    printf("----------------------------\n");
}
