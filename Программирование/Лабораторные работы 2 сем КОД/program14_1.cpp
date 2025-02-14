#include <iostream>
#include <list>

using namespace std;

void inputList(list<int>& lst, int size) {
    for (int i = 0; i < size; i++) {
        int num;
        cin >> num;
        lst.push_back(num);
    }
}

void printList(const list<int>& lst, const string& name) {
    cout << name << ": ";
    for (int num : lst) {
        cout << num << " ";
    }
    cout << endl;
}

void main14_1() {
    setlocale(LC_ALL, "ru_RU");

    int size;
    cout << "������� ������ �������: ";
    cin >> size;

    list<int> list1, list2;

    cout << "������� " << size << " ��������� ������� ������: ";
    inputList(list1, size);

    cout << "������� " << size << " ��������� ������� ������: ";
    inputList(list2, size);

    printList(list1, "������ 1");
    printList(list2, "������ 2");

    if (list1 == list2) {
        cout << "������ �����." << endl;
    }
    else {
        cout << "������ �� �����." << endl;
    }
}
