#include <iostream>

int main() {
	double price;
	std::cin >> price;

	// Има два метода да се реши тази задача
	// или (int)(price * 100) и price % x (където x е 50 или 20 или 10 или 5 или 1)
	// или (int)(price / 0.x) и price -= (int)(price / 0.x) (където х е 5 или 2 или 1 или 05 или 01)
	// Втория вариант е малко по-общ, затова него ще имплементирам
	int divided = price / 0.5;
	std::cout << "0.5 " << divided;
	price -= divided * 0.5;

	divided = price / 0.2;
	std::cout << " 0.2 " << divided;
	price -= divided * 0.2;

	divided = price / 0.1;
	std::cout << " 0.1 " << divided;
	price -= divided * 0.1;

	divided = price / 0.05;
	std::cout << " 0.05 " << divided;
	price -= divided * 0.05;

	divided = price / 0.01;
	std::cout << " 0.01 " << divided << std::endl;
}
