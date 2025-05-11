#include "functions.h"

void ShowGraph(HWND hwnd) {
    HDC hdc = GetDC(hwnd);
    RECT window;
    GetClientRect(hwnd, &window);

    // Очищаем экран
    FillRect(hdc, &window, (HBRUSH)GetStockObject(BLACK_BRUSH));

    // Настройки шрифта
    HFONT hFont = CreateFont(20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
        DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
        DEFAULT_PITCH, L"Arial");
    SelectObject(hdc, hFont);
    SetBkMode(hdc, TRANSPARENT);

    // Параметры графика
    const double xMin = 0;
    const double xMax = 2 * M_PI;
    const double yMin = 0;
    const double yMax = 8;

    const int margin = 50;
    const int graphWidth = window.right - 2 * margin;
    const int graphHeight = window.bottom - 2 * margin;
    const int originX = margin;
    const int originY = window.bottom - margin;

    // Рисуем оси координат (белые)
    HPEN hAxisPen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
    SelectObject(hdc, hAxisPen);

    // Ось X
    MoveToEx(hdc, originX, originY, NULL);
    LineTo(hdc, originX + graphWidth, originY);
    // Ось Y
    MoveToEx(hdc, originX, originY, NULL);
    LineTo(hdc, originX, originY - graphHeight);

    // Стрелки осей
    // Ось X
    MoveToEx(hdc, originX + graphWidth, originY, NULL);
    LineTo(hdc, originX + graphWidth - 10, originY - 5);
    MoveToEx(hdc, originX + graphWidth, originY, NULL);
    LineTo(hdc, originX + graphWidth - 10, originY + 5);
    // Ось Y
    MoveToEx(hdc, originX, originY - graphHeight, NULL);
    LineTo(hdc, originX - 5, originY - graphHeight + 10);
    MoveToEx(hdc, originX, originY - graphHeight, NULL);
    LineTo(hdc, originX + 5, originY - graphHeight + 10);

    // Подписи осей
    SetTextColor(hdc, RGB(255, 255, 255));
    TextOutA(hdc, originX + graphWidth + 20, originY - 10, "x", 1);
    TextOutA(hdc, originX - 5, originY - graphHeight - 40, "y", 1);

    // Разметка осей
    HPEN hGridPen = CreatePen(PS_DOT, 1, RGB(100, 100, 100));
    SelectObject(hdc, hGridPen);

    // Разметка оси X (Pi/2, Pi, 3Pi/2, 2Pi)
    const char* xLabels[] = { "0", "Pi/2", "Pi", "3Pi/2", "2Pi" };
    double xValues[] = { 0, M_PI / 2, M_PI, 3 * M_PI / 2, 2 * M_PI };

    for (int i = 0; i < 5; i++) {
        int xPos = originX + (xValues[i] / (2 * M_PI)) * graphWidth;
        MoveToEx(hdc, xPos, originY, NULL);
        LineTo(hdc, xPos, originY - graphHeight);

        TextOutA(hdc, xPos - 15, originY + 5, xLabels[i], (int)strlen(xLabels[i]));
    }

    // Разметка оси Y
    for (int i = 1; i <= 8; i++) {
        int yPos = originY - (i / 8.0) * graphHeight;
        MoveToEx(hdc, originX, yPos, NULL);
        LineTo(hdc, originX + graphWidth, yPos);

        ostringstream oss;
        oss << i;
        string label = oss.str();
        TextOutA(hdc, originX - 20, yPos - 10, label.c_str(), (int)label.length());
    }

    // Рисуем графики функций
    const int points = 500;
    POINT y1Points[points], y2Points[points];

    for (int i = 0; i < points; i++) {
        double x = xMin + (xMax - xMin) * i / (points - 1);
        double y1 = 5 - 3 * cos(x);
        double y2 = sqrt(1 + pow(sin(x), 2));

        y1Points[i].x = originX + (x / (2 * M_PI)) * graphWidth;
        y1Points[i].y = originY - ((y1 - yMin) / (yMax - yMin)) * graphHeight;

        y2Points[i].x = originX + (x / (2 * M_PI)) * graphWidth;
        y2Points[i].y = originY - ((y2 - yMin) / (yMax - yMin)) * graphHeight;
    }

    // График y1 (красный)
    HPEN hY1Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
    SelectObject(hdc, hY1Pen);
    Polyline(hdc, y1Points, points);

    // График y2 (синий)
    HPEN hY2Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hY2Pen);
    Polyline(hdc, y2Points, points);

    // Подписи графиков
    SetTextColor(hdc, RGB(255, 0, 0));
    TextOutA(hdc, originX + 100, originY - graphHeight + 30,
        "y1 = 5 - 3*cos(x)", 17);

    SetTextColor(hdc, RGB(0, 0, 255));
    TextOutA(hdc, originX + 100, originY - graphHeight + 60,
        "y2 = sqrt(1 + sin(x)^2)", 23);

    // Освобождаем ресурсы
    DeleteObject(hFont);
    DeleteObject(hAxisPen);
    DeleteObject(hGridPen);
    DeleteObject(hY1Pen);
    DeleteObject(hY2Pen);
    ReleaseDC(hwnd, hdc);

    // Ожидаем Esc
    while (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000)) {
        Sleep(100);
    }
}
