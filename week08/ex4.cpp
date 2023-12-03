#include <iostream>

void resize(int*& numbers, size_t& numbersSize) {
	int* newArr = new int[numbersSize * 2];
	for (int i = 0; i < numbersSize; i++) {
		newArr[i] = numbers[i];
	}

	delete[] numbers;
	numbers = newArr;
	numbersSize *= 2;
}

int main() {
	size_t numbersSize = 4;
	int* numbers = new int[numbersSize];

	size_t even = 0, odd = 1;
	int buf;
	std::cin >> buf;
	while (buf != 0) {
		if (even < numbersSize) {
			numbers[even] = buf;
			even += 2;
		}
		else if (odd < numbersSize) {
			numbers[odd] = buf;
			odd += 2;
		}
		else {
			resize(numbers, numbersSize);
			continue;
		}
		std::cin >> buf;
	}

	for (size_t i = 0; i < numbersSize; i++) {
		if (numbers[i] != 0) {
			std::cout << numbers[i] << " ";
		}
	}
	std::cout << std::endl;

	delete[] numbers;
}
