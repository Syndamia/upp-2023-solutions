#include <iostream>

int main() {
	int signals;
	std::cin >> signals;

	int leftSignal  = signals / 1000;
	int rightSignal = signals % 1000;

	// difference е дефакто абсолютната стойност на leftSignal - rightSignal
	int difference = leftSignal - rightSignal;
	if (difference < 0)
		difference *= -1;

	if (difference <= 3)
		std::cout << "Follow heading" << std::endl;
	else if (leftSignal < rightSignal)
		std::cout << "Turn left" << std::endl;
	else
		std::cout << "Turn right" << std::endl;
}
