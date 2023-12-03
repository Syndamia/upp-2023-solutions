#include <iostream>

int main() {
	// Вход
	size_t N, M;
	std::cin >> N >> M;

	int matrix1[60][60], matrix2[60][60];
	/* При matrix1[i][j] няма значение дали i се води ред или стълб, важното е да
	 * изберете едно значение и то да си стои до края на задачата.
	 */
	for (size_t row = 0; row < N; row++) {
		for (size_t col = 0; col < M; col++) {
			std::cin >> matrix1[row][col];
		}
	}

	for (size_t row = 0; row < M; row++) {
		for (size_t col = 0; col < N; col++) {
			std::cin >> matrix2[row][col];
		}
	}

	// Умножение
	int multMatrix[60][60] = { { 0 } };
	for (size_t row = 0; row < N; row++) {
		for (size_t col = 0; col < N; col++) {
			for (size_t i = 0; i < 60; i++) {
				multMatrix[row][col] += matrix1[row][i] * matrix2[i][col];
			}
		}
	}

	// Изход
	for (size_t row = 0; row < N; row++) {
		for (size_t col = 0; col < N; col++) {
			std::cout << multMatrix[row][col] << " ";
		}
		std::cout << std::endl;
	}
}
