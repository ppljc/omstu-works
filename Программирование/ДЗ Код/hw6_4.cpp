#include <stdio.h>
#include <stdbool.h>

int sum(int* A, int* B, int* C) {
    int carry = 0;
    for (int i = 5; i >= 0; i--) {
        int current_sum = A[i] + B[i] + carry;
        C[i + 1] = current_sum % 2;
        carry = current_sum / 2;
    }
    C[0] = carry;
    return 0;
}

int print_binary(int* A) {
    bool has_non_zero = false;
    for (int i = 0; i < 7; ++i) {
        if (A[i] != 0) {
            has_non_zero = true;
        }
        if (has_non_zero) {
            printf("%d", A[i]);
        }
    }
    if (!has_non_zero) {
        printf("0");
    }
    return 0;
}

int main() {
    int A[6] = { 1, 0, 1, 1, 1, 1 };
    int B[6] = { 0, 1, 0, 1, 1, 1 };
    int C[7] = { 0 };

    sum(A, B, C);

    print_binary(C);

    return 0;
}