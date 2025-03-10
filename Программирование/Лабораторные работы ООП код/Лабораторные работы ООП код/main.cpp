#include <iostream>
#include <clocale>

using namespace std;

extern int main1();
extern int main2();
extern int main3();

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
        case 2:
            main2();
            break;
        case 3:
            main3();
            break;
        default:
            cout << "Неправильное значение." << endl;
            break;
        }
        cout << endl;
    }

    return 0;
}