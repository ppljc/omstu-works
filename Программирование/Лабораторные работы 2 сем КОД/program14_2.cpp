#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <locale>

using namespace std;

void main14_2() {
    setlocale(LC_ALL, "ru_RU");

    stack<string> books;
    ifstream fin("books.txt");

    string book;
    while (getline(fin, book)) {
        books.push(book);
    }

    fin.close();

    string searchBook;
    cout << "¬ведите название книги дл€ поиска: ";

    cin.ignore();
    getline(cin, searchBook);

    int position = books.size();
    bool found = false;

    while (!books.empty()) {
        if (books.top() == searchBook) {
            found = true;
            break;
        }
        books.pop();
        position--;
    }

    if (found) {
        cout << " нига найдена на позиции " << position << "." << endl;
    }
    else {
        cout << " нига не найдена." << endl;
    }
}
