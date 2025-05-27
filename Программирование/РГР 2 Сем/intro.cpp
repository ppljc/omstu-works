#include "functions.h"

void ShowIntro(HWND hwnd) {
    HDC hdc = GetDC(hwnd);
    RECT window;
    GetClientRect(hwnd, &window);

    const COLORREF colors[] = {
        RGB(255, 50, 50),   // красный
        RGB(50, 255, 50),   // зеленый
        RGB(50, 50, 255),   // синий
        RGB(255, 255, 50),  // желтый
        RGB(255, 50, 255),  // пурпурный
        RGB(50, 255, 255),  // голубой
        RGB(50, 200, 100),  // зеленый
        RGB(90, 90, 150),  // нежно-фиолетовый
        RGB(160, 10, 50),  // малиновый
        RGB(10, 100, 200)  // синий
    };

    float angle = 0.0f;
    float scale = 0.5f;
    float distanceMultiplier = 2.5f;
    bool scaleIncreasing = true;
    const float rotationSpeed = 0.02f;
    const float scaleSpeed = 0.008f;

    while (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000)) {
        FillRect(hdc, &window, (HBRUSH)GetStockObject(BLACK_BRUSH));

        const int centerX = window.right / 2;
        const int centerY = window.bottom / 2;

        angle += rotationSpeed;
        if (scaleIncreasing) {
            scale += scaleSpeed;
            if (scale > 1.5f) scaleIncreasing = false;
        }
        else {
            scale -= scaleSpeed;
            if (scale < 0.4f) scaleIncreasing = true;
        }

        for (int i = 0; i < 10; i++) {
            float currentAngle = angle + i * (2 * M_PI / 6);
            int distance = (100 + i * 30) * scale * distanceMultiplier;

            int x = centerX + distance * 1.5f * cos(currentAngle);
            int y = centerY + distance * 0.8f * sin(currentAngle);

            int size = 40 + 30 * sin(angle * 2 + i);

            HBRUSH hBrush = CreateSolidBrush(colors[i]);
            HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);

            if (i % 2 == 0) {
                Ellipse(hdc, x - size, y - size, x + size, y + size);
            }
            else {
                POINT diamond[4] = {
                    {x, y - size},
                    {x + size, y},
                    {x, y + size},
                    {x - size, y}
                };
                Polygon(hdc, diamond, 4);
            }

            SelectObject(hdc, hOldBrush);
            DeleteObject(hBrush);
        }

        Sleep(16);

        GdiFlush();
    }

    ReleaseDC(hwnd, hdc);
}
