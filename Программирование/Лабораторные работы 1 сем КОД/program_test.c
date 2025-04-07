#include <stdio.h>
#include <math.h>
#include <locale.h>

#define PI 3.14159265359

<<<<<<< Updated upstream
int main0() {
=======
int maintest() {
>>>>>>> Stashed changes
    setlocale(LC_ALL, "RUS");

    float x, y, a = 0.5, dx;

    printf("   a    |    x    |     y     \n");
    printf("---------------------------------\n");

    do {
        dx = a / 4;
        x = 0;

        printf("%6.2f |         |            \n", a);
        printf("---------------------------------\n");

        do {
            if (x >= 0 && x <= 1)  y = tan(a * a + sin(PI * x));
            else if (x > 1 && x <= 2) y = a * sin(PI - cos(PI * x));
            else if (x > 2 && x < 3)  y = log(x);
            else {
                x += dx;
                continue;
            }

            printf("        | %6.2f | %10.4f \n", x, y);

            x += dx;
        } while (x <= 3.01);

        a += 0.25;
        printf("---------------------------------\n");
    } while (a <= 1.1);

    return 0;
}
