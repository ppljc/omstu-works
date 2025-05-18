#include "functions.h"

void DrawMenu(HWND hwnd, int selected) {
    HDC hdc = GetDC(hwnd);
    RECT window;
    GetClientRect(hwnd, &window);

    FillRect(hdc, &window, (HBRUSH)GetStockObject(BLACK_BRUSH));

    const int menuWidth = 400;
    const int itemHeight = 40;
    const int menuHeight = MENU_ITEMS * itemHeight;

    const int menuLeft = (window.right - menuWidth) / 2;
    const int menuTop = (window.bottom - menuHeight) / 2;

    HFONT hNormalFont = CreateFont(28, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
        DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
        DEFAULT_PITCH, L"Arial");
    HFONT hSelectedFont = CreateFont(28, 0, 0, 0, FW_NORMAL, TRUE, FALSE, FALSE,
        DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
        DEFAULT_PITCH, L"Arial");

    SetTextAlign(hdc, TA_CENTER);
    SetTextColor(hdc, RGB(255, 255, 255));
    SetBkMode(hdc, TRANSPARENT);
    SelectObject(hdc, hNormalFont);
    TextOutA(hdc, window.right / 2, menuTop - 60, "Главное меню", 12);

    SetTextAlign(hdc, TA_LEFT);
    for (int i = 0; i < MENU_ITEMS; i++) {
        RECT itemRect = {
            menuLeft,
            menuTop + i * itemHeight,
            menuLeft + menuWidth,
            menuTop + (i + 1) * itemHeight
        };

        if (i == selected) {
            HBRUSH hBlueBrush = CreateSolidBrush(RGB(100, 150, 255));
            FillRect(hdc, &itemRect, hBlueBrush);
            DeleteObject(hBlueBrush);

            SetTextColor(hdc, RGB(255, 255, 255));
            SelectObject(hdc, hSelectedFont);
        }
        else {
            SetTextColor(hdc, RGB(200, 200, 200));
            SelectObject(hdc, hNormalFont);
        }

        TextOutA(hdc, menuLeft + 10, menuTop + i * itemHeight + 8, menuItems[i], strlen(menuItems[i]));
    }

    DeleteObject(hNormalFont);
    DeleteObject(hSelectedFont);
    ReleaseDC(hwnd, hdc);
}

void HandleInput(HWND hwnd, int* selected) {
    if (GetAsyncKeyState(VK_UP) & 0x8000) {
        *selected = (*selected - 1 + MENU_ITEMS) % MENU_ITEMS;
        DrawMenu(hwnd, *selected);
        Sleep(150);
    }
    else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
        *selected = (*selected + 1) % MENU_ITEMS;
        DrawMenu(hwnd, *selected);
        Sleep(150);
    }
    else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
        if (*selected == MENU_ITEMS - 1) {
            HDC hdc = GetDC(hwnd);
            RECT window;
            GetClientRect(hwnd, &window);

            FillRect(hdc, &window, (HBRUSH)GetStockObject(BLACK_BRUSH));

            SetTextColor(hdc, RGB(255, 255, 255));
            SetBkMode(hdc, TRANSPARENT);
            HFONT hFont = CreateFont(32, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
                DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                DEFAULT_PITCH, L"Arial");
            SelectObject(hdc, hFont);
            SetTextAlign(hdc, TA_CENTER);

            const char* msg = "Нажмите любую клавишу, чтобы закрыть это окно...";
            TextOutA(hdc, window.right / 2, window.bottom / 2, msg, (int)strlen(msg));

            DeleteObject(hFont);
            ReleaseDC(hwnd, hdc);
            exit(0);
        }

        switch (*selected) {
            case 0: ShowIntro(hwnd); break;
            case 1: ShowAbout(hwnd); break;
            case 2: ShowTable(hwnd); break;
            case 3: ShowGraph(hwnd); break;
            case 4: ShowIntegral(hwnd); break;
            case 5: ShowEquation(hwnd); break;
        }

        DrawMenu(hwnd, *selected);
    }
}
