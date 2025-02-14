#include <iostream>

using namespace std;

const int SIZE = 4;

void process_matrix(int matrix[SIZE][SIZE], int& even_count, int& odd_count, int& even_count_after, int& odd_count_after) {
    even_count = 0;
    odd_count = 0;
    even_count_after = 0;
    odd_count_after = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] % 2 == 0) {
                even_count++;
            }
            else {
                odd_count++;
            }

            if ((i % 2 == 0) && (j % 2 == 0)) {
                matrix[i][j] = 0;
            }

            if (matrix[i][j] % 2 == 0) {
                even_count_after++;
            }
            else {
                odd_count_after++;
            }
        }
    }
}

void print_matrix(const char* title, int matrix[SIZE][SIZE]) {
    cout << title << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
