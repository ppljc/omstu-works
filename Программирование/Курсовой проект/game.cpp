#include "functions.h"

const int GRID_SIZE = 10;

const COLORREF COLOR_HIGHLIGHT_COL = RGB(0, 0, 255);
const COLORREF COLOR_HIGHLIGHT_ROW = RGB(255, 0, 0);
const COLORREF COLOR_HIGHLIGHT_CELL = RGB(100, 100, 100);
const COLORREF COLOR_GRID_LINE = RGB(200, 200, 200);

static int ships[GRID_SIZE][GRID_SIZE];
static int shots[GRID_SIZE][GRID_SIZE];

static int selectedCol = -1;
static int selectedRow = -1;

static const wchar_t COLUMN_LETTERS[GRID_SIZE] = {
    L'А', L'Б', L'В', L'Г', L'Д', L'Е', L'Ж', L'З', L'И', L'К'
};

void GenerateRandomShips() {
    for (int y = 0; y < GRID_SIZE; ++y) {
        for (int x = 0; x < GRID_SIZE; ++x) {
            ships[y][x] = 0;
            shots[y][x] = 0;
        }
    }

    const int shipSizes[] = {
        1, 1, 1, 1,
        2, 2, 2,
        3, 3,
        4
    };
    const int numShips = sizeof(shipSizes) / sizeof(shipSizes[0]);

    srand((unsigned)time(NULL));

    auto canPlaceAt = [&](int x0, int y0, int length, int orientation) {
        for (int k = 0; k < length; ++k) {
            int xx = x0 + (orientation == 0 ? k : 0);
            int yy = y0 + (orientation == 1 ? k : 0);

            if (ships[yy][xx] != 0)
                return false;

            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    int nx = xx + dx;
                    int ny = yy + dy;
                    if (nx >= 0 && nx < GRID_SIZE && ny >= 0 && ny < GRID_SIZE) {
                        if (ships[ny][nx] != 0)
                            return false;
                    }
                }
            }
        }
        return true;
    };

    for (int si = 0; si < numShips; ++si) {
        int length = shipSizes[si];
        bool placed = false;

        while (!placed) {
            int orientation = rand() % 2;
            int x0, y0;

            if (orientation == 0) {
                x0 = rand() % (GRID_SIZE - length + 1);
                y0 = rand() % GRID_SIZE;
            }
            else {
                x0 = rand() % GRID_SIZE;
                y0 = rand() % (GRID_SIZE - length + 1);
            }

            if (!canPlaceAt(x0, y0, length, orientation))
                continue;

            for (int k = 0; k < length; ++k) {
                int xx = x0 + (orientation == 0 ? k : 0);
                int yy = y0 + (orientation == 1 ? k : 0);
                ships[yy][xx] = 1;
            }
            placed = true;
        }
    }
}

void DrawGame(HWND hwnd) {
    HDC hdc = GetDC(hwnd);

    RECT window;
    GetClientRect(hwnd, &window);
    FillRect(hdc, &window, (HBRUSH)GetStockObject(BLACK_BRUSH));

    int winWidth = window.right;
    int winHeight = window.bottom;

    int gridSizePx = winHeight / 2;
    if (gridSizePx > winWidth) {
        gridSizePx = winWidth;
    }

    int offsetX = (winWidth - gridSizePx) / 2;
    int offsetY = (winHeight - gridSizePx) / 2;

    int cellSize = gridSizePx / GRID_SIZE;

    {
        const wchar_t* lines[] = {
            L"Игра \"Морской Бой\"",
            L"Выберите клетку с помощью клавиш, соответствующих координатам на поле",
            L"Enter - выстрелить",
            L"Space - отмена",
            L"TAB - сдаться"
        };
        const int numLines = sizeof(lines) / sizeof(lines[0]);

        HFONT hInstrFont = CreateFont(
            26, 0, 0, 0, FW_NORMAL,
            FALSE, FALSE, FALSE,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_DONTCARE,
            L"Arial"
        );
        HFONT hOldFont = (HFONT)SelectObject(hdc, hInstrFont);
        SetTextColor(hdc, RGB(255, 255, 255));
        SetBkMode(hdc, TRANSPARENT);
        SetTextAlign(hdc, TA_CENTER | TA_TOP);

        TEXTMETRIC tm;
        GetTextMetrics(hdc, &tm);
        int lineHeight = tm.tmHeight;

        int totalHeight = lineHeight * numLines;

        int startY = offsetY - totalHeight - 40;
        if (startY < 10) {
            startY = 10;
        }

        for (int i = 0; i < numLines; ++i) {
            int textY = startY + i * lineHeight;
            TextOutW(hdc, winWidth / 2, textY, lines[i], (int)wcslen(lines[i]));
        }

        SelectObject(hdc, hOldFont);
        DeleteObject(hInstrFont);
    }

    if (selectedCol >= 0) {
        HBRUSH hBrushCol = CreateSolidBrush(COLOR_HIGHLIGHT_COL);
        RECT rcCol = {
            offsetX + selectedCol * cellSize,
            offsetY,
            offsetX + (selectedCol + 1) * cellSize,
            offsetY + gridSizePx
        };
        FillRect(hdc, &rcCol, hBrushCol);
        DeleteObject(hBrushCol);
    }

    if (selectedRow >= 0) {
        HBRUSH hBrushRow = CreateSolidBrush(COLOR_HIGHLIGHT_ROW);
        RECT rcRow = {
            offsetX,
            offsetY + selectedRow * cellSize,
            offsetX + gridSizePx,
            offsetY + (selectedRow + 1) * cellSize
        };
        FillRect(hdc, &rcRow, hBrushRow);
        DeleteObject(hBrushRow);
    }

    if (selectedCol >= 0 && selectedRow >= 0) {
        HBRUSH hBrushCell = CreateSolidBrush(COLOR_HIGHLIGHT_CELL);
        RECT rcCell = {
            offsetX + selectedCol * cellSize,
            offsetY + selectedRow * cellSize,
            offsetX + (selectedCol + 1) * cellSize,
            offsetY + (selectedRow + 1) * cellSize
        };
        FillRect(hdc, &rcCell, hBrushCell);
        DeleteObject(hBrushCell);
    }

    HPEN hPenGrid = CreatePen(PS_SOLID, 1, COLOR_GRID_LINE);
    HPEN hOldPen = (HPEN)SelectObject(hdc, hPenGrid);
    for (int i = 0; i <= GRID_SIZE; ++i) {
        MoveToEx(hdc, offsetX + i * cellSize, offsetY, NULL);
        LineTo(hdc, offsetX + i * cellSize, offsetY + gridSizePx);
        
        MoveToEx(hdc, offsetX, offsetY + i * cellSize, NULL);
        LineTo(hdc, offsetX + gridSizePx, offsetY + i * cellSize);
    }
    SelectObject(hdc, hOldPen);
    DeleteObject(hPenGrid);

    HFONT hLabelFont = CreateFont(
        18, 0, 0, 0, FW_BOLD,
        FALSE, FALSE, FALSE,
        DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
        DEFAULT_PITCH | FF_DONTCARE,
        L"Arial"
    );
    HFONT hOldFont2 = (HFONT)SelectObject(hdc, hLabelFont);
    SetTextColor(hdc, RGB(255, 255, 255));
    SetBkMode(hdc, TRANSPARENT);
    SetTextAlign(hdc, TA_CENTER | TA_TOP);

    for (int x = 0; x < GRID_SIZE; ++x) {
        wchar_t letter = COLUMN_LETTERS[x];
        SIZE textSize;
        GetTextExtentPoint32W(hdc, &letter, 1, &textSize);

        int centerX = offsetX + x * cellSize + cellSize / 2;
        int textX = centerX;
        int textY = offsetY - textSize.cy - 4;
        if (textY < 0) {
            textY = offsetY + 2;
        }
        TextOutW(hdc, textX, textY, &letter, 1);
    }

    SetTextAlign(hdc, TA_RIGHT | TA_TOP);
    for (int y = 0; y < GRID_SIZE; ++y) {
        wchar_t buf[3] = { 0 };
        int number = y + 1;
        if (number < 10) {
            buf[0] = L'0' + number;
            buf[1] = L'\0';
        }
        else {
            buf[0] = L'1';
            buf[1] = L'0';
            buf[2] = L'\0';
        }

        SIZE textSize;
        GetTextExtentPoint32W(hdc, buf, wcslen(buf), &textSize);

        int centerY = offsetY + y * cellSize + cellSize / 2;
        int textX = offsetX - 4;
        int textY = centerY - textSize.cy / 2;
        if (textX - textSize.cx < 0) {
            textX = offsetX + 2 + textSize.cx;
        }
        TextOutW(hdc, textX, textY, buf, (int)wcslen(buf));
    }

    SelectObject(hdc, hOldFont2);
    DeleteObject(hLabelFont);

    HFONT hMarkFont = CreateFont(
        24, 0, 0, 0, FW_BOLD,
        FALSE, FALSE, FALSE,
        DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
        DEFAULT_PITCH | FF_DONTCARE,
        L"Consolas"
    );
    HFONT hOldMarkFont = (HFONT)SelectObject(hdc, hMarkFont);
    SetTextColor(hdc, RGB(255, 255, 255));
    SetBkMode(hdc, TRANSPARENT);
    SetTextAlign(hdc, TA_CENTER | TA_TOP);

    for (int y = 0; y < GRID_SIZE; ++y) {
        for (int x = 0; x < GRID_SIZE; ++x) {
            if (shots[y][x] != 0) {
                int centerX = offsetX + x * cellSize + cellSize / 2;
                int centerY = offsetY + y * cellSize + cellSize / 2;

                wchar_t mark = (shots[y][x] == 2 ? L'X' : L'·');
                SIZE sz;
                GetTextExtentPoint32W(hdc, &mark, 1, &sz);
                TextOutW(
                    hdc,
                    centerX,
                    centerY - (sz.cy / 2),
                    &mark,
                    1
                );
            }
        }
    }

    SelectObject(hdc, hOldMarkFont);
    DeleteObject(hMarkFont);

    ReleaseDC(hwnd, hdc);
}

void RevealAllShips() {
    for (int y = 0; y < GRID_SIZE; ++y) {
        for (int x = 0; x < GRID_SIZE; ++x) {
            if (ships[y][x] == 1) {
                shots[y][x] = 2;
            }
        }
    }
}

void ShowGame(HWND hwnd) {
    GenerateRandomShips();
    selectedCol = -1;
    selectedRow = -1;

    bool exitLoop = false;

    SHORT prevKeyStateCols[GRID_SIZE] = { 0 };
    SHORT prevKeyStateRows[10] = { 0 };
    SHORT prevKeyStateSpace = 0;
    SHORT prevKeyStateEnter = 0;
    SHORT prevKeyStateEsc = 0;
    SHORT prevKeyStateTab = 0;

    const int COL_KEYS[GRID_SIZE] = {
        0x46, // f а
        0xBC, // , б
        0x44, // d в
        0x55, // u г
        0x4C, // l д
        0x54, // t е
        0xBA, // ; ж
        0x50, // p з
        0x42, // b и
        0x52, // r к
    };

    while (!exitLoop) {
        DrawGame(hwnd);

        SHORT escState = GetAsyncKeyState(VK_ESCAPE);
        if ((escState & 0x8000) && !(prevKeyStateEsc & 0x8000)) {
            exitLoop = true;
        }
        prevKeyStateEsc = escState;

        SHORT tabState = GetAsyncKeyState(VK_TAB);
        if ((tabState & 0x8000) && !(prevKeyStateTab & 0x8000)) {
            RevealAllShips();
        }
        prevKeyStateTab = tabState;

        for (int i = 0; i < GRID_SIZE; ++i) {
            SHORT keyState = GetAsyncKeyState(COL_KEYS[i]);
            if ((keyState & 0x8000) && !(prevKeyStateCols[i] & 0x8000)) {
                selectedCol = i;
            }
            prevKeyStateCols[i] = keyState;
        }

        const int ROW_KEYS[10] = {
            0x31, // 1
            0x32, // 2
            0x33, // 3
            0x34, // 4
            0x35, // 5
            0x36, // 6
            0x37, // 7
            0x38, // 8
            0x39, // 9
            0x30  // 0
        };

        for (int i = 0; i < 10; ++i) {
            SHORT keyState = GetAsyncKeyState(ROW_KEYS[i]);
            if ((keyState & 0x8000) && !(prevKeyStateRows[i] & 0x8000)) {
                if (i < 9) {
                    selectedRow = i;
                }
                else {
                    selectedRow = 9;
                }
            }
            prevKeyStateRows[i] = keyState;
        }

        SHORT spaceState = GetAsyncKeyState(VK_SPACE);
        if ((spaceState & 0x8000) && !(prevKeyStateSpace & 0x8000)) {
            selectedCol = -1;
            selectedRow = -1;
        }
        prevKeyStateSpace = spaceState;

        SHORT enterState = GetAsyncKeyState(VK_RETURN);
        if ((enterState & 0x8000) && !(prevKeyStateEnter & 0x8000)) {
            if (selectedCol >= 0 && selectedRow >= 0) {
                if (shots[selectedRow][selectedCol] == 0) {
                    if (ships[selectedRow][selectedCol] == 1) {
                        shots[selectedRow][selectedCol] = 2;
                    }
                    else {
                        shots[selectedRow][selectedCol] = 1;
                    }
                }
                selectedCol = -1;
                selectedRow = -1;
            }
        }
        prevKeyStateEnter = enterState;

        Sleep(50);
    }
}
