#include "functions.h"

void ShowIntro(HWND hwnd) {
    HDC hdc = GetDC(hwnd);
    RECT window;
    GetClientRect(hwnd, &window);

    // Цвета для анимации
    const COLORREF colors[] = {
        RGB(255, 50, 50),   // Красный
        RGB(50, 255, 50),   // Зеленый
        RGB(50, 50, 255),   // Синий
        RGB(255, 255, 50),  // Желтый
        RGB(255, 50, 255),  // Пурпурный
        RGB(50, 255, 255)   // Голубой
    };

    // Параметры анимации
    float angle = 0.0f;
    float scale = 0.5f;
    float distanceMultiplier = 2.5f; // Увеличиваем базовое расстояние
    bool scaleIncreasing = true;
    const float rotationSpeed = 0.02f;
    const float scaleSpeed = 0.008f; // Увеличиваем скорость масштабирования

    // Основной цикл анимации
    while (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000)) {
        // Очищаем экран
        FillRect(hdc, &window, (HBRUSH)GetStockObject(BLACK_BRUSH));

        // Центр экрана
        const int centerX = window.right / 2;
        const int centerY = window.bottom / 2;

        // Обновляем параметры анимации
        angle += rotationSpeed;
        if (scaleIncreasing) {
            scale += scaleSpeed;
            if (scale > 1.5f) scaleIncreasing = false; // Увеличиваем максимальный масштаб
        }
        else {
            scale -= scaleSpeed;
            if (scale < 0.4f) scaleIncreasing = true; // Уменьшаем минимальный масштаб
        }

        // Рисуем вращающиеся фигуры
        for (int i = 0; i < 6; i++) {
            float currentAngle = angle + i * (2 * 3.14159f / 6);
            // Увеличиваем расстояние от центра и добавляем индивидуальное смещение для каждой фигуры
            int distance = (100 + i * 30) * scale * distanceMultiplier;

            // Добавляем эллиптическую траекторию (разный радиус по X и Y)
            int x = centerX + distance * 1.5f * cos(currentAngle);
            int y = centerY + distance * 0.8f * sin(currentAngle);

            // Размер фигур также зависит от положения
            int size = 40 + 30 * sin(angle * 2 + i);

            // Выбираем кисть с текущим цветом
            HBRUSH hBrush = CreateSolidBrush(colors[i]);
            HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);

            // Рисуем разные фигуры с изменяющимся размером
            if (i % 2 == 0) {
                // Круги с переменным размером
                Ellipse(hdc, x - size, y - size, x + size, y + size);
            }
            else {
                // Квадраты с вращением (ромбы)
                POINT diamond[4] = {
                    {x, y - size},
                    {x + size, y},
                    {x, y + size},
                    {x - size, y}
                };
                Polygon(hdc, diamond, 4);
            }

            // Восстанавливаем кисть
            SelectObject(hdc, hOldBrush);
            DeleteObject(hBrush);
        }

        // Текст заставки с эффектом пульсации
        HFONT hFont = CreateFont(48 + 10 * sin(angle * 3), 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
            DEFAULT_PITCH, L"Arial");
        SelectObject(hdc, hFont);
        SetTextColor(hdc, RGB(255, 255, 255));
        SetBkMode(hdc, TRANSPARENT);
        SetTextAlign(hdc, TA_CENTER);

        DeleteObject(hFont);

        // Задержка для плавности анимации
        Sleep(16); // ~60 FPS

        // Обновляем экран
        GdiFlush();
    }

    ReleaseDC(hwnd, hdc);
}
