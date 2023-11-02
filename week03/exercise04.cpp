#include <iostream>

int main() {
	int num = 65536;
	int input;
	for (int i = 0; i < 10; i++) {
		std::cin >> input;
		if (input == 0) break;

		num /= input;
	}
	std::cout << num << std::endl;
}
