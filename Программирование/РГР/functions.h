#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <string>
#include <cmath>
#include <locale>
#include <functional>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <iomanip>
#include <sstream>

using namespace std;

void gotoxy(int x, int y);
void setTextColor(bool selected);
int getConsoleWidth();
int getConsoleHeight();
void drawMenu(const vector<string>& items, int selectedIndex);
void showSubmenu(const string& title);
void runMenu(const vector<string>& menuItems, const vector<function<void()>>& actions);
void setCursorVisible(bool visible);
void clearConsoleBlack();
void setColor(WORD color);
void resetColor();


//void printIntro(HWND hwnd);
void printAbout(HWND hwnd);
//void printFunctionTable(HWND hwnd);
//void printGraph(HWND hwnd);
