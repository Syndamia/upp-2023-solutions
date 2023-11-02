#include <iostream>

int main() {
	int countLower = 0, countUpper = 0, countDigit = 0;
	char input;
	std::cin >> input;
	while (input != '$') {
		if (input == '@') {
			return 0;
		}
		// Грешка ли е, че тук има "if" вместо "else if"?
		if ('a' <= input && input <= 'z') {
			countLower++;
		}
		else if ('A' <= input && input <= 'Z') {
			countUpper++;
		}
		else if ('0' <= input && input <= '9') {
			countDigit++;
		}
		std::cin >> input;
	}
	std::cout << "Lowercase: " << countLower << " Uppercase: " << countUpper << " Digit: " << countDigit << std::endl;
}
