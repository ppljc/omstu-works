#include <iostream>
#include <clocale>

using namespace std;

extern void main10_1();
extern void main10_2();

int main() {
    setlocale(LC_ALL, "ru_RU");

    int choice;

    while (1) {
        cout << "������� ����� ������: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 0:
                cout << "�����" << endl;
                return 0;
            case 101:
                main10_1();
                break;
            case 102:
                main10_2();
                break;
            default:
                cout << "������������ ��������." << endl;
                break;
        }
        cout << endl;
    }

    return 0;
}