#include <iostream>

using namespace std;

extern int A[4][4];
extern int B[4][4];

void processMatrix(int matrix[4][4], int& sumAbove, int& sumBelow) {
    int temp[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j < 2)
                temp[i][j] = 0;
            else
                temp[i][j] = matrix[i][j - 2];
        }
    }

    sumAbove = 0;
    sumBelow = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i < j)
                sumAbove += temp[i][j];
            else if (i > j)
                sumBelow += temp[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
}

void module13_3() {
    int sumAboveA, sumBelowA;
    int sumAboveB, sumBelowB;

    processMatrix(A, sumAboveA, sumBelowA);
    
    cout << "\n����� ������ A ����� ������:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << A[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "����� ��������� ���� ������� ��������� ������� A: " << sumAboveA << "\n";
    cout << "����� ��������� ���� ������� ��������� ������� A: " << sumBelowA << "\n";

    processMatrix(B, sumAboveB, sumBelowB);
    
    cout << "\n����� ������ B ����� ������:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << B[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "����� ��������� ���� ������� ��������� ������� B: " << sumAboveB << "\n";
    cout << "����� ��������� ���� ������� ��������� ������� B: " << sumBelowB << "\n";
}
