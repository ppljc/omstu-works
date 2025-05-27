#include "functions.h"

void ShowTable(HWND hwnd) {
    HDC hdc = GetDC(hwnd);
    RECT window;
    GetClientRect(hwnd, &window);

    FillRect(hdc, &window, (HBRUSH)GetStockObject(BLACK_BRUSH));

    HFONT hFont = CreateFont(24, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
        DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
        DEFAULT_PITCH, L"Courier New");
    SelectObject(hdc, hFont);
    SetBkMode(hdc, TRANSPARENT);

    SetTextColor(hdc, RGB(255, 255, 255));
    TextOutA(hdc, window.right / 2 - 300, 50, "Таблица значений функций:", 24);
    TextOutA(hdc, window.right / 2 - 300, 80, "y1 = 5 - 3*cos(x)", 17);
    TextOutA(hdc, window.right / 2 - 300, 110, "y2 = sqrt(1 + sin(x)^2)", 23);
    TextOutA(hdc, window.right / 2 - 300, 140, "Интервал: [0, 2Pi], шагов: 20", 30);

    const int rows = 21;
    const int cols = 4;
    const int cellWidth = 150;
    const int cellHeight = 30;
    const int tableWidth = cols * cellWidth;
    const int tableHeight = rows * cellHeight;
    const int tableX = (window.right - tableWidth) / 2;
    const int tableY = 180;

    struct TableData {
        int step;
        double x;
        double y1;
        double y2;
    } data[20];

    double minY1 = 1000, maxY1 = -1000;
    double minY2 = 1000, maxY2 = -1000;

    for (int i = 0; i < 20; i++) {
        data[i].step = i + 1;
        data[i].x = (2 * M_PI * i) / 19.0;
        data[i].y1 = 5 - 3 * cos(data[i].x);
        data[i].y2 = sqrt(1 + pow(sin(data[i].x), 2));

        if (data[i].y1 < minY1) minY1 = data[i].y1;
        if (data[i].y1 > maxY1) maxY1 = data[i].y1;
        if (data[i].y2 < minY2) minY2 = data[i].y2;
        if (data[i].y2 > maxY2) maxY2 = data[i].y2;
    }

    HPEN hWhitePen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    HPEN hOldPen = (HPEN)SelectObject(hdc, hWhitePen);

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            RECT cell = {
                tableX + col * cellWidth,
                tableY + row * cellHeight,
                tableX + (col + 1) * cellWidth,
                tableY + (row + 1) * cellHeight
            };

            MoveToEx(hdc, cell.left, cell.top, NULL);
            LineTo(hdc, cell.right, cell.top);
            LineTo(hdc, cell.right, cell.bottom);
            LineTo(hdc, cell.left, cell.bottom);
            LineTo(hdc, cell.left, cell.top);

            if (row == 0) {
                SetTextColor(hdc, RGB(255, 255, 255));
                const char* headers[] = { "Шаг", "X", "y1", "y2" };
                TextOutA(hdc, cell.left + 10, cell.top + 5, headers[col], (int)strlen(headers[col]));
            }
            else {
                TableData& item = data[row - 1];
                ostringstream oss;
                oss << fixed << setprecision(4);

                switch (col) {
                    case 0: oss << item.step; break;
                    case 1: oss << item.x; break;
                    case 2:
                        oss << item.y1;
                        if (item.y1 == minY1) {
                            SetTextColor(hdc, RGB(0, 0, 255));
                        }
                        else if (item.y1 == maxY1) {
                            SetTextColor(hdc, RGB(255, 0, 0));
                        }
                        else {
                            SetTextColor(hdc, RGB(255, 255, 255));
                        }
                        break;
                    case 3:
                        oss << item.y2;
                        if (item.y2 == minY2) {
                            SetTextColor(hdc, RGB(0, 0, 255));
                        }
                        else if (item.y2 == maxY2) {
                            SetTextColor(hdc, RGB(255, 0, 0));
                        }
                        else {
                            SetTextColor(hdc, RGB(255, 255, 255));
                        }
                        break;
                }

                string text = oss.str();
                TextOutA(hdc, cell.left + 10, cell.top + 5, text.c_str(), (int)text.length());
                SetTextColor(hdc, RGB(255, 255, 255));
            }
        }
    }

    SelectObject(hdc, hOldPen);
    DeleteObject(hWhitePen);

    SetTextColor(hdc, RGB(255, 0, 0));
    TextOutA(hdc, tableX, tableY + rows * cellHeight + 20, "Красный - максимум", 18);
    SetTextColor(hdc, RGB(0, 0, 255));
    TextOutA(hdc, tableX, tableY + rows * cellHeight + 50, "Синий - минимум", 15);

    DeleteObject(hFont);
    ReleaseDC(hwnd, hdc);

    while (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000)) Sleep(100);
}
