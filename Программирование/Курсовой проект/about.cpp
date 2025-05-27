#include "functions.h"

void ShowAbout(HWND hwnd) {
    HDC hdc = GetDC(hwnd);

    RECT window;
    GetClientRect(hwnd, &window);
    FillRect(hdc, &window, (HBRUSH)GetStockObject(BLACK_BRUSH));

    HFONT hFont = CreateFont(28, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
        DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
        DEFAULT_PITCH, L"Arial");
    SelectObject(hdc, hFont);

    SetTextColor(hdc, RGB(255, 255, 255));
    SetTextAlign(hdc, TA_CENTER);
    SetBkMode(hdc, TRANSPARENT);

    TextOutA(hdc, window.right / 2, window.bottom / 2 - 150, "Информация об авторе", 20);

    HFONT hTextFont = CreateFont(24, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
        DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
        DEFAULT_PITCH, L"Arial");
    SelectObject(hdc, hTextFont);

    TextOutA(hdc, window.right / 2, window.bottom / 2 - 80, "ФИО: Шмидт Антон Владиславович", 30);
    TextOutA(hdc, window.right / 2, window.bottom / 2 - 40, "Дата рождения: 17.10.2006", 25);
    TextOutA(hdc, window.right / 2, window.bottom / 2, "Факультет: ФИТиКС", 17);
    TextOutA(hdc, window.right / 2, window.bottom / 2 + 40, "Группа: ИВТ-244", 15);

    DeleteObject(hFont);
    DeleteObject(hTextFont);
    ReleaseDC(hwnd, hdc);

    while (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000)) Sleep(100);
}
