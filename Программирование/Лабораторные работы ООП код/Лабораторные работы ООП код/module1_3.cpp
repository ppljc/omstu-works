#include <iostream>
#include <locale>
#include <vector>

using namespace std;

extern void printVector(vector<int> c);

class Boolean {
private:
    int value;

public:
    Boolean(int val) {
        if (val != 0 && val != 1) {
            throw invalid_argument("Invalid value, must be 0 or 1");
        }
        value = val;
    }

    int getValue() const {
        return value;
    }

    Boolean operator!() const {
        return Boolean(value == 0 ? 1 : 0);
    }

    Boolean operator&&(const Boolean& other) const {
        return Boolean(value && other.value);
    }

    Boolean operator||(const Boolean& other) const {
        return Boolean(value || other.value);
    }

    Boolean operator==(const Boolean& other) const {
        return Boolean(value == other.value ? 1 : 0);
    }

    Boolean operator!=(const Boolean& other) const {
        return Boolean(value != other.value ? 1 : 0);
    }
};

int main1_3(vector<int> v) {
    setlocale(LC_ALL, "ru_RU");

    Boolean ispositive = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 0) {
            ispositive = 1;
            break;
        }
    }

    cout << "Результат обнаружения положительного числа в векторе [ ";
    printVector(v);
    cout << " ] - " << ispositive.getValue() << "\n\n";

    return 0;
}
