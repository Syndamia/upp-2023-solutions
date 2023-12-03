#include <iostream>

int main() {
	unsigned int N;
	std::cin >> N;

	int* numbers = new int[N];
	for (int i = 0; i < N; i++) {
		std::cin >> numbers[i];
	}

	for (int i = 1; i < N; i += 2) {
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 2; i < N; i += 3) {
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

	delete[] numbers;
}
