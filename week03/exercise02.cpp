#include <iostream>

int main() {
	int x;
	std::cin >> x;
	for (int row = 0; row < x; row++) {
		for (int col = 0; col <= row; col++) {
			std::cout << '#';
		}
		std::cout << std::endl;
	}
}
