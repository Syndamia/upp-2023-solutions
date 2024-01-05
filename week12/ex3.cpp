#include <iostream>

void markQueen(int valueBy, int row, int col, int board[8][8]) {
	for (int i = 0; i < 8; i++) {
		board[row][i] += valueBy;
	}
	for (int i = 0; i < 8; i++) {
		board[i][col] += valueBy;
	}
	for (int i = 0; i < 8; i++) {
		if (row+i < 8  && col+i < 8)
			board[row+i][col+i] += valueBy;
		if (row-i > -1 && col-i > -1)
			board[row-i][col-i] += valueBy;
	}
	for (int i = 0; i < 8; i++) {
		if (row-i > -1 && col+i < 8)
			board[row-i][col+i] += valueBy;
		if (row+i < 8  && col-i > -1)
			board[row+i][col-i] += valueBy;
	}
}

void placeQueen(int row, int col, int board[8][8]) {
	markQueen(1, row, col, board);
}

void removeQueen(int row, int col, int board[8][8]) {
	markQueen(-1, row, col, board);
}

int possibleSolutions(int row, int board[8][8]) {
	// Board is filled with queens
	if (row == 8) {
		// За бонуса, тук просто принтираме целия board
		return 1;
	}

	// Find first free column, if any
	int col = 0;
	int sum = 0;
	while (col < 8) {
		// Place queen temporarily
		if (board[row][col] == 0) {
			placeQueen(row, col, board);
			sum += possibleSolutions(row + 1, board);
			removeQueen(row, col, board);
		}
		col++;
	}

	return sum;
}

int main() {
	int board[8][8] = { { 0 } };
	std::cout << possibleSolutions(0, board) << std::endl;
}
