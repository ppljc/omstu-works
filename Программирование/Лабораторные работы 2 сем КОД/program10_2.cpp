#define _CRT_SECURE_NO_WARNINGS

#include <clocale>
#include <iostream>
#include <cstring>

using namespace std;

void main10_2() {
    setlocale(LC_ALL, "ru_RU");

    char s[48];

    cout << "¬ведите до 8 слов через зап€тую: ";
    cin >> s;

    char* a = strtok(s, ",.");
    char* b = a;

    while (a != NULL) {
        int counter = 0;
        while (b != NULL) {
            if (a == b)
                counter++;
            b = strtok(NULL, ",.");
        }
        if (counter > 1) {
            
        }
    }
}
