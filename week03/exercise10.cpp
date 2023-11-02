#include <iostream>

int main() {
	int current = 0, memory = 0, temp = 0;
	std::cin >> current;
	char buff;
	bool printMem = false;
	while (true) {
		std::cin >> buff;
		switch (buff) {
			case 'a': memory += current; printMem = true; break;
			case 's': memory -= current; printMem = true; break;
			case 'm': memory = 0; printMem = true; break;

			case 'c': current = 0; std::cout << current << std::endl; continue;
		}
		if (printMem) {
			std::cout << memory << std::endl;
			printMem = false;
			continue;
		}

		std::cin >> temp;
		switch (buff) {
			case '+': current += temp; break;
			case '-': current -= temp; break;
			case '*': current *= temp; break;
			case '/': current /= temp; break;
		}
		std::cout << current << std::endl;
	}
}
