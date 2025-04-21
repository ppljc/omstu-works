#include "functions.h"

using namespace std;

void setCursorVisible(bool visible) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = visible;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void clearConsoleBlack() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;

    COORD topLeft = { 0, 0 };
    DWORD charsWritten;
    FillConsoleOutputCharacter(hConsole, ' ', consoleSize, topLeft, &charsWritten);
    FillConsoleOutputAttribute(hConsole, 0, consoleSize, topLeft, &charsWritten);
    SetConsoleCursorPosition(hConsole, topLeft);
}

void printIntro() {
    srand(static_cast<unsigned>(time(nullptr)));
    SetConsoleOutputCP(65001);
    setCursorVisible(false);

    clearConsoleBlack();

    int width = getConsoleWidth();
    int height = getConsoleHeight();

    vector<string> logo = {
        " ____   ____   _          _  ____ ",
        "|  _ \\ |  _ \\ | |        | ||  __\\",
        "| |_) || |_) || |    _   | || |   ",
        "|  __/ |  __/ | |__ / \\ _| || |__ ",
        "|_|    |_|    |____|\\ _____||____/"
    };

    int logoHeight = logo.size();
    int logoWidth = logo[0].length();
    int startY = height / 2 - logoHeight / 2;
    int startX = width / 2 - logoWidth / 2;

    string charset = "!@#$%^&*()_+-=[]{}|;:<>?/\\";

    for (int step = 0; step < 20; ++step) {
        for (int y = 0; y < logoHeight; ++y) {
            for (int x = 0; x < logoWidth; ++x) {
                char actual = logo[y][x];
                if (actual == ' ') continue;

                char symbol = (step > 15) ? actual : charset[rand() % charset.size()];
                gotoxy(startX + x, startY + y);
                cout << symbol;
            }
        }
        this_thread::sleep_for(chrono::milliseconds(50));
    }

    for (int y = 0; y < logoHeight; ++y) {
        gotoxy(startX, startY + y);
        cout << logo[y];
    }

    this_thread::sleep_for(chrono::milliseconds(1200));
    setCursorVisible(true);

    _getch();
}
