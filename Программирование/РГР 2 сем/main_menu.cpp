#include "functions.h"

void MainMenu() {
    HWND hWnd = GetConsoleWindow();
    HDC hdc = GetDC(hWnd);
    int selected = 0;
    char key;
    do {
        ShowMenu(selected, hdc, hWnd);
        key = _getch();

        if (key == 72) {
            selected = (selected - 1 + 7) % 7;
        }
        else if (key == 80) {
            selected = (selected + 1) % 7;
        }
        else if (key == 13) {
            switch (selected) {
            case 0:
                printIntro();
                break;
            case 1:
                printAbout();
                break;
            case 2:
                printTable();
                break;
            case 3:
                printGraph();
                break;
            case 4:
                printIntegral();
                break;
            case 5:
                printEquation();
                break;
            case 6:
                system("cls");
                ExitProcess(0);
            }
        }
    } while (key != 27);
}


void ShowMenu(int selected, HDC hdc, HWND hWnd) {
    RECT window;
    GetClientRect(hWnd, &window);
    FillRect(hdc, &window, (HBRUSH)GetStockObject(BLACK_BRUSH));
    const char* menuItems[] = { "1. Заставка", "2. Об авторе","3. Таблица","4. График","5. Интеграл","6. Уравнение","7. Выход" };
    for (int i = 0; i < 7; i++)
    {
        if (i == selected) {
            printSelectedMenuItem(menuItems[i], i, window);
        }
        else {
            printMenuItems(menuItems[i], i, window);
        }
    }

}

void printSelectedMenuItem(const char* items, int i, RECT window) {
    HWND hWnd = GetConsoleWindow();
    HDC hdc = GetDC(hWnd);
    GetClientRect(hWnd, &window);
    HFONT font = CreateFont(30, 0, 0, 0, FW_NORMAL, TRUE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_QUALITY, NULL);
    SelectObject(hdc, font);
    SetTextColor(hdc, RGB(255, 255, 0));
    SetBkColor(hdc, RGB(40, 100, 100));
    TextOutA(hdc, window.right/2 - 50, window.bottom/2 + i * 30 - 90, items, strlen(items));
    DeleteObject(font);
    ReleaseDC(hWnd, hdc);
}
void printMenuItems(const char* items, int i, RECT window) {
    HWND hWnd = GetConsoleWindow();
    HDC hdc = GetDC(hWnd);
    HFONT font = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_QUALITY, NULL);
    SelectObject(hdc, font);
    SetBkColor(hdc, RGB(0, 0, 0));
    SetTextColor(hdc, RGB(255, 255, 255));
    TextOutA(hdc, window.right / 2 - 50, window.bottom / 2 + i * 30 - 90, items, strlen(items));
    DeleteObject(font);
    ReleaseDC(hWnd, hdc);
}

