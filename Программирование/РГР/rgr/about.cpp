#include "functions.h"

void printAbout() {
	HWND hWnd = GetConsoleWindow();
	HDC hdc = GetDC(hWnd);
	RECT window;
	GetClientRect(hWnd, &window);

	const char* intro[] = {
		"_________________________________",
		"|            Информация об авторе:            |",
		"----------------------------------------------------------",
		"| ФИО          Клексин Роман Сергеевич |",
		"| Факультет                              ФИТИКС |",
		"| Группа                                    ИВТ-244 |",
		"| Дата рождения                   07.09.2006 |",
		"----------------------------------------------------------"
	};

	HFONT font = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_QUALITY, NULL);
	SelectObject(hdc, font);
	SetTextColor(hdc, RGB(150, 10, 10));
	SetBkColor(hdc, RGB(0, 0, 0));
	FillRect(hdc, &window, (HBRUSH)GetStockObject(BLACK_BRUSH));
	while (!_kbhit()) {
		for (int i = 0; i < 8; i++)
			TextOutA(hdc, window.right / 2 - 200, window.bottom / 2 - 105 + 30 * i, intro[i], strlen(intro[i]));
	}
	DeleteObject(font);
	ReleaseDC(hWnd, hdc);
}