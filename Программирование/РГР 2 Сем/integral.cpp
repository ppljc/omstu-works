#include "functions.h"

double f(double x) { return exp(-x) * log(x + 1); }

double rectangleMethod(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; i++) sum += f(a + (i + 0.5) * h);
    return sum * h;
}

double trapezoidMethod(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;
    for (int i = 1; i < n; i++) sum += f(a + i * h);
    return sum * h;
}

void ShowIntegral(HWND hwnd) {
    HDC hdc = GetDC(hwnd);
    RECT window;
    GetClientRect(hwnd, &window);
    FillRect(hdc, &window, (HBRUSH)GetStockObject(BLACK_BRUSH));

    // фон
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

    const double a = 0.0, b = 2.0;
    const int n = 1000;
    const int leftMargin = panelX + 50;
    const int rightMargin = panelX + panelWidth - 50;
    int currentY = panelY + 50;

    SetTextColor(hdc, RGB(255, 255, 255));
    SetTextAlign(hdc, TA_CENTER);
    TextOutA(hdc, panelX + panelWidth / 2, currentY, "Численное интегрирование", 24);
    currentY += 70;

    SetTextColor(hdc, RGB(180, 230, 255));
    TextOutA(hdc, panelX + panelWidth / 2, currentY, "(e^-x)*ln(x+1)dx от 0 до 2", 26);
    SetTextAlign(hdc, TA_LEFT);
    currentY += 60;

    auto DrawRow = [&](const char* label, const string& value, COLORREF color) {
        SetTextColor(hdc, color);
        TextOutA(hdc, leftMargin, currentY, label, (int)strlen(label));

        SetTextAlign(hdc, TA_RIGHT);
        SetTextColor(hdc, RGB(255, 255, 255));
        TextOutA(hdc, rightMargin, currentY, value.c_str(), (int)value.length());
        SetTextAlign(hdc, TA_LEFT);

        currentY += 40;
    };

    double rect = rectangleMethod(a, b, n);
    double trap = trapezoidMethod(a, b, n);

    ostringstream oss;
    oss << n;
    DrawRow("Количество разбиений:", oss.str(), RGB(200, 200, 200));

    oss.str("");
    oss << fixed << setprecision(6) << rect;
    DrawRow("Метод прямоугольников:", oss.str(), RGB(150, 255, 150));

    oss.str("");
    oss << fixed << setprecision(6) << trap;
    DrawRow("Метод трапеций:", oss.str(), RGB(180, 230, 255));

    DeleteObject(hFont);
    ReleaseDC(hwnd, hdc);

    while (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000)) Sleep(100);
}
