#include <iostream>

int main() {
	size_t N, nums[30];
	std::cin >> N;
	for (size_t i = 0; i < N; i++) {
		std::cin >> nums[i];
	}

	size_t maxJumpsIndex = 0, maxJumpsCount = 0;
	bool visited[30] = { false };

	for (size_t start = 0; start < N; start++) {
		size_t current = start, jumpsCount = 0;

		while (!visited[current]) {
			visited[current] = true;
			current = nums[current];
			jumpsCount++;
		}

		if (jumpsCount > maxJumpsCount) {
			maxJumpsCount = jumpsCount;
			maxJumpsIndex = start;
		}

		for (size_t j = 0; j < N; j++) {
			visited[j] = false;
		}
	}

	std::cout << maxJumpsIndex << " " << maxJumpsCount << std::endl;
}
