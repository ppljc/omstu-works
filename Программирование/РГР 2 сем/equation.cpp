#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"

double f(double x) {
    return tan(x) - exp(x + 1);
}

double bisection(double a, double b, double e) {
    double c;
    do {
        c = (a + b) / 2;
        if (fabs(f(c)) < e)
            break;
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    } while ((b - a) >= e);
    return c;
}

double secant(double a, double b, double e) {
    double c;
    do {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        if (fabs(f(c)) < e)
            break;
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    } while (fabs(b - a) >= e);
    return c;
}

void printEquation() {
    HWND hWnd = GetConsoleWindow();
    HDC hdc = GetDC(hWnd);
    RECT window;
    GetClientRect(hWnd, &window);

    const char* table[] = {
        "_________________________________",
        "|   Решение уравнения: tg(x)-e^(x+1)=0  |",
        "----------------------------------------------------------",
        "| Интервал                                      [2, 3] |",
    };
    char eps[100], bis[100], sec[100];
    double e = 0.0001; int a = 2, b = 3;

    sprintf(eps, "| Точность                                   %.5lf|", e);
    sprintf(bis, "| Метод бисекции                       %.5lf|", bisection(a, b, e));
    sprintf(sec, "| Метод хорд                              %.5lf|", secant(a, b, e));

    HFONT font = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_QUALITY, NULL);
    SelectObject(hdc, font);
    SetTextColor(hdc, RGB(150, 10, 10));
    SetBkColor(hdc, RGB(0, 0, 0));
    FillRect(hdc, &window, (HBRUSH)GetStockObject(BLACK_BRUSH));
    while (!_kbhit()) {
        for (int i = 0; i < 4; i++)
            TextOutA(hdc, window.right / 2 - 200, window.bottom / 2 - 105 + 30 * i, table[i], strlen(table[i]));
        TextOutA(hdc, window.right / 2 - 200, window.bottom / 2 + 15, eps, strlen(eps));
        TextOutA(hdc, window.right / 2 - 200, window.bottom / 2 + 45, bis, strlen(bis));
        TextOutA(hdc, window.right / 2 - 200, window.bottom / 2 + 75, sec, strlen(sec));
        TextOutA(hdc, window.right / 2 - 200, window.bottom / 2 + 105, table[2], strlen(table[2]));
    }
    DeleteObject(font);
    ReleaseDC(hWnd, hdc);
}
