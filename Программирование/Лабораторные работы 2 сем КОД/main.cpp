#include <iostream>
#include <clocale>

using namespace std;

extern void main10_1();
extern void main10_2();
extern void main11_1();
extern void main11_2();
extern void main12_1();
extern void main12_2();
extern void main12_3();
extern void main13_1();
extern void main13_2();
extern void main13_3();
extern void main14_1();
extern void main14_2();

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
            case 101:
                main10_1();
                break;
            case 102:
                main10_2();
                break;
            case 111:
                main11_1();
                break;
            case 112:
                main11_2();
                break;
            case 121:
                main12_1();
                break;
            case 122:
                main12_2();
                break;
            case 123:
                main12_3();
                break;
            case 131:
                main13_1();
                break;
            case 132:
                main13_2();
                break;
            case 133:
                main13_3();
                break;
            case 141:
                main14_1();
                break;
            case 142:
                main14_2();
                break;
            default:
                cout << "Неправильное значение." << endl;
                break;
        }
        cout << endl;
    }

    return 0;
}