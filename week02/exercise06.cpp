#include <iostream>

int main() {
	char input;
	std::cin >> input;
	// Някои хора използваха конкретните числови ASCII стойности в сравнението
	// Бих казал че това е грешка, фундаментално знаците са числа, '0' и '9' се "превеждат"
	// до конкретните ASCII стойности от C++
	std::cout << ('0' <= input && input <= '9') << std::endl;
}
