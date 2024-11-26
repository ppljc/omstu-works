#include <locale.h>
#include <stdio.h>

void main7_1() {
    setlocale(LC_ALL, "ru_RU");

    int B[5][5], C[4][4];
    int n, k;

    printf("¬ведите матрицу B[5][5]:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("B[%d][%d] = ", i, j);
            scanf_s("%d", &B[i][j]);
        }
    }

    printf("¬ведите номер строки дл€ удалени€ (от 0 до 4): ");
    scanf_s("%d", &n);

    printf("¬ведите номер столбца дл€ удалени€ (от 0 до 4): ");
    scanf_s("%d", &k);

    int ci = 0;
    for (int i = 0; i < 5; i++) {
        if (i == n) continue;
        int cj = 0;
        for (int j = 0; j < 5; j++) {
            if (j == k) continue;
            C[ci][cj] = B[i][j];
            cj++;
        }
        ci++;
    }

    printf("–езультирующа€ матрица C:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%5d", C[i][j]);
        }
        printf("\n");
    }
}
