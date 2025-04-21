#include <windows.h>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include "functions.h"

void printIntro(HWND hwnd) {
    // Получаем контекст устройства для рисования
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);

    // Устанавливаем шрифт (моноширинный для логотипа)
    HFONT hFont = CreateFont(20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FIXED_PITCH, L"Courier New");
    SelectObject(hdc, hFont);

    // Получаем размеры окна
    RECT clientRect;
    GetClientRect(hwnd, &clientRect);
    int width = clientRect.right - clientRect.left;
    int height = clientRect.bottom - clientRect.top;

    // Очищаем фон (черный)
    HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
    FillRect(hdc, &clientRect, hBrush);
    DeleteObject(hBrush);

    // Логотип
    std::vector<std::wstring> logo = {
        L" ____   ____   _          _  ____ ",
        L"|  _ \\ |  _ \\ | |        | ||  __\\",
        L"| |_) || |_) || |    _   | || |   ",
        L"|  __/ |  __/ | |__ / \\ _| || |__ ",
        L"|_|    |_|    |____|\\ _____||____/"
    };

    int logoHeight = logo.size();
    int logoWidth = logo[0].length();
    int startY = (height - logoHeight * 20) / 2; // 20 - высота шрифта
    int startX = (width - logoWidth * 10) / 2;   // 10 - примерная ширина символа

    // Набор символов для анимации
    std::wstring charset = L"!@#$%^&*()_+-=[]{}|;:<>?/\\";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, charset.size() - 1);

    // Анимация (20 шагов)
    for (int step = 0; step < 20; ++step) {
        // Очищаем область логотипа
        RECT logoRect = { startX, startY, startX + logoWidth * 10, startY + logoHeight * 20 };
        FillRect(hdc, &logoRect, (HBRUSH)GetStockObject(BLACK_BRUSH));

        // Отрисовка символов
        for (int y = 0; y < logoHeight; ++y) {
            for (int x = 0; x < logoWidth; ++x) {
                if (logo[y][x] == L' ') continue;

                wchar_t symbol = (step > 15) ? logo[y][x] : charset[dis(gen)];
                TextOut(hdc, startX + x * 10, startY + y * 20, &symbol, 1);
            }
        }

        // Обновляем окно
        InvalidateRect(hwnd, &logoRect, FALSE);
        UpdateWindow(hwnd);

        // Задержка
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    // Окончательный логотип
    RECT logoRect = { startX, startY, startX + logoWidth * 10, startY + logoHeight * 20 };
    FillRect(hdc, &logoRect, (HBRUSH)GetStockObject(BLACK_BRUSH));
    for (int y = 0; y < logoHeight; ++y) {
        TextOut(hdc, startX, startY + y * 20, logo[y].c_str(), logo[y].length());
    }

    // Завершаем рисование
    DeleteObject(hFont);
    EndPaint(hwnd, &ps);

    // Задержка 1.2 секунды
    std::this_thread::sleep_for(std::chrono::milliseconds(1200));

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