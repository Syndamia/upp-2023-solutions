#include <iostream>

int fibIndex(const int N, int count = 0, int a = 0, int b = 1) {
	if (N == a) return count;
	return fibIndex(N, count + 1, b, a+b);
}

int main() {
	int N;
	std::cin >> N;
	std::cout << fibIndex(N) << std::endl;
}
