#include <clocale>
#include <iostream>
#include <cstring>

using namespace std;

int count_sum(char s[], int l) {
    int c = 0;

    for (int i = 0; i < l; i++)
        c += s[i];
    
    return c;
}

void main10_1() {
    setlocale(LC_ALL, "ru_RU");

    char s1[] = "SUM", s2[] = "ALFA";
    int sum1 = 0, sum2 = 0;

    sum1 = count_sum(s1, 3);
    sum2 = count_sum(s2, 4);

    if (sum1 > sum2)
        cout << "Сумма кодов SUM больше: " << sum1 << endl;
    else
        cout << "Сумма кодов ALFA больше: " << sum2 << endl;
}
