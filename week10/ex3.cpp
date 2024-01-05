#include <iostream>

void printCharNTimes(int n, char c) {
	for (int i = 0; i < n; i++) {
		std::cout << c;
	}
}

void hourglass(int lines, int whitespaces, int nonwhitespace) {
	if (lines == 0) return;

	printCharNTimes(whitespaces, ' ');
	printCharNTimes(nonwhitespace, '+');
	std::cout << std::endl;

	hourglass(lines - 1, whitespaces + 1, nonwhitespace - 2);

	printCharNTimes(whitespaces, ' ');
	printCharNTimes(nonwhitespace, '#');
	std::cout << std::endl;
}

int main() {
	int N;
	std::cin >> N;
	hourglass(N, 0, 2*N - 1);
}
