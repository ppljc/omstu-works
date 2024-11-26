#include <locale.h>
#include <stdio.h>

void main6_1_1() {
    setlocale(LC_ALL, "ru_RU");

    double numbers[10];
    int is_increasing = 1;

    printf("������� 10 ������������ �����:\n");

    for (int i = 0; i < 10; i++) {
        printf("����� %d: ", i + 1);
        scanf_s("%lf", &numbers[i]);
    }

    for (int i = 1; i < 10; i++) {
        if (numbers[i] <= numbers[i - 1]) {
            is_increasing = 0;
            break;
        }
    }

    if (is_increasing)
        printf("������������������ �������� ������������.\n");
    else
        printf("������������������ �� �������� ������������.\n");
}

void main6_1_2() {
    setlocale(LC_ALL, "ru_RU");

    double previous, current;
    int is_increasing = 1;

    printf("������� 10 ������������ �����:\n");

    printf("����� 1: ");
    scanf_s("%lf", &previous);

    for (int i = 2; i <= 10; i++) {
        printf("����� %d: ", i);
        scanf_s("%lf", &current);

        if (current <= previous) {
            is_increasing = 0;
        }

        previous = current;
    }

    if (is_increasing)
        printf("������������������ �������� ������������.\n");
    else
        printf("������������������ �� �������� ������������.\n");
}
