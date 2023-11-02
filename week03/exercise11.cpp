#include <iostream>
#include <cassert>

int parseSensor(int s) { return ((((s=(s>>1)&(~0xF617A100))<0x54)?s|0xF01:s&0xCBFF)>>2)-21; }

int main() {
	int rawValue;
	std::cin >> rawValue;

	int temp = parseSensor(rawValue);
	assert(-20 <= temp);
	assert(temp <= 40);

	if (30 <= temp && temp <= 40) {
		std::cout << "Hot" << std::endl;
	}
	else if (20 <= temp && temp <= 29) {
		std::cout << "Warm" << std::endl;
	}
	else if (11 <= temp && temp <= 19) {
		std::cout << "Temperate" << std::endl;
	}
	else if (0 <= temp && temp <= 10) {
		std::cout << "Cold" << std::endl;
	}
	else if (-20 <= temp && temp <= -1) {
		std::cout << "Freezing" << std::endl;
	}
}
