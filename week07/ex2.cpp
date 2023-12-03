#include <iostream>

void sell(unsigned int& stock) {
	stock--;
}

void receive(unsigned int& stock) {
	stock += 10;
}

int main() {
	unsigned int stockA = 0, stockB = 0, stockC = 0;
	unsigned int* current = &stockA;
	
	char buf;
	std::cin >> buf;
	while (buf != '$') {
		switch(buf) {
			case 'a': current = &stockA; break;
			case 'b': current = &stockB; break;
			case 'c': current = &stockC; break;
			case 'S': sell(*current); break;
			case 'R': receive(*current); break;
		}
		std::cin >> buf;
	}
}
