#include <iostream>

int main() {
	int num = 15;
	char command = '\0';
	while (true) {
		std::cin >> command;
		switch (command) {
			case 's': std::cin >> num; break;
			case 'l': num <<= 1; break;
			case 'r': num >>= 1; break;
			case 'q': num *= num; break;
			case 'c': num *= num * num; break;
			case 'm': num -= 351; break;
			case 'p': num += 94; break;
			case '&': return 0;
			default:
				std::cout << "Invalid command!" << std::endl;
				continue;
		}
		std::cout << num << std::endl;
	}
}
