#include <iostream>
#include <cstring>

int max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	/* 1025 за да поберем и последната терминираща нула, ако случайно реда
	 * действително е с дължина от 1024 знака */
	char str1[1025] = { '\0' };
	char str2[1025] = { '\0' };

	/* Последния параметър не е нужен, по подразбиране е '\n' */
	std::cin.getline(str1, 1025);
	std::cin.getline(str2, 1025);

	int biggestSize = max(strlen(str1), strlen(str2));
	for (int i = 0; i < biggestSize; i++) {
		if (str1[i] != str2[i]) {
			std::cout << '_';
		}
		else {
			std::cout << str1[i];
		}
	}
	std::cout << std::endl;
}
