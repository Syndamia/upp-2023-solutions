#include <iostream>

int main() {
	unsigned int x, n;
	std::cin >> x >> n;
	unsigned int xToPowerOfN = 1;
	for (int i = 0; i < n; i++) {
		xToPowerOfN *= x;
	}
	std::cout << xToPowerOfN << std::endl;
}
