#include <locale.h>
#include <stdio.h>

void shiftRight(int arr[], int n) {
    int temp = arr[n - 1];
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

void main4a() {
    setlocale(LC_ALL, "ru_RU");

    int arr[] = { 1, 2, 3, 4, 5 };
    int n = 5;

    printf("Исходный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    shiftRight(arr, n);
    printf("Массив после сдвига вправо:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
