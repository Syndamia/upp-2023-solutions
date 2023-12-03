#include <iostream>

int main() {
	size_t N;
	std::cin >> N;

	unsigned nums[30];
	for (size_t i = 0; i < N; i++) {
		std::cin >> nums[i];
	}

	bool lastWas = false;
	unsigned count = 0;

	bool hasGE = true;
	for (unsigned comp = 1; hasGE; comp++) {
		hasGE = false;
		for (size_t i = 0; i < N; i++) {
			if ((nums[i] >= comp) != lastWas) {
				if (!lastWas) count++;
				lastWas = !lastWas;
				hasGE = true;
			}
		}
	}

	std::cout << count << std::endl;
}
