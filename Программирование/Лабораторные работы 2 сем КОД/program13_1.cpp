#include <iostream>
#include <locale>

using namespace std;

int A[6], B[8], C[7];

extern void module13_1();

void main13_1() {
    setlocale(LC_ALL, "ru_RU");

    module13_1();
}
