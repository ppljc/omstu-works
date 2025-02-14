#include <iostream>

using namespace std;

const int SIZE = 4;

struct ShiftResult {
    int sum_above;
    int sum_below;
};

ShiftResult shift_matrix(int matrix[SIZE][SIZE]) {
    ShiftResult result = { 0, 0 };

    for (int i = 0; i < SIZE; i++) {
        for (int j = SIZE - 1; j >= 2; j--) {
            matrix[i][j] = matrix[i][j - 2];
        }
        matrix[i][0] = 0;
        matrix[i][1] = 0;
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (j > i) {
                result.sum_above += matrix[i][j];
            }
            else if (j < i) {
                result.sum_below += matrix[i][j];
            }
        }
    }

    return result;
}
