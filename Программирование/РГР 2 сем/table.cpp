#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"

void graphCalculate(float* x, double* f1, double* f2) {
    double dx = M_PI / 15;
    x[0] = 0.0;
    for (int i = 0; i < 16; i++)
    {
        f1[i] = exp(-x[i]) + cos(2 * x[i]);
        f2[i] = exp(-2 * x[i]);
        if (i < 15)
            x[i + 1] = x[i] + dx;
    }
}

void printTable() {
    HWND hWnd = GetConsoleWindow();
    HDC hdc = GetDC(hWnd);
    RECT window;
    GetClientRect(hWnd, &window);

    const char* table[] = {
        "______________________________________",
        "| Табуляция функций: f1(x) = e^(-x)+cos(2x) |",
        "|                                  f2(x) = e^(-2x)            |",
        "---------------------------------------------------------",
        "| Интервал                                     [0, 3.14] |",
        "---------------------------------------------------------",
        "|     i     |        x       |      f1(x)     |     f2(x)      |"
    };
    char graph[100], graph1[100], graph2[100];
    HFONT font = CreateFont(20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_QUALITY, NULL);
    SelectObject(hdc, font);
    SetTextColor(hdc, RGB(150, 10, 10));
    SetBkColor(hdc, RGB(0, 0, 0));
    FillRect(hdc, &window, (HBRUSH)GetStockObject(BLACK_BRUSH));

    for (int i = 0; i < 7; i++)
        TextOutA(hdc, window.right / 2 - 133, window.bottom / 2 - 250 + 20 * i, table[i], strlen(table[i]));
    float n = 6.5;
    float x[20]; double f1[20], f2[20], minf1, minf2, maxf1, maxf2;
    graphCalculate(x, f1, f2);
    minf1 = f1[0]; maxf1 = f1[0];
    minf2 = f2[0]; maxf2 = f2[0];
    for (int i = 1; i < 16; i++) {
        if (f1[i] > maxf1)
            maxf1 = f1[i];
        if (f1[i] < minf1)
            minf1 = f1[i];
        if (f2[i] > maxf2)
            maxf2 = f2[i];
        if (f2[i] < minf2)
            minf2 = f2[i];
    }
    for (int i = 0; i < 16; i++) {
        //sprintf(graph, "|   0%d    |   %.5f  |%11.5lf  |%11.5lf  |", i + 1, x[i], f1[i], f2[i]);
        //sprintf(graph, "|   %d    |   %.5f  |%11.5lf  |%11.5lf  |", i + 1, x[i], f1[i], f2[i]);
        if (i < 9)
            sprintf(graph1, "|   0%d    |   %.5f  |", i + 1, x[i]);
        if (i >= 9)
            sprintf(graph1, "|   %d    |   %.5f  |", i + 1, x[i]);

        TextOutA(hdc, window.right / 2 - 133, window.bottom / 2 - 110 + 20 * i, graph1, strlen(graph1));
        if (f1[i] == maxf1)
            SetTextColor(hdc, RGB(0, 200, 0));
        if (f1[i] == minf1)
            SetTextColor(hdc, RGB(0, 0, 200));
        sprintf(graph, "%11.5lf  ", f1[i]);
        TextOutA(hdc, window.right / 2 - 133 + strlen(graph1)*n, window.bottom / 2 - 110 + 20 * i, graph, strlen(graph));

        SetTextColor(hdc, RGB(150, 10, 10));
        TextOutA(hdc, window.right / 2 - 133 + strlen(graph1)*n + strlen(graph)*n, window.bottom / 2 - 110 + 20 * i, "|", strlen("|"));

        if (f2[i] == maxf2)
            SetTextColor(hdc, RGB(0, 200, 0));
        if (f2[i] == minf2)
            SetTextColor(hdc, RGB(0, 0, 200));

        sprintf(graph2, "%11.5lf  ", f2[i]);
        TextOutA(hdc, window.right / 2 - 133 + strlen(graph1)*n + strlen(graph)*n + strlen("|")*n, window.bottom / 2 - 110 + 20 * i, graph2, strlen(graph2));

        SetTextColor(hdc, RGB(150, 10, 10));
        TextOutA(hdc, window.right / 2 - 133 + strlen(graph1)*n + strlen(graph)*n + strlen(graph2)*n  + strlen("|")*n, window.bottom / 2 - 110 + 20 * i, "|", strlen("|"));

        TextOutA(hdc, window.right / 2 - 133, window.bottom / 2 + 210, table[3], strlen(table[3]));
        TextOutA(hdc, window.right / 2 - 133, window.bottom / 2 + 230, "Макс. значения выделены ", strlen("Макс. значения выделены "));
        SetTextColor(hdc, RGB(0, 200, 0));
        TextOutA(hdc, window.right / 2 - 133 + strlen("Макс. значения выделены ") * n + 60 , window.bottom / 2 + 230, "зелёным", strlen("зелёным"));
        SetTextColor(hdc, RGB(150, 10, 10));
        TextOutA(hdc, window.right / 2 - 133, window.bottom / 2 + 250, "Мин. значения выделены ", strlen("Макс. значения выделены "));
        SetTextColor(hdc, RGB(0, 0, 200));
        TextOutA(hdc, window.right / 2 - 133 + strlen("Мин. значения выделены ") * n + 60, window.bottom / 2 + 250, "синим", strlen("синим"));
        SetTextColor(hdc, RGB(150, 10, 10));
    }



    while (!_kbhit()) {
        ;
    }

    DeleteObject(font);
    ReleaseDC(hWnd, hdc);
}