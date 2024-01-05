#include <iostream>

// Това е значително по-просто решение, аз не се сетих, взех от Катрин Попова
int knapsack2(int i, int *values, int *weights, int size, int maxWeight) {
	if (i == size)
		return 0;

	int currentNotTaken = knapsack2(i+1, values, weights, size, maxWeight);

	if (weights[i] <= maxWeight) {
		int currentTaken = values[i] + knapsack2(i+1, values, weights, size, maxWeight - weights[i]);
		return currentTaken > currentNotTaken ? currentTaken : currentNotTaken;
	}
	return currentNotTaken;
}

// Това е решението, показано на практикума
void knapsack1(int i, int& maxValues, bool *taken, int *values, int *weights, int size, int maxWeight) {
	if (i == size) {
		int currentValues = 0, currentWeight = 0;
		for (int i = 0; i < size; i++) {
			if (taken[i]) {
				currentValues += values[i];
				currentWeight += weights[i];
			}
		}
		if (currentWeight > maxWeight) return;
		if (currentValues > maxValues) {
			maxValues = currentValues;
		}
		return;
	}

	taken[i] = false;
	knapsack1(i+1, maxValues, taken, values, weights, size, maxWeight);

	taken[i] = true;
	knapsack1(i+1, maxValues, taken, values, weights, size, maxWeight);
}

int main() {
	int N;
	std::cin >> N;

	int *values = new int[N];
	int *weights = new int[N];
	for (int i = 0; i < N; i++) {
		std::cin >> values[i] >> weights[i];
	}
	int maxWeight;
	std::cin >> maxWeight;

	int maxValues = 0;
	bool *taken = new bool[N];
	knapsack1(0, maxValues, taken, values, weights, N, maxWeight);
	std::cout << maxValues << std::endl;
	delete[] taken;

	std::cout << knapsack2(0, values, weights, N, maxWeight) << std::endl;

	delete[] values;
	delete[] weights;
}
