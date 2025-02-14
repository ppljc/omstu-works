#include <iostream>
#include <locale>
#include <ctime>

using namespace std;

const int SIZE = 4;

extern void process_matrix(int matrix[SIZE][SIZE], int& even_count, int& odd_count, int& even_count_after, int& odd_count_after);
extern void print_matrix(const char* title, int matrix[SIZE][SIZE]);

void main13_2() {
    setlocale(LC_ALL, "ru_RU");
    srand(time(NULL));

    int A[SIZE][SIZE], B[SIZE][SIZE];
    int even_A, odd_A, even_A_after, odd_A_after;
    int even_B, odd_B, even_B_after, odd_B_after;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            A[i][j] = rand() % 20 - 10;
            B[i][j] = rand() % 20 - 10;
        }
    }

    print_matrix("Исходная матрица A:", A);
    print_matrix("Исходная матрица B:", B);

    process_matrix(A, even_A, odd_A, even_A_after, odd_A_after);
    process_matrix(B, even_B, odd_B, even_B_after, odd_B_after);

    print_matrix("Преобразованная матрица A:", A);
    print_matrix("Преобразованная матрица B:", B);

    cout << "Матрица A:\n";
    cout << "До преобразования: чётных = " << even_A << ", нечётных = " << odd_A << endl;
    cout << "После преобразования: чётных = " << even_A_after << ", нечётных = " << odd_A_after << endl << endl;

    cout << "Матрица B:\n";
    cout << "До преобразования: чётных = " << even_B << ", нечётных = " << odd_B << endl;
    cout << "После преобразования: чётных = " << even_B_after << ", нечётных = " << odd_B_after << endl;
}
