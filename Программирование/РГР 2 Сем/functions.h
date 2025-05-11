#pragma once
#define _USE_MATH_DEFINES
#include <windows.h>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

extern const int MENU_ITEMS;
extern const char* menuItems[];

void DrawMenu(HWND hwnd, int selected);
void HandleInput(HWND hwnd, int* selected);
void ShowAbout(HWND hwnd);
void ShowTable(HWND hwnd);
void ShowGraph(HWND hwnd);
void ShowIntegral(HWND hwnd);
void ShowEquation(HWND hwnd);
void ShowIntro(HWND hwnd);
