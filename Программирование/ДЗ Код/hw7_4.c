#include <stdio.h>
#include <locale.h>
#include <math.h>

int binaryFloatAddition(int* mantissa1, int* mantissa2, int exp1, int exp2, int* resultMantissa, int size) {
    int expDiff = exp1 - exp2;
    int resultExp;

    if (expDiff > 0) {
        for (int i = size - 1; i >= expDiff; i--) {
            mantissa2[i] = mantissa2[i - expDiff];
        }
        for (int i = 0; i < expDiff; i++) {
            mantissa2[i] = 0;
        }
        resultExp = exp1;
    }
    else {
        for (int i = size - 1; i >= -expDiff; i--) {
            mantissa1[i] = mantissa1[i + expDiff];
        }
        for (int i = 0; i < -expDiff; i++) {
            mantissa1[i] = 0;
        }
        resultExp = exp2;
    }

    int carry = 0;
    for (int i = size - 1; i >= 0; i--) {
        int sum = mantissa1[i] + mantissa2[i] + carry;
        resultMantissa[i] = sum % 2;
        carry = sum / 2;
    }

    if (carry == 1) {
        for (int i = size - 1; i > 0; i--) {
            resultMantissa[i] = resultMantissa[i - 1];
        }
        resultMantissa[0] = 1;
        resultExp++;
    }

    return resultExp;
}

void printArray7_4(const char* message, int* array, int size) {
    printf("%s", message);
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
}

int main7_4() {
    setlocale(LC_ALL, "RU_ru");

    int mantissa1[] = { 1, 0, 1, 1, 0 };
    int mantissa2[] = { 1, 1, 0, 1, 1 };
    int exp1 = 3;
    int exp2 = 1;
    int size = sizeof(mantissa1) / sizeof(mantissa1[0]);
    int resultMantissa[5] = { 0 };

    int resultExp = binaryFloatAddition(mantissa1, mantissa2, exp1, exp2, resultMantissa, size);

    printArray("Мантисса первого числа: ", mantissa1, size);
    printf("Порядок первого числа: %d\n", exp1);
    printArray("Мантисса второго числа: ", mantissa2, size);
    printf("Порядок второго числа: %d\n", exp2);
    printArray("Результат сложения (мантисса): ", resultMantissa, size);
    printf("Результат сложения (порядок): %d\n", resultExp);

    return 0;
}
