#include <iostream>
#include <locale>

using namespace std;

int A[4][4], B[4][4];

extern void module13_3();

void inputMatrix(int matrix[4][4], const char* name) {
    cout << "¬ведите элементы массива " << name << " (4x4):\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << name << "[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
}

void main13_3() {
    setlocale(LC_ALL, "ru_RU");

    inputMatrix(A, "A");
    cout << "\n";
    inputMatrix(B, "B");

    module13_3();
}
