#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"

void printGraph() {
	HWND hWnd = GetConsoleWindow();
	HDC hdc = GetDC(hWnd);
	RECT window;
	GetClientRect(hWnd, &window);
	POINT point;
	HPEN coord_plane = CreatePen(PS_SOLID, 1, RGB(255, 255, 0));
	FillRect(hdc, &window, (HBRUSH)GetStockObject(BLACK_BRUSH));
	SelectObject(hdc, coord_plane);
	HFONT font = CreateFont(20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_QUALITY, NULL);
	SelectObject(hdc, font);
	SetTextColor(hdc, RGB(155, 155, 155));
	SetBkColor(hdc, RGB(0, 0, 0));

	double n = 100;

	MoveToEx(hdc, window.right / 2, window.bottom / 2, &point);
	for (int k = 0; k < window.right / 2 + n; k += n) {
		LineTo(hdc, window.right / 2 + k, window.bottom / 2);
		MoveToEx(hdc, window.right / 2 + k, window.bottom / 2 - 10, &point);
		LineTo(hdc, window.right / 2 + k, window.bottom / 2 + 10);
		MoveToEx(hdc, window.right / 2 + k, window.bottom / 2, &point);
	}
	MoveToEx(hdc, window.right / 2, window.bottom / 2, &point);
	for (int k = 0; k < window.bottom / 2 + n; k += n) {
		LineTo(hdc, window.right / 2, window.bottom / 2 + k);
		MoveToEx(hdc, window.right / 2 - 10, window.bottom / 2 + k, &point);
		LineTo(hdc, window.right / 2 + 10, window.bottom / 2 + k);
		MoveToEx(hdc, window.right / 2, window.bottom / 2 + k, &point);
	}
	MoveToEx(hdc, window.right / 2, window.bottom / 2, &point);
	for (int k = 0; k < window.right / 2 + n; k += n) {
		LineTo(hdc, window.right / 2 - k, window.bottom / 2);
		MoveToEx(hdc, window.right / 2 - k, window.bottom / 2 - 10, &point);
		LineTo(hdc, window.right / 2 - k, window.bottom / 2 + 10);
		MoveToEx(hdc, window.right / 2 - k, window.bottom / 2, &point);
	}
	for (int k = 0; k < window.bottom / 2 + n; k += n) {
		LineTo(hdc, window.right / 2, window.bottom / 2 - k);
		MoveToEx(hdc, window.right / 2 - 10, window.bottom / 2 - k, &point);
		LineTo(hdc, window.right / 2 + 10, window.bottom / 2 - k);
		MoveToEx(hdc, window.right / 2, window.bottom / 2 - k, &point);
	}
	TextOutA(hdc, window.right - 30, window.bottom / 2 + 10, "x", strlen("x"));
	TextOutA(hdc, window.right / 2 - 30, window.top + 30, "y", strlen("y"));

	DeleteObject(coord_plane);
	HPEN graph1 = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	SelectObject(hdc, graph1);

	int mod = 1000;
	double dx = M_PI / (mod - 1);
	double x = 0.0;
	double x_mod, y_mod;
	double f1 = 5 - 3 * cos(x);
	char func1[100], func2[100];
	sprintf(func1, "f1(x) = 5 - 3*cos(x)");
	sprintf(func2, "f2(x) = (1 + (sin(x))^2)^(1/2)");

	MoveToEx(hdc, window.right / 2, window.bottom / 2 - n * f1, &point);
	for (int i = 0; i < mod; i++) {
		f1 = 5 - 3 * cos(x);
		x_mod = n * x + window.right / 2;
	    y_mod = window.bottom / 2 - n * f1;

		LineTo(hdc, (int)x_mod, (int)y_mod);
		MoveToEx(hdc, (int)x_mod, (int)y_mod, &point);
		
		x += dx;
	}
	SetTextColor(hdc, RGB(255, 0, 0));
	TextOutA(hdc, x_mod, y_mod + 10, func1, strlen(func1));
	DeleteObject(graph1);
	HPEN graph2 = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	SelectObject(hdc, graph2);

	x = 0.0;
	double f2 = sqrt(1 + pow(sin(x), 2));
	MoveToEx(hdc, window.right / 2, window.bottom / 2 - n * f2, &point);
	for (int i = 0; i < mod; i++) {
		f2 = sqrt(1 + pow(sin(x), 2));
		x_mod = n * x + window.right / 2;
		y_mod = window.bottom / 2 - n * f2;

		LineTo(hdc, (int)x_mod, (int)y_mod);
		MoveToEx(hdc, (int)x_mod, (int)y_mod, &point);

		x += dx;
	}
	SetTextColor(hdc, RGB(0, 0, 255));
	TextOutA(hdc, x_mod, y_mod + 10, func2, strlen(func2));
	DeleteObject(graph2);
	DeleteObject(font);

	while (!_kbhit()) {
		;
	}

	ReleaseDC(hWnd, hdc);
}