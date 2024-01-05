#include <iostream>

int main() {
	size_t N = 0;
	std::cin >> N;

	char* str = new char[N+1];
	std::cin.ignore();
	std::cin.getline(str, N+1);

	size_t mid = N / 2;
	for (size_t i = mid; i < N; i++) {
		std::cout << str[i];
	}
	for (size_t i = 0; i < mid; i++) {
		std::cout << str[i];
	}
	std::cout << std::endl;
	/* Как може да направим горната логика със само един цикъл?
	 * Подсказка: модулно деление */

	delete[] str;
}
