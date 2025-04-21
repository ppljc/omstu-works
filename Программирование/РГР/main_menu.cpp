#include "functions.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13
#define KEY_ESC 27

void gotoxy(int x, int y) {
    COORD coord = { SHORT(x), SHORT(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setTextColor(bool selected) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (selected)
        SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    else
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

int getConsoleHeight() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void drawMenu(const vector<string>& items, int selectedIndex) {
    system("cls");
    int width = getConsoleWidth();
    int height = getConsoleHeight();
    int startY = height / 2 - items.size() / 2;

    for (int i = 0; i < items.size(); ++i) {
        string text = items[i];
        int startX = width / 2 - text.size() / 2;
        gotoxy(startX, startY + i);
        setTextColor(i == selectedIndex);
        cout << text;
        setTextColor(false);
    }
}

void showSubmenu(const string& title) {
    system("cls");
    int width = getConsoleWidth();
    int height = getConsoleHeight();

    string msg = "Вы выбрали: " + title;
    gotoxy(width / 2 - msg.size() / 2, height / 2);
    cout << msg;

    gotoxy(width / 2 - 12, height / 2 + 2);
    cout << "Нажмите ESC для возврата";

    while (true) {
        int key = _getch();
        if (key == KEY_ESC)
            break;
    }
}

void runMenu(const vector<string>& menuItems, const vector<function<void()>>& actions) {
    int selectedIndex = 0;

    while (true) {
        drawMenu(menuItems, selectedIndex);

        int key = _getch();
        if (key == 224) key = _getch();

        switch (key) {
        case KEY_UP:
            selectedIndex = (selectedIndex - 1 + menuItems.size()) % menuItems.size();
            break;
        case KEY_DOWN:
            selectedIndex = (selectedIndex + 1) % menuItems.size();
            break;
        case KEY_ENTER:
            if (menuItems[selectedIndex] == "7. Выход") {
                exit(0);
            }
            else {
                actions[selectedIndex]();
            }
            break;
        case KEY_ESC:
            exit(0);
        }
    }
}
