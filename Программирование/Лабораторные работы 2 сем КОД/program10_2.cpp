#include <iostream>
#include <fstream>
#include <locale>

using namespace std;

const int MAX_SIZE = 100;

void main10_2() {
    setlocale(LC_ALL, "ru_RU");

    ifstream fin("D1.txt");
    ofstream fout("D2.txt");

    int n;
    fin >> n;

    double matrix[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> matrix[i][j];
        }
    }

    for (int j = 0; j < n; j++) {
        double tmp = matrix[0][j];
        matrix[0][j] = matrix[n - 1][j];
        matrix[n - 1][j] = tmp;
    }

    fout << n << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fout << matrix[i][j] << " ";
        }
        fout << endl;
    }

    fin.close();
    fout.close();

    cout << "Результат в D2.txt" << endl;
}
