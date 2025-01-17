#include <stdio.h>
#include <locale.h>

void invertBits(int* array, int* invertedArray, int size) {
    for (int i = 0; i < size; i++) {
        invertedArray[i] = array[i] ^ 1;
    }
}

void addOne(int* array, int size) {
    int carry = 1;
    int i = size - 1;
    while (i >= 0 && carry > 0) {
        int sum = array[i] + carry;
        array[i] = sum % 2;
        carry = sum / 2;
        i--;
    }
}

void printArray(const char* message, int* array, int size) {
    printf("%s", message);
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
}

int main7_5() {
    setlocale(LC_ALL, "RU_ru");

    int number[] = { 0, 1, 1, 0, 1 };
    int size = 5;
    int invertedNumber[5] = { 0 };

    invertBits(number, invertedNumber, size);
    addOne(invertedNumber, size);

    printArray("Исходное число: ", number, size);
    printArray("Число в дополнительном коде: ", invertedNumber, size);

    return 0;
}
