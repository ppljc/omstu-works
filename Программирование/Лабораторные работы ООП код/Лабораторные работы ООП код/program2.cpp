#include <iostream>

#define PI 3.14

using namespace std;

class Cyl {
private:
	double radius, height;

public:
	Cyl(double r = 5, double h = 9) : radius(r), height(h) {}

	double volume() const {
		return PI * radius * radius * height;
	}

	double area() const {
		return (2 * (PI * radius * radius)) + (2 * PI * radius * height);
	}
};

int main2() {
	double r, h;

	cout << "������� ������ � ������: ";
	cin >> r >> h;
	cout << endl;

	Cyl cylinder(r, h), defaultCylinder;

	double volume, area;

	volume = cylinder.volume();
	area = cylinder.area();

	cout << "����� �������� � �������� " << r << " � ������� " << h << " - " << volume << endl;
	cout << "������ ������� �������� � �������� " << r << " � ������� " << h << " - " << area << endl;
	cout << endl;

	double defaultVolume, defaultArea;

	defaultVolume = defaultCylinder.volume();
	defaultArea = defaultCylinder.area();

	cout << "����� ������������ �������� - " << defaultVolume << endl;
	cout << "������ ������� ������������ �������� - " << defaultArea << endl;

	return 0;
}
