#include <iostream>
#include <bitset>
#include <string>
#include <locale>

using namespace std;
int main() {
    setlocale(LC_ALL, "ru_RU");

    unsigned char SM = 0; // сумматор

    bool lastbit = false;

    unsigned char R2; // mA

    cout << "Введите знаковый бит А: ";
    string zA;
    cin >> zA;

    cout << "Введите мантиссу A (8 разрядов): ";
    string mA;
    cin >> mA;
    R2 = bitset<8>(mA).to_ulong();

    unsigned char pA; // pA 

    cout << "Введите порядок pA (5 разрядов): ";
    string porA;
    cin >> porA;
    pA = bitset<8>(porA).to_ulong();

    unsigned char R1; // mB

    cout << "Введите знаковый бит B: ";
    string zB;
    cin >> zB;

    cout << "Введите мантиссу B (8 разрядов): ";
    string mB;
    cin >> mB;
    R1 = bitset<8>(mB).to_ulong();

    unsigned char pB; // pB 

    cout << "Введите порядок pB (5 разрядов): ";
    string porB;
    cin >> porB;
    pB = bitset<8>(porB).to_ulong();

    unsigned char pC = pA + pB;

    for (int i = 0; i < 8; i++) {
        R2 = R2 >> 1;
        R1 = R1 << 1;
        if (R1 & 0b10000000) {
            SM += R2;
            lastbit = true;
        }
        else {
            lastbit = false;
        }
    }

    if ((SM & 0b10000000) == lastbit) {
        while ((SM & 0b10000000) == lastbit) {
            SM = SM << 1;
            pC = pC + 1;
        }
    }
  
    if (lastbit == true) {
        cout << "mC: " << "1." << SM << endl;
    }
    else {
        cout << "mC: " << "0." << bitset<8>(SM) << endl;
    }
    cout << "pC: " << bitset<5>(pC);

    return 0;
}
