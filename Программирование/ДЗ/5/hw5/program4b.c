#include <locale.h>
#include <stdio.h>

void shiftLeft(int arr[], int n) {
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
}

void main4b() {
    setlocale(LC_ALL, "ru_RU");

    int arr[] = { 1, 2, 3, 4, 5 };
    int n = 5;

    printf("Исходный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    shiftLeft(arr, n);
    printf("Массив после циклического сдвига влево:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
