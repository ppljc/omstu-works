#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Polynomial {
private:
    vector<double> coefficients;

    void normalize() {
        while (coefficients.size() > 1 && coefficients.front() == 0) {
            coefficients.erase(coefficients.begin());
        }
    }

public:
    Polynomial() {
        coefficients.push_back(0);
    }

    Polynomial(const vector<double>& coeffs) : coefficients(coeffs) {
        normalize();
    }

    void print() const {
        bool first = true;
        int maxDegree = coefficients.size() - 1;
        for (int i = 0; i < coefficients.size(); i++) {
            int degree = maxDegree - i;
            if (coefficients[i] != 0) {
                if (!first && coefficients[i] > 0) {
                    cout << "+";
                }
                if (degree == 0) {
                    cout << coefficients[i];
                }
                else if (degree == 1) {
                    if (coefficients[i] == 1) cout << "x";
                    else if (coefficients[i] == -1) cout << "-x";
                    else cout << coefficients[i] << "x";
                }
                else {
                    if (coefficients[i] == 1) cout << "x^" << degree;
                    else if (coefficients[i] == -1) cout << "-x^" << degree;
                    else cout << coefficients[i] << "x^" << degree;
                }
                first = false;
            }
        }
        if (first) cout << "0";
        cout << endl;
    }

    Polynomial operator-(const Polynomial& other) const {
        vector<double> result;
        size_t maxSize = max(coefficients.size(), other.coefficients.size());

        for (size_t i = 0; i < maxSize; i++) {
            double a = (i < coefficients.size()) ? coefficients[i] : 0;
            double b = (i < other.coefficients.size()) ? other.coefficients[i] : 0;
            result.push_back(a - b);
        }

        return Polynomial(result);
    }

    Polynomial operator/(const Polynomial& divisor) const {
        if (divisor.coefficients.size() == 1 && divisor.coefficients[0] == 0) {
            cout << "Ошибка: деление на нуль!" << endl;
            return Polynomial();
        }

        vector<double> dividend = coefficients;
        vector<double> result(max(0, (int)coefficients.size() - (int)divisor.coefficients.size() + 1), 0);

        for (int i = 0; i <= (int)coefficients.size() - (int)divisor.coefficients.size(); i++) {
            double coef = dividend[i] / divisor.coefficients[0];
            result[i] = coef;

            for (size_t j = 0; j < divisor.coefficients.size(); j++) {
                dividend[i + j] -= coef * divisor.coefficients[j];
            }
        }

        return Polynomial(result);
    }
};

int main4() {
    setlocale(LC_ALL, "ru_RU");

    Polynomial p1({ 2, 3, -1 });
    Polynomial p2({ 1, 2 });

    cout << "Полином 1: ";
    p1.print();
    cout << "Полином 2: ";
    p2.print();

    Polynomial p3 = p1 - p2;
    cout << "P1 - P2: ";
    p3.print();

    Polynomial p4 = p1 / p2;
    cout << "P1 / P2: ";
    p4.print();

    return 0;
}