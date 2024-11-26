#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

void process_matrix(int matrix[SIZE][SIZE], int* even_count, int* odd_count, int* even_count_after, int* odd_count_after) {
    *even_count = 0;
    *odd_count = 0;
    *even_count_after = 0;
    *odd_count_after = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] % 2 == 0) {
                (*even_count)++;
            }
            else {
                (*odd_count)++;
            }

            if ((i % 2 == 0) && (j % 2 == 0)) {
                matrix[i][j] = 0;
            }

            if (matrix[i][j] % 2 == 0) {
                (*even_count_after)++;
            }
            else {
                (*odd_count_after)++;
            }
        }
    }
}

void print_matrix(const char* title, int matrix[SIZE][SIZE]) {
    printf("%s\n", title);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void main9_2() {
    setlocale(LC_ALL, "ru_RU");
    srand(time(NULL));

    int A[SIZE][SIZE], B[SIZE][SIZE];
    int even_A, odd_A, even_A_after, odd_A_after;
    int even_B, odd_B, even_B_after, odd_B_after;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            A[i][j] = rand() % 20 - 10;
            B[i][j] = rand() % 20 - 10;
        }
    }

    print_matrix("�������� ������� A:", A);
    print_matrix("�������� ������� B:", B);

    process_matrix(A, &even_A, &odd_A, &even_A_after, &odd_A_after);
    process_matrix(B, &even_B, &odd_B, &even_B_after, &odd_B_after);

    print_matrix("��������������� ������� A:", A);
    print_matrix("��������������� ������� B:", B);

    printf("������� A:\n");
    printf("�� ��������������: ������ = %d, �������� = %d\n", even_A, odd_A);
    printf("����� ��������������: ������ = %d, �������� = %d\n\n", even_A_after, odd_A_after);

    printf("������� B:\n");
    printf("�� ��������������: ������ = %d, �������� = %d\n", even_B, odd_B);
    printf("����� ��������������: ������ = %d, �������� = %d\n", even_B_after, odd_B_after);
}
