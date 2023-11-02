#include <iostream>

int main() {
	char input;
	std::cin >> input;
	while (input != '^') {
		if (('A' <= input && input <= 'Z') ||
		    ('a' <= input && input <= 'z')) {
			std::cout << "letter" << std::endl;
		}
		else if ('0' <= input && input <= '9') {
			std::cout << "digit" << std::endl;
		}
		else {
			std::cout << "other" << std::endl;
		}
		std::cin >> input;
	}
}
