#include <iostream>

void printNumbers(int currentBit, char* buf, const int N) {
	if (currentBit == 0) {
		std::cout << buf << std::endl;
		return;
	}
	buf[N - currentBit] = '0';
	printNumbers(currentBit - 1, buf, N);
	buf[N - currentBit] = '1';
	printNumbers(currentBit - 1, buf, N);
}

int main() {
	int N;
	std::cin >> N;

	char* buf = new char[N+1];
	buf[N] = '\0';

	printNumbers(N, buf, N);
	delete[] buf;
}
