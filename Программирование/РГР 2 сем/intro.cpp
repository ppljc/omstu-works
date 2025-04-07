#include "functions.h"

struct Bullet {
    double x, y;
    double dx, dy;
    Bullet(double startX, double startY, double speedX, double speedY)
        : x(startX), y(startY), dx(speedX), dy(speedY) {
    }
};

void printIntro()
{
    HWND hWnd = GetConsoleWindow();
    HDC hdc = GetDC(hWnd);
    RECT window;
    GetClientRect(hWnd, &window);

    HBRUSH GunBrush = CreateSolidBrush(RGB(128, 128, 128));
    HPEN GunPen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
    HBRUSH BulletBrush = CreateSolidBrush(RGB(255, 0, 0));
    HBRUSH MagBrush = CreateSolidBrush(RGB(100, 100, 100));

    int baseX = 100;
    int baseY = window.bottom / 2;

    std::vector<Bullet> bullets;
    int shotsFired = 0;
    int totalShots = 12;
    bool isReloading = false;
    DWORD reloadStartTime = 0;
    const int reloadDuration = 4000;

    HFONT font = CreateFont(40, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
        DEFAULT_PITCH | FF_DONTCARE, L"Arial");
    SelectObject(hdc, font);

    while (!_kbhit()) {
        FillRect(hdc, &window, (HBRUSH)GetStockObject(BLACK_BRUSH));

        SelectObject(hdc, GunBrush);
        SelectObject(hdc, GunPen);
        Rectangle(hdc, baseX, baseY - 40, baseX + 200, baseY + 40);
        Rectangle(hdc, baseX + 200, baseY - 20, baseX + 360, baseY + 20);
        Rectangle(hdc, baseX + 40, baseY + 40, baseX + 120, baseY + 160);
        MoveToEx(hdc, baseX + 80, baseY + 40, NULL);
        LineTo(hdc, baseX + 80, baseY + 100);
        LineTo(hdc, baseX + 120, baseY + 100);

        float magY = baseY + 160;
        if (isReloading) {
            DWORD currentTime = GetTickCount();
            int elapsed = currentTime - reloadStartTime;
            float progress = (float)elapsed / reloadDuration;
            if (progress < 0.5f) {
                magY += (progress / 0.5f) * 60;
            }
            else {
                magY += (1.0f - (progress - 0.5f) / 0.5f) * 60;
            }
        }
        SelectObject(hdc, MagBrush);
        Rectangle(hdc, baseX + 50, magY - 40, baseX + 110, magY);

        if (!isReloading && shotsFired < totalShots) {
            if (rand() % 10 == 0) {
                double startX = baseX + 360;
                double startY = baseY;
                double dx = 5 + (rand() % 11);
                double dy = -10 + (rand() % 21);
                bullets.emplace_back(startX, startY, dx, dy);
                shotsFired++;
            }
        }

        SelectObject(hdc, BulletBrush);
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].x += bullets[i].dx;
            bullets[i].y += bullets[i].dy;
            Ellipse(hdc, (int)bullets[i].x - 10, (int)bullets[i].y - 10,
                (int)bullets[i].x + 10, (int)bullets[i].y + 10);
        }

        for (int i = bullets.size() - 1; i >= 0; i--) {
            if (bullets[i].x > window.right || bullets[i].x < 0 ||
                bullets[i].y > window.bottom || bullets[i].y < 0) {
                bullets.erase(bullets.begin() + i);
            }
        }

        if (shotsFired >= totalShots && !isReloading) {
            isReloading = true;
            reloadStartTime = GetTickCount();
        }

        std::string text;
        if (isReloading) {
            DWORD currentTime = GetTickCount();
            int elapsed = currentTime - reloadStartTime;
            int remaining = reloadDuration - elapsed;
            if (remaining <= 0) {
                isReloading = false;
                shotsFired = 0;
                bullets.clear();
            }
            else {
                text = std::to_string(remaining / 1000) + "." +
                    std::to_string(remaining % 1000) + "s";
            }
        }
        else {
            text = std::to_string(totalShots - shotsFired) + "/" +
                std::to_string(totalShots);
        }
        TextOutA(hdc, 10, window.bottom - 50, text.c_str(), text.length());

        Sleep(20);
    }

    DeleteObject(GunBrush);
    DeleteObject(GunPen);
    DeleteObject(BulletBrush);
    DeleteObject(MagBrush);
    DeleteObject(font);
    ReleaseDC(hWnd, hdc);
}