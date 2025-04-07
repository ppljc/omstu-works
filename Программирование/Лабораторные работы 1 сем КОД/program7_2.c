#include <locale.h>
#include <stdio.h>

void main7_2() {
    setlocale(LC_ALL, "ru_RU");

    int table[9][9];

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            table[i][j] = (i + 1) * (j + 1);
        }
    }

    printf("Таблица Пифагора:\n");
    printf("     ");
    for (int j = 1; j <= 9; j++) {
        printf("%4d", j);
    }
    printf("\n");

    printf("    ");
    for (int j = 0; j < 9; j++) {
        printf("----");
    }
    printf("\n");

    for (int i = 0; i < 9; i++) {
        printf("%2d | ", i + 1);
        for (int j = 0; j < 9; j++) {
            printf("%4d", table[i][j]);
        }
        printf("\n");
    }
}
