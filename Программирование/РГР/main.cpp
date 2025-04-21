#include "functions.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Регистрация класса окна
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"MainWindowClass";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    RegisterClass(&wc);

    // Создание окна
    HWND hwnd = CreateWindow(
        L"MainWindowClass", L"Меню программы",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL, NULL, hInstance, NULL
    );

    // Создание меню
    HMENU hMenu = CreateMenu();
    AppendMenu(hMenu, MF_STRING, 1, L"Заставка");
    AppendMenu(hMenu, MF_STRING, 2, L"Об авторе");
    AppendMenu(hMenu, MF_STRING, 3, L"Таблица");
    AppendMenu(hMenu, MF_STRING, 4, L"График");
    AppendMenu(hMenu, MF_STRING, 5, L"Интеграл");
    AppendMenu(hMenu, MF_STRING, 6, L"Уравнение");
    AppendMenu(hMenu, MF_STRING, 7, L"Выход");

    SetMenu(hwnd, hMenu);

    // Показ окна
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Цикл обработки сообщений
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

// Обработчик сообщений окна
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case 1: /*printIntro(hwnd);*/ break;
        case 2: printAbout(hwnd); break;
        case 3: /*printFunctionTable(hwnd); */break;
        case 4: /*printGraph(hwnd); */break;
        case 5: break; // Интеграл (позже)
        case 6: break; // Уравнение (позже)
        case 7: PostQuitMessage(0); break;
        }
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
