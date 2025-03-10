#include <iostream>
#include <string>

using namespace std;

class Computer {
protected:
	string brand;
	string CPU;
	string GPU;
	int RAM;
	int ROM;

public:
	Computer(string b, string cpu, string gpu, int ram, int rom) : brand(b), CPU(cpu), GPU(gpu), RAM(ram), ROM(rom) {}

	void getComputer() const {
		cout << "Бренд: " << brand << endl;
		cout << "CPU: " << CPU << endl;
		cout << "GPU: " << GPU << endl;
		cout << "RAM (ГБ): " << RAM << endl;
		cout << "ROM (ГБ): " << ROM << endl;
	}
};

class PeripheralDevice : public Computer {
protected:
	string deviceType;
	string connectionType;

public:
	PeripheralDevice(string b, string cpu, string gpu, int ram, int rom, string dt, string ct) :
		Computer(b, cpu, gpu, ram, rom), deviceType(dt), connectionType(ct) {}

	void getPeripheralDevice() const {
		getComputer();
		cout << "Тип периферического устройства: " << deviceType << endl;
		cout << "Тип подключения периферического устройства: " << connectionType << endl;
	}
};

class Keyboard : public PeripheralDevice {
protected:
	string keyboardBrand;
	string keyboardType;
	string mainColor;
	bool backlight;

public:
	Keyboard(string b, string cpu, string gpu, int ram, int rom, string dt, string ct, string kb, string kt, string mc, bool bl) :
		PeripheralDevice(b, cpu, gpu, ram, rom, dt, ct), keyboardBrand(kb), keyboardType(kt), mainColor(mc), backlight(bl) { }

	void getKeyboard() const {
		getPeripheralDevice();
		cout << "Бренд клавиатуры: " << keyboardBrand << endl;
		cout << "Тип переключетелей клавиатуры: " << keyboardType << endl;
		cout << "Основной цвет клавиатуры: " << mainColor << endl;
		cout << "Наличие подсветки на клавиатуре: " << backlight << endl;
	}
};

int main3() {
	Keyboard keyboard("Xiaomi", "AMD Ryzen 7 7840HS", "AMD Radeon 780M", 16, 1024, "Keyboard", "Bluetooth", "FleSports", "Mechanical", "Green", true);

	cout << "Информация о компьютере: " << endl;
	keyboard.getComputer();
	cout << endl;

	cout << "Информация о периферийном устройстве: " << endl;
	keyboard.getPeripheralDevice();
	cout << endl;

	cout << "Информация о клавиатуре: " << endl;
	keyboard.getKeyboard();
	cout << endl;

	return 0;
}
