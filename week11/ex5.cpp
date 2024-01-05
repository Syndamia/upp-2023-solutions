#include <iostream>

int* firstEmpty(int board[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == -1)
				return &board[i][j];
		}
	}
	return nullptr;
}

bool isSolvedTakuzo(int board[4][4]) {
	// Бройка в ред или колона
	// Не е нужно да пазим или проверяваме броя 1ци, понеже той е 4 - zeroes
	int zeroes = 0;
	for (int i = 0; i < 4; i++) {
		if (board[i][0] == 0) zeroes++;
	}

	// Бройка на редове
	for (int i = 0; i < 4; i++) {
		int currentZeroes = 0;
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == 0) currentZeroes++;
		}
		if (currentZeroes != zeroes) return false;
	}

	// Бройка на колони
	for (int i = 0; i < 4; i++) {
		int currentZeroes = 0;
		for (int j = 0; j < 4; j++) {
			if (board[j][i] == 0) currentZeroes++;
		}
		if (currentZeroes != zeroes) return false;
	}

	// Последователни в ред
	for (int i = 0; i < 4; i++) {
		for (int j = 2; j < 4; j++) {
			if (board[i][j - 2] == board[i][j - 1] && board[i][j - 1] == board[i][j]) return false;
		}
	}

	// Последователни в колона
	for (int i = 2; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i - 2][j] == board[i - 1][j] && board[i - 1][j] == board[i][j]) return false;
		}
	}

	return true;
}

void printTakuzo(int board[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void solveTakuzo(int board[4][4], bool &isSolved) {
	int* toFill = firstEmpty(board);
	if (toFill == nullptr) {
		if (isSolvedTakuzo(board)) {
			isSolved = true;
			printTakuzo(board);
		}
		return;
	}

	if (!isSolved) {
		*toFill = 0;
		solveTakuzo(board, isSolved);
	}
	if (!isSolved) {
		*toFill = 1;
		solveTakuzo(board, isSolved);
	}
	*toFill = -1;
}

void solveTakuzo(int board[4][4]) {
	bool isSolved = false;
	solveTakuzo(board, isSolved);
}

int main() {
	int board[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cin >> board[i][j];
		}
	}
	solveTakuzo(board);
}
