#include <iostream>

void tryResize(int*& numbers, size_t& numbersSize, size_t numbersCount) {
	if (numbersCount < numbersSize) {
		return;
	}

	numbersSize *= 2;
	int* biggerArray = new int[numbersSize];
	for (size_t i = 0; i < numbersCount; i++) {
		biggerArray[i] = numbers[i];
	}

	delete[] numbers;
	numbers = biggerArray;
}

void addToEndOfArray(int value, int*& numbers, size_t& numbersSize, size_t& numbersCount) {
	tryResize(numbers, numbersSize, numbersCount + 1);
	numbers[numbersCount] = value;
	numbersCount += 1;
}

int main() {
	int* numbers = new int[1];
	size_t numbersSize = 1;
	size_t numbersCount = 0;

	int buffer;
	std::cin >> buffer;
	while(buffer != 0) {
		addToEndOfArray(buffer, numbers, numbersSize, numbersCount);
		std::cin >> buffer;
	}

	size_t R;
	std::cin >> R;

	int* rotated = new int[numbersCount];
	for (int i = 0; i < numbersCount; i++) {
		rotated[(i + R + numbersCount) % numbersCount] = numbers[i];
	}
	delete[] numbers;

	for (int i = 0; i < numbersCount; i++) {
		std::cout << rotated[i] << " ";
	}
	std::cout << std::endl;

	delete[] rotated;
}
