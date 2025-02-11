#include <iostream>
#include <string>
#include <locale>

using namespace std;

int sumOfCodes(const string& word) {
    int sum = 0;
    for (char ch : word) {
        sum += static_cast<int>(ch);
    }
    return sum;
}

void main10_1() {
    setlocale(LC_ALL, "ru_RU");

    string word1 = "SUM";
    string word2 = "ALFA";

    int sum1 = sumOfCodes(word1);
    int sum2 = sumOfCodes(word2);

    cout << "Сумма ASCII-кодов слова " << word1 << ": " << sum1 << endl;
    cout << "Сумма ASCII-кодов слова " << word2 << ": " << sum2 << endl;

    if (word1 > word2) {
        cout << word1 << " больше, чем " << word2 << endl;
    }
    else if (word1 < word2) {
        cout << word1 << " меньше, чем " << word2 << endl;
    }
    else {
        cout << word1 << " и " << word2 << " равны" << endl;
    }
}
