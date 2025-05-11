#include "functions.h"

static double equation(double x) {
    return 0.5 + cos(x) - 2 * x * sin(x);
}

static double bisectionMethod(double a, double b, double epsilon) {
    double c = a;

    while ((b - a) >= epsilon) {
        c = (a + b) / 2;
        if (equation(c) == 0.0) break;
        else if (equation(c) * equation(a) < 0) b = c;
        else a = c;
    }

    return c;
}

static double chordMethod(double a, double b, double epsilon) {
    double x0 = a;
    double x1 = b;
    double x2 = 0;

    do {
        x2 = x1 - (equation(x1) * (x1 - x0)) / (equation(x1) - equation(x0));
        x0 = x1;
        x1 = x2;
    } while (fabs(equation(x2)) > epsilon);

    return x2;
}

void ShowEquation(HWND hwnd) {
    HDC hdc = GetDC(hwnd);
    RECT window;
    GetClientRect(hwnd, &window);
    FillRect(hdc, &window, (HBRUSH)GetStockObject(BLACK_BRUSH));

    const int panelWidth = 700;
    const int panelHeight = 350;
    const int panelX = (window.right - panelWidth) / 2;
    const int panelY = (window.bottom - panelHeight) / 2;

    HBRUSH hBlueBrush = CreateSolidBrush(RGB(50, 100, 180));
    RECT panelRect = { panelX, panelY, panelX + panelWidth, panelY + panelHeight };
    FillRect(hdc, &panelRect, hBlueBrush);
    DeleteObject(hBlueBrush);

    HFONT hFont = CreateFont(26, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
        DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
        DEFAULT_PITCH, L"Arial");
    SelectObject(hdc, hFont);
    SetBkMode(hdc, TRANSPARENT);

    const double epsilon = 0.001;
    double a = 0.0, b = 2.0;
    int currentY = panelY + 50;

    SetTextColor(hdc, RGB(255, 255, 255));
    SetTextAlign(hdc, TA_CENTER);
    TextOutA(hdc, panelX + panelWidth / 2, currentY, "Решение уравнения", 17);
    currentY += 70;

    SetTextColor(hdc, RGB(180, 230, 255));
    TextOutA(hdc, panelX + panelWidth / 2, currentY, "0.5 + cos(x) - 2x*sin(x) = 0", 29);
    currentY += 60;

    while (equation(a) * equation(b) > 0 && b < 10.0) b += 0.5;

    const int leftMargin = panelX + 50;
    const int rightMargin = panelX + panelWidth - 50;

    SetTextAlign(hdc, TA_LEFT);
    SetTextColor(hdc, RGB(200, 200, 200));
    TextOutA(hdc, leftMargin, currentY, "Интервал поиска:", 16);

    SetTextAlign(hdc, TA_RIGHT);
    ostringstream oss;
    oss << "[" << fixed << setprecision(1) << a << ", " << b << "]";
    TextOutA(hdc, rightMargin, currentY, oss.str().c_str(), (int)oss.str().length());
    currentY += 40;

    SetTextAlign(hdc, TA_LEFT);
    SetTextColor(hdc, RGB(150, 255, 150));
    TextOutA(hdc, leftMargin, currentY, "Метод бисекции:", 15);

    SetTextAlign(hdc, TA_RIGHT);
    oss.str("");
    oss << fixed << setprecision(5) << bisectionMethod(a, b, epsilon);
    TextOutA(hdc, rightMargin, currentY, oss.str().c_str(), (int)oss.str().length());
    currentY += 40;

    SetTextAlign(hdc, TA_LEFT);
    SetTextColor(hdc, RGB(180, 230, 255));
    TextOutA(hdc, leftMargin, currentY, "Метод хорд:", 11);

    SetTextAlign(hdc, TA_RIGHT);
    oss.str("");
    oss << fixed << setprecision(5) << chordMethod(a, b, epsilon);
    TextOutA(hdc, rightMargin, currentY, oss.str().c_str(), (int)oss.str().length());

    DeleteObject(hFont);
    ReleaseDC(hwnd, hdc);

    while (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000)) Sleep(100);
}
