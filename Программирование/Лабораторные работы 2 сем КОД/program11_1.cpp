#include <iostream>
#include <string>
#include <locale>

using namespace std;

int calculateSum(const string& word) {
    int sum = 0;
    for (char c : word) {
        sum += static_cast<int>(c);
    }
    return sum;
}

void main11_1() {
    setlocale(LC_ALL, "ru_RU");

    string word1 = "SUM";
    string word2 = "ALFA";

    int sum1 = calculateSum(word1);
    int sum2 = calculateSum(word2);

    cout << "Сумма кодов букв слова " << word1 << " = " << sum1 << endl;
    cout << "Сумма кодов букв слова " << word2 << " = " << sum2 << endl << endl;

    if (sum1 > sum2) {
        cout << "Слово " << word1 << " больше." << endl;
    }
    else if (sum1 < sum2) {
        cout << "Слово " << word2 << " больше." << endl;
    }
    else {
        cout << "Слова равны." << endl;
    }
}
