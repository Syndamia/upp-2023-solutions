#include <iostream>

int main() {
	int x;
	std::cin >> x;
	double step = 10.0 / x;
	double length = step;
	while (length <= 10) {
		for (int col = 0; col < length; col++) {
			std::cout << '#';
		}
		std::cout << std::endl;
		length += step;
	}
}
