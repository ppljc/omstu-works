#include <locale.h>
#include <stdio.h>

void main2_2() {
    setlocale(LC_ALL, "ru_RU");

    int a, c;
    const char* b = "������";

    printf("����: ����� ����� a = ");
    scanf_s("%d", &a);
    
    c = a % 5;

    switch (c) {
        case 0:
            b = "����";
            break;
        case 1:
            b = "����";
            break;
        case 2:
            b = "���";
            break;
        case 3:
            b = "���";
            break;
        case 4:
            b = "������";
            break;
    }

    printf("���������: ������� �� ������� %d �� 5 - %s\n", a, b);
}
