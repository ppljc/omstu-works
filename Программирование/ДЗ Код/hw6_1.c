#include <stdio.h>
#include <locale.h>

float facsum(int k, int* A) {
    float s = 0.0;
    int f = 1;
    for (int i = 0; i < k; i++) {
        s += A[i];
        f *= (i + 1);
    }
    float z = s / f;
    return z;
}

int main6_1() {
    setlocale(LC_ALL, "ru_RU");

    int k = 5, n = 6;
    int A[5] = { 1, 2, 3, 4, 5 };
    int B[6] = { 2, 3, 4, 5, 6, 7 };

    float z = facsum(k, A) + facsum(n, B);

    printf("%.2f", z);

    return 0;
}