#include <iostream>
#include <vector>
#include <locale>

using namespace std;

extern int main1_1(vector<int> v);
extern int main1_2(vector<int> v);

int main1() {
	setlocale(LC_ALL, "ru_RU");

	double a;
	vector<int> v = {};

	cout << "Введите количество элементов в векторе: ";
	cin >> a;
	cout << "Введите элементы вектора: ";

	for (int i = 0; i < a; i++) {
		int b;

		cin >> b;

		v.push_back(b);
	}

	cout << "\n";
	cout << "Вариант - 1:\n" <<
			"#define TRUE 1\n" <<
			"#define FALSE 0\n" <<
			"#define Boolean int\n\n";
	main1_1(v);

	cout << "Вариант - 2:\n" <<
		"enum Boolean { false_, true_ };\n\n";
	main1_2(v);

	return 0;
}
