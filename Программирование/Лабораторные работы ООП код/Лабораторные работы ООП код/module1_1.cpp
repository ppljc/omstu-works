#include <iostream>
#include <locale>
#include <vector>

#define TRUE 1
#define FALSE 0
#define Boolean int

using namespace std;

extern void printVector(vector<int> c);

int main1_1(vector<int> v) {
	setlocale(LC_ALL, "ru_RU");

	Boolean isnegative = FALSE;
	
	for (int i = 0; i < v.size(); i++) {
		if (v[i] < 0) {
			isnegative = TRUE;
			break;
		}
	}

	cout << "Результат обнаружения отрицательного числа в векторе [ ";
	printVector(v);
	cout << " ] - " << isnegative << "\n\n";

	return 0;
}
