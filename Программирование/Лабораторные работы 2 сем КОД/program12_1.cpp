#include <iostream>
#include <locale>
#define MAX_TYPES 6
#define MAX_OPS 10

using namespace std;

struct Types {
    string name;
    string operations[MAX_OPS];
    int opCount;
};

struct Operation {
    string operation;
    string types[MAX_TYPES];
    int typeCount;
};

void main12_1() {
    setlocale(LC_ALL, "ru_RU");

    Types types[MAX_TYPES] = {
        {"int", {"+", "-", "*", "/", "%", "++", "--", "==", "!=", "="}, 10},
        {"double", {"+", "-", "*", "/", "++", "--", "==", "!=", "="}, 9},
        {"char", {"+", "-", "++", "--", "==", "!=", "="}, 7},
        {"bool", {"&&", "||", "!", "==", "!=", "="}, 6},
        {"string", {"+", "=", "==", "!="}, 4},
        {"float", {"+", "-", "*", "/", "++", "--", "==", "!=", "="}, 9}
    };

    Operation operationsList[MAX_OPS * MAX_TYPES];
    int operationCount = 0;

    for (int i = 0; i < MAX_TYPES; i++) {
        for (int j = 0; j < types[i].opCount; j++) {
            bool found = false;
            for (int k = 0; k < operationCount; k++) {
                if (operationsList[k].operation == types[i].operations[j]) {
                    operationsList[k].types[operationsList[k].typeCount++] = types[i].name;
                    found = true;
                    break;
                }
            }
            if (!found) {
                operationsList[operationCount].operation = types[i].operations[j];
                operationsList[operationCount].types[0] = types[i].name;
                operationsList[operationCount].typeCount = 1;
                operationCount++;
            }
        }
    }

    cout << "Количество различных операций: " << operationCount << endl;

    for (int i = 0; i < operationCount; i++) {
        cout << "Операция '" << operationsList[i].operation << "' поддерживается типами: ";
        for (int j = 0; j < operationsList[i].typeCount; j++) {
            cout << operationsList[i].types[j] << " ";
        }
        cout << endl;
    }
}
