#include <iostream>
#include <string>

using namespace std;

bool containsWord(const string words[], int size, const string& word) {
    for (int i = 0; i < size; ++i) {
        if (words[i] == word) {
            return true;
        }
    }
    return false;
}

void main11_2() {
    string input;
    cout << "Введите последовательность слов, разделенных запятыми, и завершите точкой: ";
    cin.ignore();
    getline(cin, input);

    string uniqueWords[8];
    int uniqueCount = 0;

    string word;
    int start = 0;

    for (int i = 0; i < input.length(); ++i) {
        if (input[i] == ',' || input[i] == '.') {
            word = input.substr(start, i - start);

            if (!containsWord(uniqueWords, uniqueCount, word)) {
                uniqueWords[uniqueCount] = word;
                uniqueCount++;
            }

            start = i + 1;
        }
    }

    cout << "Результат: ";
    for (int i = 0; i < uniqueCount; ++i) {
        cout << uniqueWords[i];
        if (i < uniqueCount - 1) {
            cout << ", ";
        }
    }
    cout << "." << endl;
}
