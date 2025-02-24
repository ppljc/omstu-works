#include <iostream>
#include <vector>
#include <locale>

using namespace std;

extern void printVector(vector<int> c);

enum Boolean { false_, true_ };

int main1_2(vector<int> v) {
	setlocale(LC_ALL, "ru_RU");

	Boolean istherezero = false_;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0) {
			istherezero = true_;
			break;
		}
	}

	cout << "Результат обнаружения нуля в векторе [ ";
	printVector(v);
	cout << " ] - " << istherezero << "\n\n";

	return 0;
}
