#pragma once
#define _USE_MATH_DEFINES
#include <windows.h>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <SDL3/SDL.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

extern const int MENU_ITEMS;
extern const char* menuItems[];

void DrawMenu(HWND hwnd, int selected);
void HandleInput(HWND hwnd, int* selected);
void ShowIntro(HWND hwnd);
void ShowAbout(HWND hwnd);
void ShowSynth(HWND hwnd);
void ShowGame(HWND hwnd);
