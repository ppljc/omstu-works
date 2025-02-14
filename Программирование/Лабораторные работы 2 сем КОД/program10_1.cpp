#include <iostream>
#include <fstream>
#include <string>
#include <locale>

using namespace std;

const int SIZE = 4;

void processMatrix(int matrix[SIZE][SIZE], int& even_count, int& odd_count, int& even_count_after, int& odd_count_after) {
    even_count = 0;
    odd_count = 0;
    even_count_after = 0;
    odd_count_after = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] % 2 == 0)
                even_count++;
            else
                odd_count++;
            if ((i % 2 == 0) && (j % 2 == 0))
                matrix[i][j] = 0;
            if (matrix[i][j] % 2 == 0)
                even_count_after++;
            else
                odd_count_after++;
        }
    }
}

void printMatrix(ofstream& fout, const string& title, int matrix[SIZE][SIZE]) {
    fout << title << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            fout << matrix[i][j] << " ";
        }
        fout << endl;
    }
    fout << endl;
}

void inputMatrix(ifstream& fin, int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            fin >> matrix[i][j];
        }
    }
}

void main10_1() {
    setlocale(LC_ALL, "ru_RU");

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int A[SIZE][SIZE], B[SIZE][SIZE];

    inputMatrix(fin, A);
    inputMatrix(fin, B);

    printMatrix(fout, "Исходная матрица A:", A);
    printMatrix(fout, "Исходная матрица B:", B);

    int even_A, odd_A, even_A_after, odd_A_after;
    int even_B, odd_B, even_B_after, odd_B_after;

    processMatrix(A, even_A, odd_A, even_A_after, odd_A_after);
    processMatrix(B, even_B, odd_B, even_B_after, odd_B_after);

    printMatrix(fout, "Преобразованная матрица A:", A);
    printMatrix(fout, "Преобразованная матрица B:", B);

    fout << "Матрица A:" << endl;
    fout << "До преобразования: чётных = " << even_A << ", нечётных = " << odd_A << endl;
    fout << "После преобразования: чётных = " << even_A_after << ", нечётных = " << odd_A_after << endl;
    fout << endl;

    fout << "Матрица B:" << endl;
    fout << "До преобразования: чётных = " << even_B << ", нечётных = " << odd_B << endl;
    fout << "После преобразования: чётных = " << even_B_after << ", нечётных = " << odd_B_after << endl;

    fin.close();
    fout.close();

    cout << "Результат в output.txt" << endl;
}
