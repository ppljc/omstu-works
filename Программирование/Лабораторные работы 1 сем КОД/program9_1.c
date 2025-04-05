#include <locale.h>
#include <stdio.h>

#define SIZE 5
#define REDUCED_SIZE 4

void remove_row_column(int source[SIZE][SIZE], int result[REDUCED_SIZE][REDUCED_SIZE], int row_to_remove, int col_to_remove) {
    int ci = 0;
    for (int i = 0; i < SIZE; i++) {
        if (i == row_to_remove) continue;
        int cj = 0;
        for (int j = 0; j < SIZE; j++) {
            if (j == col_to_remove) continue;
            result[ci][cj] = source[i][j];
            cj++;
        }
        ci++;
    }
}

void main9_1() {
    setlocale(LC_ALL, "ru_RU");

    int B[SIZE][SIZE], C[REDUCED_SIZE][REDUCED_SIZE];
    int n, k;

    printf("¬ведите матрицу B[5][5]:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("B[%d][%d] = ", i, j);
            scanf_s("%d", &B[i][j]);
        }
    }

    printf("¬ведите номер строки дл€ удалени€ (от 0 до 4): ");
    scanf_s("%d", &n);

    printf("¬ведите номер столбца дл€ удалени€ (от 0 до 4): ");
    scanf_s("%d", &k);

    remove_row_column(B, C, n, k);

    printf("–езультирующа€ матрица C:\n");
    for (int i = 0; i < REDUCED_SIZE; i++) {
        for (int j = 0; j < REDUCED_SIZE; j++) {
            printf("%5d", C[i][j]);
        }
        printf("\n");
    }
}
