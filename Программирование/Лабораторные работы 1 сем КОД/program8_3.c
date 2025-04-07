#include <locale.h>
#include <stdio.h>

void input_array(int array[], int size, const char* name) {
    printf("Введите элементы массива %s[%d]:\n", name, size);
    for (int i = 0; i < size; i++) {
        printf("%s[%d] = ", name, i);
        scanf_s("%d", &array[i]);
    }
}

int count_non_negative(const int array[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] >= 0) {
            count++;
        }
    }
    return count;
}

void main8_3() {
    setlocale(LC_ALL, "ru_RU");

    int A[6], B[8], C[7];

    input_array(A, 6, "A");
    input_array(B, 8, "B");
    input_array(C, 7, "C");

    int countA = count_non_negative(A, 6);
    int countB = count_non_negative(B, 8);
    int countC = count_non_negative(C, 7);

    printf("\nКоличество неотрицательных элементов:\n");
    printf("В массиве A: %d\n", countA);
    printf("В массиве B: %d\n", countB);
    printf("В массиве C: %d\n", countC);
}
