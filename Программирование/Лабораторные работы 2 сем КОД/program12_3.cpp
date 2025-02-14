#include <iostream>
#include <ctime>
#include <locale>

using namespace std;

const int SIZE = 4;

struct MatrixStats {
    int even_count;
    int odd_count;
    int even_count_after;
    int odd_count_after;
};

MatrixStats processMatrix(int matrix[SIZE][SIZE]) {
    MatrixStats stats = { 0, 0, 0, 0 };

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] % 2 == 0)
                stats.even_count++;
            else
                stats.odd_count++;

            if ((i % 2 == 0) && (j % 2 == 0))
                matrix[i][j] = 0;

            if (matrix[i][j] % 2 == 0)
                stats.even_count_after++;
            else
                stats.odd_count_after++;
        }
    }

    return stats;
}

void printMatrix(const string& title, int matrix[SIZE][SIZE]) {
    cout << title << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void main12_3() {
    setlocale(LC_ALL, "ru_RU");
    srand(time(NULL));

    int A[SIZE][SIZE], B[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            A[i][j] = rand() % 20 - 10;
            B[i][j] = rand() % 20 - 10;
        }
    }

    printMatrix("Исходная матрица A:", A);
    printMatrix("Исходная матрица B:", B);

    MatrixStats statsA = processMatrix(A);
    MatrixStats statsB = processMatrix(B);

    printMatrix("Преобразованная матрица A:", A);
    printMatrix("Преобразованная матрица B:", B);

    cout << "Матрица A:" << endl;
    cout << "До преобразования: чётных = " << statsA.even_count << ", нечётных = " << statsA.odd_count << endl;
    cout << "После преобразования: чётных = " << statsA.even_count_after << ", нечётных = " << statsA.odd_count_after << endl << endl;

    cout << "Матрица B:" << endl;
    cout << "До преобразования: чётных = " << statsB.even_count << ", нечётных = " << statsB.odd_count << endl;
    cout << "После преобразования: чётных = " << statsB.even_count_after << ", нечётных = " << statsB.odd_count_after << endl;
}
