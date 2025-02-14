#include <iostream>
#include <locale>
#include <ctime>

using namespace std;

const int SIZE = 4;

struct ShiftResult {
    int sum_above;
    int sum_below;
};

extern ShiftResult shift_matrix(int matrix[SIZE][SIZE]);
extern void print_matrix(const char* title, int matrix[SIZE][SIZE]);

void main13_3() {
    setlocale(LC_ALL, "ru_RU");
    srand(time(NULL));

    int A[SIZE][SIZE], B[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            A[i][j] = rand() % 20 - 10;
            B[i][j] = rand() % 20 - 10;
        }
    }

    print_matrix("Исходная матрица A:", A);
    print_matrix("Исходная матрица B:", B);

    ShiftResult resultA = shift_matrix(A);
    ShiftResult resultB = shift_matrix(B);

    print_matrix("Преобразованная матрица A:", A);
    print_matrix("Преобразованная матрица B:", B);

    cout << "Матрица A:\n";
    cout << "Сумма выше главной диагонали: " << resultA.sum_above << endl;
    cout << "Сумма ниже главной диагонали: " << resultA.sum_below << endl << endl;

    cout << "Матрица B:\n";
    cout << "Сумма выше главной диагонали: " << resultB.sum_above << endl;
    cout << "Сумма ниже главной диагонали: " << resultB.sum_below << endl;
}
