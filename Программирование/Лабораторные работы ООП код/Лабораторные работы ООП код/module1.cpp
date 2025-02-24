#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i < v.size() - 1)
			cout << ", ";
	}
}
