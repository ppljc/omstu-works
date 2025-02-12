#include <iostream>
#include <locale>

using namespace std;

extern int A[6], B[8], C[7];

void input_array(int array[], int size, const char* name) {
    cout << "Введите элементы массива " << name << " [" << size << "]:" << endl;
    for (int i = 0; i < size; i++) {
        cout << name << "[" << i << "] = ";
        cin >> array[i];
    }
}

int count_non_negative(const int array[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] >= 0)
            count++;
    }
    return count;
}

void module13_1() {
    setlocale(LC_ALL, "ru_RU");

    input_array(A, 6, "A");
    input_array(B, 8, "B");
    input_array(C, 7, "C");

    int countA = count_non_negative(A, 6);
    int countB = count_non_negative(B, 8);
    int countC = count_non_negative(C, 7);

    cout << "\nКоличество неотрицательных элементов:\n";
    cout << "В массиве A: " << countA << "\n";
    cout << "В массиве B: " << countB << "\n";
    cout << "В массиве C: " << countC << "\n";
}
