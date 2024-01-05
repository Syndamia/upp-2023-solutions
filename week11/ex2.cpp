#include <iostream>

// а) подточка
void printCharNTimes(int n, char c) {
	for (int i = 0; i < n; i++) {
		std::cout << c;
	}
	std::cout << std::endl;
}

void triangleA(const int N, int current = 1) {
	if (current > N) return;

	printCharNTimes(current, '+');

	triangleA(N, current + 1);
}

// б) подточка
void triangleB(const int N, int current = 1) {
	if (current > N) return;

	triangleA(N, current + 1);

	printCharNTimes(current, '+');
}


// в) подточка
void triangleC(const int N, int current = 1) {
	if (current > N) return;

	printCharNTimes(current, '+');

	triangleC(N, current + 1);

	printCharNTimes(current, '#');
}

int main() {
	int N;
	std::cin >> N;
	triangleC(N);
}
