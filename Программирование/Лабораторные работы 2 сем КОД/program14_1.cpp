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
    cout << "Введите размер списков: ";
    cin >> size;

    list<int> list1, list2;

    cout << "Введите " << size << " элементов первого списка: ";
    inputList(list1, size);

    cout << "Введите " << size << " элементов второго списка: ";
    inputList(list2, size);

    printList(list1, "Список 1");
    printList(list2, "Список 2");

    if (list1 == list2) {
        cout << "Списки равны." << endl;
    }
    else {
        cout << "Списки не равны." << endl;
    }
}
