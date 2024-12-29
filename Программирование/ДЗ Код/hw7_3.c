#include <stdio.h>
#include <locale.h>

void binaryMultiplication(const int* num1, const int* num2, int* result, int size) {
    for (int i = size - 1; i >= 0; i--) {
        if (num2[i] == 1) {
            int carry = 0;
            for (int j = size - 1; j >= 0; j--) {
                int product = num1[j] * num2[i] + result[i + j + 1] + carry;
                result[i + j + 1] = product % 2;
                carry = product / 2;
            }
            result[i] += carry;
        }
    }
}

void printArray7_3(const char* message, int* array, int size) {
    printf("%s", message);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main7_3() {
    setlocale(LC_ALL, "RU_ru");

    int num1[] = { 1, 0, 1, 1 };
    int num2[] = { 1, 1, 0, 1 };
    int size = sizeof(num1) / sizeof(num1[0]);
    int result[8] = { 0 };

    binaryMultiplication(num1, num2, result, size);

    printArray("Первое число: ", num1, size);
    printArray("Второе число: ", num2, size);
    printArray("Результат умножения: ", result, size * 2);

    return 0;
}
