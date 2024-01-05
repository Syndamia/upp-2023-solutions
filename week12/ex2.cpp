#include <iostream>

void floodFill(int row, int col, char** board, int rows, int cols) {
	if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] == '#')
		return;

	board[row][col] = '#';
	floodFill(row+1, col,   board, rows, cols); // up
	floodFill(row-1, col,   board, rows, cols); // down
	floodFill(row,   col+1, board, rows, cols); // right
	floodFill(row,   col-1, board, rows, cols); // left
}

int main() {
	int N, M;
	std::cin >> N >> M;

	char** board = new char*[N];
	for (int i = 0; i < N; i++) {
		board[i] = new char[M];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> board[i][j];
		}
	}

	int X, Y;
	std::cin >> X >> Y;

	floodFill(X, Y, board, N, M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < N; i++) {
		delete[] board[i];
	}
	delete[] board;
}
