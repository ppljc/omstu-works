#include "functions.h"

int main() {
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_MAXIMIZE);

    CONSOLE_CURSOR_INFO cci = { 1, FALSE };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

    int selected = 0;
    DrawMenu(hwnd, selected);

    while (true) {
        HandleInput(hwnd, &selected);
    }

    return 0;
}
