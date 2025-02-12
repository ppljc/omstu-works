#include <iostream>
#include <fstream>
#include <locale>
#define MAX_TYPES 10
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

void main12_2() {
    setlocale(LC_ALL, "ru_RU");

    cout << "Введите имя входного файла: ";
    string inputFileName;
    cin >> inputFileName;

    ifstream inputFile(inputFileName.c_str());

    int typeCount;
    inputFile >> typeCount;

    Types types[MAX_TYPES];

    for (int i = 0; i < typeCount; i++) {
        inputFile >> types[i].name;
        inputFile >> types[i].opCount;
        for (int j = 0; j < types[i].opCount; j++) {
            inputFile >> types[i].operations[j];
        }
    }
    inputFile.close();

    Operation operationsList[MAX_TYPES * MAX_OPS];
    int operationCount = 0;

    for (int i = 0; i < typeCount; i++) {
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

    cout << "Введите имя выходного файла: ";
    string outputFileName;
    cin >> outputFileName;

    ofstream outputFile(outputFileName.c_str());

    outputFile << "Количество различных операций: " << operationCount << "\n\n";
    for (int i = 0; i < operationCount; i++) {
        outputFile << "Операция '" << operationsList[i].operation
            << "' поддерживается типами: ";
        for (int j = 0; j < operationsList[i].typeCount; j++) {
            outputFile << operationsList[i].types[j] << " ";
        }
        outputFile << endl;
    }
    outputFile.close();

    cout << "Результат в " << outputFileName << endl;
}
