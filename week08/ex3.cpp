#include <iostream>

int main() {
	size_t N;
	std::cin >> N;

	int** matrix = new int*[N];
	for (int i = 0; i < N; i++) {
		matrix[i] = new int[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> matrix[i][j];
		}
	}

	int* mult = new int[N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mult[i] += matrix[0][i] * matrix[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		std::cout << mult[i] << " ";
	}
	std::cout << std::endl;

	delete[] mult;
	for (int i = 0; i < N; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
