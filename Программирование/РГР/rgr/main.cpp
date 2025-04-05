#include "functions.h"

int main() {
    srand(time(NULL));
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_MAXIMIZE);
    setlocale(LC_ALL, "RUS");
    CONSOLE_CURSOR_INFO CCI = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CCI);
    MainMenu();
    return 0;
}