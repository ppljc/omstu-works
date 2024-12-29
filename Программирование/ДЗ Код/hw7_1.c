#include <stdio.h>
#include <locale.h>

void shiftArrayRight(int* array, int size) {
    int temp = array[size - 1];
    for (int i = size - 1; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = temp;
}

void printArray7_1(const char* message, int* array, int size) {
    printf("%s", message);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main7_1() {
    setlocale(LC_ALL, "RU_ru");

    int array1[] = { 1, 2, 3, 4, 5 };
    int array2[] = { 6, 7, 8, 9, 10 };
    int array3[] = { 11, 12, 13, 14, 15 };
    int size1 = 5;
    int size2 = 5;
    int size3 = 5;

    shiftArrayRight(array1, size1);
    shiftArrayRight(array2, size2);
    shiftArrayRight(array3, size3);

    printArray("Массив 1 после сдвига вправо: ", array1, size1);
    printArray("Массив 2 после сдвига вправо: ", array2, size2);
    printArray("Массив 3 после сдвига вправо: ", array3, size3);

    return 0;
}
