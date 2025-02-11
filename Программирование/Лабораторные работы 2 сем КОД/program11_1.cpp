#include <iostream>
#include <fstream>
#include <locale>
#define MAX_N 100

using namespace std;

void processMatrix(int matrix[MAX_N][MAX_N], int n, int& evenCount, int& oddCount) {
    evenCount = 0;
    oddCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i % 2 == 0) && (j % 2 == 0)) {
                matrix[i][j] = 0;
            }
            else {
                if (matrix[i][j] % 2 == 0)
                    evenCount++;
                else
                    oddCount++;
            }
        }
    }
}

void printMatrix(ofstream& outfile, int matrix[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            outfile << matrix[i][j] << " ";
        }
        outfile << endl;
    }
    outfile << endl;
}

void readMatrix(ifstream& inputFile, int matrix[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inputFile >> matrix[i][j];
        }
    }
}

void main11_1() {
    setlocale(LC_ALL, "ru_RU");

    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int n;
    inputFile >> n;

    int matrix1[MAX_N][MAX_N];
    int matrix2[MAX_N][MAX_N];
    int originalMatrix1[MAX_N][MAX_N];
    int originalMatrix2[MAX_N][MAX_N];

    readMatrix(inputFile, matrix1, n);
    readMatrix(inputFile, matrix2, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            originalMatrix1[i][j] = matrix1[i][j];
            originalMatrix2[i][j] = matrix2[i][j];
        }
    }

    int evenCount1, oddCount1, evenCount2, oddCount2;

    processMatrix(matrix1, n, evenCount1, oddCount1);
    processMatrix(matrix2, n, evenCount2, oddCount2);

    outputFile << "Исходная первая матрица:" << endl;
    printMatrix(outputFile, originalMatrix1, n);
    outputFile << "Обработанная первая матрица:" << endl;
    printMatrix(outputFile, matrix1, n);
    outputFile << "Количество четных: " << evenCount1 << ", нечетных: " << oddCount1 << endl << endl;

    outputFile << "Исходная вторая матрица:" << endl;
    printMatrix(outputFile, originalMatrix2, n);
    outputFile << "Обработанная вторая матрица:" << endl;
    printMatrix(outputFile, matrix2, n);
    outputFile << "Количество четных: " << evenCount2 << ", нечетных: " << oddCount2 << endl;

    inputFile.close();
    outputFile.close();

    cout << "Результат в output.txt" << endl;
}
