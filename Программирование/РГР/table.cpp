#include "functions.h"

void setColor(WORD color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void resetColor() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void printFunctionTable() {
    const int steps = 20;
    const double from = 0.0;
    const double to = 2 * M_PI;
    const double stepSize = (to - from) / steps;

    vector<double> xs, f1s, f2s;

    for (int i = 0; i <= steps; ++i) {
        double x = from + i * stepSize;
        double f1 = 5 - 3 * cos(x);
        double f2 = sqrt(1 + pow(sin(x), 2));
        xs.push_back(x);
        f1s.push_back(f1);
        f2s.push_back(f2);
    }

    double f1_min = *min_element(f1s.begin(), f1s.end());
    double f1_max = *max_element(f1s.begin(), f1s.end());
    double f2_min = *min_element(f2s.begin(), f2s.end());
    double f2_max = *max_element(f2s.begin(), f2s.end());

    system("cls");

    int width = getConsoleWidth();
    const int col1 = 8, col2 = 14, col3 = 21, col4 = 32;
    const int tableWidth = col1 + col2 + col3 + col4 + 5;
    int startX = (width - tableWidth) / 2;

    auto printLine = [&](char fill = '-') {
        gotoxy(startX, -1);
        cout << string(tableWidth, fill);
        };

    gotoxy(startX, 1);
    cout << "“аблица значений функций на отрезке [0; 2Pi] с " << steps << " шагами";

    gotoxy(startX, 2);
    printLine();
    gotoxy(startX, 3);
    cout << "|"
        << setw(col1) << left << " Ўаг" << "|"
        << setw(col2) << left << " x" << "|"
        << setw(col3) << left << " f1(x) = 5 - 3cos(x) " << "|"
        << setw(col4) << left << " f2(x) = (1 + (sin(x))^2)^(1/2) " << "|";
    gotoxy(startX, 4);
    printLine();

    for (int i = 0; i <= steps; ++i) {
        gotoxy(startX, 5 + i);

        cout << "|";
        cout << setw(col1) << left << i << "|";
        cout << setw(col2) << fixed << setprecision(4) << xs[i] << "|";

        if (f1s[i] == f1_min)
            setColor(1);
        else if (f1s[i] == f1_max)
            setColor(12);
        else
            resetColor();

        stringstream f1str;
        f1str << fixed << setprecision(6) << f1s[i];
        string f1text = f1str.str();
        int f1pad = (col3 - f1text.length()) / 2;
        cout << string(f1pad, ' ') << f1text << string(col3 - f1pad - f1text.length(), ' ');
        resetColor();
        cout << "|";

        if (f2s[i] == f2_min)
            setColor(1);
        else if (f2s[i] == f2_max)
            setColor(12);
        else
            resetColor();

        stringstream f2str;
        f2str << fixed << setprecision(6) << f2s[i];
        string f2text = f2str.str();
        int f2pad = (col4 - f2text.length()) / 2;
        cout << string(f2pad, ' ') << f2text << string(col4 - f2pad - f2text.length(), ' ');
        resetColor();
        cout << "|";
    }

    gotoxy(startX, 6 + steps);
    printLine();

    gotoxy(startX, 7 + steps);
    setColor(1);
    cout << "—иним";
    resetColor();
    cout << " Ч минимумы, ";
    setColor(12);
    cout << "красным";
    resetColor();
    cout << " Ч максимумы." << endl;

    _getch();
}
