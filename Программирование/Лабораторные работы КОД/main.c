#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

extern void main1_1();
extern void main1_2();
extern void main2_1();
extern void main2_2();
extern void main2_3();
extern void main3_1();
extern void main3_2();
extern void main4_1();
extern void main4_2();
extern void main4_3();
extern void main5_1();
extern void main5_2();
extern void main5_3();
extern void main6_1_1();
extern void main6_1_2();
extern void main6_2();
extern void main7_1();
extern void main7_2();
extern void main7_3();
extern void main8_1();
extern void main8_2();
extern void main8_3();
extern void main8_3();
extern void main9_1();

int main() {
    setlocale(LC_ALL, "ru_RU");

    int choice;

    while (1) {
        printf("Введите номер задачи: ");
        scanf_s("%d", &choice);
        printf("\n");

        switch (choice) {
            case 0:
                printf("Выход\n");
                return 0;
            case 11:
                main1_1();
                break;
            case 12:
                main1_2();
                break;
            case 21:
                main2_1();
                break;
            case 22:
                main2_2();
                break;
            case 23:
                main2_3();
                break;
            case 31:
                main3_1();
                break;
            case 32:
                main3_2();
                break;
            case 41:
                main4_1();
                break;
            case 42:
                main4_2();
                break;
            case 43:
                main4_3();
                break;
            case 51:
                main5_1();
                break;
            case 52:
                main5_2();
                break;
            case 53:
                main5_3();
                break;
            case 611:
                main6_1_1();
                break;
            case 612:
                main6_1_2();
                break;
            case 62:
                main6_2();
                break;
            case 71:
                main7_1();
                break;
            case 72:
                main7_2();
                break;
            case 73:
                main7_3();
                break;
            case 81:
                main8_1();
                break;
            case 82:
                main8_2();
                break;
            case 83:
                main8_3();
                break;
            case 91:
                main9_1();
                break;
            default:
                printf("Неправильное значение.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}