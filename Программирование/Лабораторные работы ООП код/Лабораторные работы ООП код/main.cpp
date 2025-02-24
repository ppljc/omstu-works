#include <iostream>
#include <clocale>

using namespace std;

extern int main1();

int main() {
    setlocale(LC_ALL, "ru_RU");

    int choice;

    while (1) {
        cout << "Введите номер задачи: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 0:
            cout << "Выход" << endl;
            return 0;
        case 1:
            main1();
            break;
        default:
            cout << "Неправильное значение." << endl;
            break;
        }
        cout << endl;
    }

    return 0;
}