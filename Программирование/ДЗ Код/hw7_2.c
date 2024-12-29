#include <stdio.h>
#include <locale.h>

void binaryAddition(const int* array1, const int* array2, int* result, int size) {
    int carry = 0;
    for (int i = size - 1; i >= 0; i--) {
        int sum = array1[i] + array2[i] + carry;
        result[i] = sum % 2;
        carry = sum / 2;
    }
}

void printArray7_2(const char* message, int* array, int size) {
    printf("%s", message);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main7_2() {
    setlocale(LC_ALL, "RU_ru");

    int array1[] = { 1, 0, 1, 1, 0 };
    int array2[] = { 1, 1, 0, 0, 1 };
    int result[5];
    int size = sizeof(array1) / sizeof(array1[0]);

    binaryAddition(array1, array2, result, size);

    printArray("Первый массив: ", array1, size);
    printArray("Второй массив: ", array2, size);
    printArray("Результат сложения: ", result, size);

    return 0;
}
