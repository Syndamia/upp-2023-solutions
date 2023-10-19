#include <iostream>

int main() {
	int n;
	std::cin >> n;

	std::cout << "Със загуба bool " << (bool)n << std::endl;
	std::cout << "Без загуба long long int " << (long long int)n << std::endl;
	// Беше малко спорно дали от int към unsigned int губим информация
	// Накрая приехме, че не губи, понеже всеки бит се запазва
	std::cout << "Без загуба unsigned int " << (unsigned int)n << std::endl;
	std::cout << "Със загуба char " << (char)n << std::endl;
	std::cout << "Със загуба short int " << (short int)n << std::endl;
	std::cout << "Без загуба double " << (double)n << std::endl;
	std::cout << "Без загуба long int " << (long int)n << std::endl;
	std::cout << "Със загуба unsigned char " << (unsigned char)n << std::endl;
}
