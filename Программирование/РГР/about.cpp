#include <windows.h>
#include "functions.h"

void printAbout(HWND hwnd) {
    // Получаем контекст устройства для рисования
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);

    // Устанавливаем шрифт
    HFONT hFont = CreateFont(20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"Arial");
    SelectObject(hdc, hFont);

    // Текст для вывода
    const wchar_t* content[] = {
        L"Информация об авторе",
        L"",
        L"ФИО: Шмидт Антон Владиславович",
        L"Дата рождения: 17.10.2006",
        L"Факультет: ФИТиКС",
        L"Группа: ИВТ - 244"
    };
    int contentSize = sizeof(content) / sizeof(content[0]);

    // Размеры окна
    RECT clientRect;
    GetClientRect(hwnd, &clientRect);
    int width = clientRect.right - clientRect.left;
    int height = clientRect.bottom - clientRect.top;

    // Отрисовка рамки
    int maxLength = 0;
    for (int i = 0; i < contentSize; ++i) {
        SIZE size;
        GetTextExtentPoint32(hdc, content[i], wcslen(content[i]), &size);
        if (size.cx > maxLength) maxLength = size.cx;
    }

    int padding = 20;
    int boxWidth = maxLength + padding * 2;
    int boxHeight = contentSize * 30 + padding * 2;
    int startX = (width - boxWidth) / 2;
    int startY = (height - boxHeight) / 2;

    // Рисуем рамку
    Rectangle(hdc, startX, startY, startX + boxWidth, startY + boxHeight);

    // Выводим текст
    for (int i = 0; i < contentSize; ++i) {
        TextOut(hdc, startX + padding, startY + padding + i * 30, content[i], wcslen(content[i]));
    }

    // Очищаем
    DeleteObject(hFont);
    EndPaint(hwnd, &ps);

    // Ждем нажатия клавиши (например, ESC)
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