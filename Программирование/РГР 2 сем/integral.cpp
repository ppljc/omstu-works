#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"

double fun(double x) {
    return exp(2 * x) * sin(2 * x);
}

double rectangle_rule(double a, double b, int n) {
    double h = (b - a) / n; 
    double sum = 0.0;
    double x;

    for (int i = 0; i < n; i++) {
        x = a + (i + 0.5) * h;  
        sum += fun(x);
    }
    return sum * h;
}

double trapezoidal_rule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (fun(a) + fun(b)) / 2.0;
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += fun(x);
    }
    return sum * h;
}

void printIntegral() {
    HWND hWnd = GetConsoleWindow();
    HDC hdc = GetDC(hWnd);
    RECT window;
    GetClientRect(hWnd, &window);

    const char* table[] = {
        "_________________________________",
        "|    Решение интеграла: (e^(2x))*sin(2x)    |",
        "----------------------------------------------------------",
        "| Интервал                                      [0, Pi] |",
    };
    char num[100], rec[100], tra[100];
    int n = 1000, a = 0, b = M_PI;

    sprintf(num, "| Кол-во промежутков                     %d|", n);
    sprintf(rec, "| Метод прямоугольников       %.6lf|", rectangle_rule(a, b, n));
    sprintf(tra, "| Метод трапеций                     %.6lf|", trapezoidal_rule(a, b, n));

    HFONT font = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_QUALITY, NULL);
    SelectObject(hdc, font);
    SetTextColor(hdc, RGB(150, 10, 10));
    SetBkColor(hdc, RGB(0, 0, 0));
    FillRect(hdc, &window, (HBRUSH)GetStockObject(BLACK_BRUSH));
    while (!_kbhit()) {
        for (int i = 0; i < 4; i++)
            TextOutA(hdc, window.right / 2 - 200, window.bottom / 2 - 105 + 30 * i, table[i], strlen(table[i]));
        TextOutA(hdc, window.right / 2 - 200, window.bottom / 2 + 15, num, strlen(num));
        TextOutA(hdc, window.right / 2 - 200, window.bottom / 2 + 45, rec, strlen(rec));
        TextOutA(hdc, window.right / 2 - 200, window.bottom / 2 + 75, tra, strlen(tra));
        TextOutA(hdc, window.right / 2 - 200, window.bottom / 2 + 105, table[2], strlen(table[2]));
    }
    DeleteObject(font);
    ReleaseDC(hWnd, hdc);
}