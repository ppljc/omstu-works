#include <windows.h>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "functions.h"

void printFunctionTable(HWND hwnd) {
    // Получаем контекст устройства для рисования
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);

    // Устанавливаем шрифт (моноширинный для таблицы)
    HFONT hFont = CreateFont(18, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FIXED_PITCH, L"Courier New");
    SelectObject(hdc, hFont);

    // Получаем размеры окна
    RECT clientRect;
    GetClientRect(hwnd, &clientRect);
    int width = clientRect.right - clientRect.left;
    int height = clientRect.bottom - clientRect.top;

    // Очищаем фон (белый)
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
    FillRect(hdc, &clientRect, hBrush);
    DeleteObject(hBrush);

    // Параметры таблицы
    const int steps = 20;
    const double from = 0.0;
    const double to = 2 * M_PI;
    const double stepSize = (to - from) / steps;

    // Вычисляем значения функций
    std::vector<double> xs, f1s, f2s;
    for (int i = 0; i <= steps; ++i) {
        double x = from + i * stepSize;
        double f1 = 5 - 3 * cos(x);
        double f2 = sqrt(1 + pow(sin(x), 2));
        xs.push_back(x);
        f1s.push_back(f1);
        f2s.push_back(f2);
    }

    double f1_min = *std::min_element(f1s.begin(), f1s.end());
    double f1_max = *std::max_element(f1s.begin(), f1s.end());
    double f2_min = *std::min_element(f2s.begin(), f2s.end());
    double f2_max = *std::max_element(f2s.begin(), f2s.end());

    // Параметры таблицы
    const int col1 = 8 * 10;  // Шаг (в пикселях, 10 пикселей на символ)
    const int col2 = 14 * 10; // x
    const int col3 = 21 * 10; // f1
    const int col4 = 32 * 10; // f2
    const int tableWidth = col1 + col2 + col3 + col4 + 5 * 10;
    int startX = (width - tableWidth) / 2;
    int startY = 50; // Отступ сверху

    // Заголовок
    std::wstring title = L"Таблица значений функций на отрезке [0; 2Pi] с " + std::to_wstring(steps) + L" шагами";
    TextOut(hdc, startX, startY, title.c_str(), title.length());
    startY += 30;

    // Линия
    auto drawLine = [&](int y) {
        MoveToEx(hdc, startX, y, NULL);
        LineTo(hdc, startX + tableWidth, y);
        };
    drawLine(startY);

    // Шапка таблицы
    startY += 10;
    std::wstring header[] = {
        L"Шаг",
        L"x",
        L"f1(x) = 5 - 3cos(x)",
        L"f2(x) = (1 + (sin(x))^2)^(1/2)"
    };
    int colWidths[] = { col1, col2, col3, col4 };
    int xPos = startX;
    for (int i = 0; i < 4; ++i) {
        TextOut(hdc, xPos + 10, startY, header[i].c_str(), header[i].length());
        xPos += colWidths[i];
        MoveToEx(hdc, xPos, startY - 10, NULL);
        LineTo(hdc, xPos, startY + 20); // Вертикальная линия
    }
    startY += 30;
    drawLine(startY - 10);

    // Заполнение таблицы
    for (int i = 0; i <= steps; ++i) {
        xPos = startX;

        // Шаг
        std::wstring stepStr = std::to_wstring(i);
        TextOut(hdc, xPos + 10, startY, stepStr.c_str(), stepStr.length());
        xPos += col1;
        MoveToEx(hdc, xPos, startY - 10, NULL);
        LineTo(hdc, xPos, startY + 20);

        // x
        std::wstringstream xStr;
        xStr << std::fixed << std::setprecision(4) << xs[i];
        TextOut(hdc, xPos + 10, startY, xStr.str().c_str(), xStr.str().length());
        xPos += col2;
        MoveToEx(hdc, xPos, startY - 10, NULL);
        LineTo(hdc, xPos, startY + 20);

        // f1
        std::wstringstream f1Str;
        f1Str << std::fixed << std::setprecision(6) << f1s[i];
        std::wstring f1Text = f1Str.str();
        if (f1s[i] == f1_min)
            SetTextColor(hdc, RGB(0, 0, 255)); // Синий для минимума
        else if (f1s[i] == f1_max)
            SetTextColor(hdc, RGB(255, 0, 0)); // Красный для максимума
        else
            SetTextColor(hdc, RGB(0, 0, 0)); // Черный по умолчанию
        TextOut(hdc, xPos + (col3 - f1Text.length() * 10) / 2, startY, f1Text.c_str(), f1Text.length());
        xPos += col3;
        MoveToEx(hdc, xPos, startY - 10, NULL);
        LineTo(hdc, xPos, startY + 20);

        // f2
        std::wstringstream f2Str;
        f2Str << std::fixed << std::setprecision(6) << f2s[i];
        std::wstring f2Text = f2Str.str();
        if (f2s[i] == f2_min)
            SetTextColor(hdc, RGB(0, 0, 255)); // Синий для минимума
        else if (f2s[i] == f2_max)
            SetTextColor(hdc, RGB(255, 0, 0)); // Красный для максимума
        else
            SetTextColor(hdc, RGB(0, 0, 0)); // Черный по умолчанию
        TextOut(hdc, xPos + (col4 - f2Text.length() * 10) / 2, startY, f2Text.c_str(), f2Text.length());
        xPos += col4;
        MoveToEx(hdc, xPos, startY - 10, NULL);
        LineTo(hdc, xPos, startY + 20);

        startY += 20;
    }

    // Нижняя линия
    drawLine(startY - 10);

    // Подпись
    startY += 20;
    SetTextColor(hdc, RGB(0, 0, 255));
    TextOut(hdc, startX, startY, L"Синим", 6);
    SetTextColor(hdc, RGB(0, 0, 0));
    TextOut(hdc, startX + 60, startY, L"— минимумы, ", 13);
    SetTextColor(hdc, RGB(255, 0, 0));
    TextOut(hdc, startX + 160, startY, L"красным", 7);
    SetTextColor(hdc, RGB(0, 0, 0));
    TextOut(hdc, startX + 230, startY, L"— максимумы.", 12);

    // Завершаем рисование
    DeleteObject(hFont);
    EndPaint(hwnd, &ps);

    // Ожидание нажатия клавиши (например, ESC)
    MSG msg;
    while (PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_KEYDOWN && msg.wParam == VK_ESCAPE) {
            InvalidateRect(hwnd, NULL, TRUE); // Перерисовываем окно
            break;
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}