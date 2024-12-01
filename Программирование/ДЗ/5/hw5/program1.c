#include <locale.h>
#include <stdio.h>

void main1() {
    setlocale(LC_ALL, "ru_RU");

    int N, q;
    char result[32];
    int index = 0;

    scanf_s("%d", &N);
    scanf_s("%d", &q);

    while (N > 0) {
        int remainder = N % q;
        result[index] = (remainder < 10) ? '0' + remainder : 'A' + (remainder - 10);
        N /= q;
        index++;
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
}
