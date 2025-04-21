#include "functions.h"

void printGraph() {
    HWND hWnd = GetConsoleWindow();

    HDC hdc = GetDC(hWnd);

    RECT window;
    GetClientRect(hWnd, &window);
    POINT point;

    const double scale = 100.0;
    const int mod = 1000;

    const double x_start = 0.0;
    const double x_end = 2 * M_PI;
    const double dx = (x_end - x_start) / mod;

    FillRect(hdc, &window, (HBRUSH)GetStockObject(BLACK_BRUSH));

    HPEN coordPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 0));
    SelectObject(hdc, coordPen);

    int originX = window.right / 2;
    int originY = window.bottom / 2;

    MoveToEx(hdc, 0, originY, &point);
    LineTo(hdc, window.right, originY);

    MoveToEx(hdc, originX, 0, &point);
    LineTo(hdc, originX, window.bottom);

    for (int k = -window.right / 2; k < window.right / 2; k += (int)scale) {
        MoveToEx(hdc, originX + k, originY - 5, &point);
        LineTo(hdc, originX + k, originY + 5);
    }

    for (int k = -window.bottom / 2; k < window.bottom / 2; k += (int)scale) {
        MoveToEx(hdc, originX - 5, originY + k, &point);
        LineTo(hdc, originX + 5, originY + k);
    }

    // Подписи осей
    SetTextColor(hdc, RGB(155, 155, 155));
    SetBkColor(hdc, RGB(0, 0, 0));
    HFONT font = CreateFont(20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
        OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_QUALITY, NULL);
    SelectObject(hdc, font);
    TextOutA(hdc, window.right - 20, originY + 5, "x", 1);
    TextOutA(hdc, originX - 20, 5, "y", 1);

    // --- f1(x) = 5 - 3cos(x) (синяя)
    HPEN bluePen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));  // Синяя ручка для f1
    SelectObject(hdc, bluePen);
    double x = x_start;
    double x_px = originX + x * scale;
    double y1 = 5 - 3 * cos(x);
    double y_px = originY - y1 * scale;
    MoveToEx(hdc, (int)x_px, (int)y_px, &point);

    for (int i = 1; i <= mod; ++i) {
        x = x_start + i * dx;
        x_px = originX + x * scale;
        y1 = 5 - 3 * cos(x);
        y_px = originY - y1 * scale;
        LineTo(hdc, (int)x_px, (int)y_px);
    }
    TextOutA(hdc, (int)x_px + 10, (int)y_px - 10, "f1(x) = 5 - 3cos(x)", strlen("f1(x) = 5 - 3cos(x)"));

    HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));  // Красная ручка для f2
    SelectObject(hdc, redPen);
    x = x_start;
    x_px = originX + x * scale;
    double y2 = sqrt(1 + pow(sin(x), 2));
    y_px = originY - y2 * scale;
    MoveToEx(hdc, (int)x_px, (int)y_px, &point);

    for (int i = 1; i <= mod; ++i) {
        x = x_start + i * dx;
        x_px = originX + x * scale;
        y2 = sqrt(1 + pow(sin(x), 2));
        y_px = originY - y2 * scale;
        LineTo(hdc, (int)x_px, (int)y_px);
    }
    TextOutA(hdc, (int)x_px + 10, (int)y_px + 10, "f2(x) = sqrt(1 + sin^2(x))", strlen("f2(x) = sqrt(1 + sin^2(x))"));

    // Очистка ресурсов
    DeleteObject(bluePen);
    DeleteObject(redPen);
    DeleteObject(coordPen);
    DeleteObject(font);

    while (!_kbhit()) {} // Ожидание клавиши
    ReleaseDC(hWnd, hdc);
}
