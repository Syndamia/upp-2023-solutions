#include <iostream>

int main() {
	double num = 3.14159;
	do {
		if (num > 0) {
			std::cout << "Positive" << std::endl;
		}
		else {
			std::cout << "Negative" << std::endl;
		}

		std::cin >> num;
	} while (num != 0);
}
