#pragma once
#define _USE_MATH_DEFINES
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <locale.h>

void MainMenu();
void ShowMenu(int selected, HDC hdc, HWND hWnd);
void printSelectedMenuItem(const char* items, int i, RECT window);
void printMenuItems(const char* items, int i, RECT window);
void printIntro();
void printAbout();
void printEquation();
void printIntegral();
void printGraph();
void printTable();