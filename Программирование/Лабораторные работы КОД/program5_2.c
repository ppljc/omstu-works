#include <locale.h>
#include <stdio.h>
#include <math.h>

void main5_2() {
    setlocale(LC_ALL, "ru_RU");

    int num, count = 0;
    double product = 1.0;

    printf("����:\n");
    scanf_s("%d", &num);

    while (num >= 0) {
        product *= num;
        count++;
        scanf_s("%d", &num);
    }

    if (count > 0)
        printf("���������: %.6f\n", pow(product, 1.0 / count));
    else
        printf("������: ������������������ �����.\n");
}
