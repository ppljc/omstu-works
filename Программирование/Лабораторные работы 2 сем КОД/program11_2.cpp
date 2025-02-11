#include <iostream>
#include <fstream>
#include <locale>
#define MAX_N 100

using namespace std;

void readMatrix(ifstream& inputFile, double matrix[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inputFile >> matrix[i][j];
        }
    }
}

void printMatrix(ofstream& outfile, double matrix[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            outfile << matrix[i][j] << " ";
        }
        outfile << endl;
    }
    outfile << endl;
}

void main11_2() {
    setlocale(LC_ALL, "ru_RU");

    ifstream inputFile("D1.txt");
    ofstream outputFile("D2.txt");

    int n;
    inputFile >> n;

    double matrix[MAX_N][MAX_N];

    readMatrix(inputFile, matrix, n);

    outputFile << "Исходная матрица:" << endl;
    printMatrix(outputFile, matrix, n);

    for (int j = 0; j < n; j++) {
        swap(matrix[0][j], matrix[n - 1][j]);
    }

    outputFile << "Обработанная матрица:" << endl;
    printMatrix(outputFile, matrix, n);

    inputFile.close();
    outputFile.close();

    cout << "Результат в D2.txt" << endl;
}
