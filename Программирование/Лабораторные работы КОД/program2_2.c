#include <locale.h>
#include <stdio.h>

void main2_2() {
    setlocale(LC_ALL, "ru_RU");

    int a, c;
    const char* b = "ничего";

    printf("¬вод: целое число a = ");
    scanf_s("%d", &a);
    
    c = a % 5;

    switch (c) {
        case 0:
            b = "ноль";
            break;
        case 1:
            b = "один";
            break;
        case 2:
            b = "два";
            break;
        case 3:
            b = "три";
            break;
        case 4:
            b = "четыре";
            break;
    }

    printf("–езультат: остаток от делени€ %d на 5 - %s\n", a, b);
}
