#include <iostream>
#include <stdlib.h>
#include <ctime>

int main() {
	srand(time(NULL));
	for (int row = 0; row < 20; row++) {
		for (int col = 0; col < 20; col++) {
			std::cout << ((rand() % 2) ? '/' : '\\');
		}
		std::cout << std::endl;
	}
}
