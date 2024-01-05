#include <iostream>

void ages(const int mult, const int sum, int youngest, int middle, int oldest, bool &foundSolution) {
	// Не проверяваме за сума, понеже винаги правим такива извиквания, че сумата да е коректна
	if (youngest * middle * oldest == mult) {
		std::cout << youngest << " " << middle << " " << oldest << std::endl;
		foundSolution = true;
		return;
	}

	// Правим middle по-стар като копенсираме чрез по-млад oldest
	if (!foundSolution && oldest - 1 > middle + 1)
		ages(mult, sum, youngest, middle + 1, oldest - 1, foundSolution);
	// Правим youngest по-стар, като middle трябва да има най-малко същата му възраст
	if (!foundSolution && sum - 2*(youngest + 1) > youngest + 1)
		ages(mult, sum, youngest + 1, youngest + 1, sum - 2*(youngest + 1), foundSolution);
}

void ages(const int mult, const int sum) {
	bool foundSolution = false;
	// Започваме с минималните възможни възрасти за youngest и middle
	ages(mult, sum, 1, 1, sum - 2, foundSolution);
}

int main() {
	int mult, sum;
	std::cin >> mult >> sum;

	ages(mult, sum);
}
