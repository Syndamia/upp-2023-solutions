#include <iostream>

void putOn(char board[3][3], char marker, size_t position) {
	position--;
	board[position / 3][position % 3] = marker;
}

void print(char board[3][3]) {
	for (size_t row = 0; row < 3; row++) {
		for (size_t col = 0; col < 3; col++) {
			std::cout << board[row][col];
		}
		std::cout << std::endl;
	}
}

unsigned win(char board[3][3]) {
	bool notFull = false;
	char start = ' ';
	bool won = false;
	
	/* Проверяваме редовете */
	for (size_t row = 0; row < 3; row++) {
		start = board[row][0];

	}
}



int main() {
	char board[3][3] = { { ' ' } };
	bool playerOneTurn = true;

	size_t position;
	unsigned winStatus = 0;
	do {
		std::cin >> position;
		if (playerOneTurn) {
			putOn(board, 'X', position);
		}
		else {
			putOn(board, 'O', position);
		}
		playerOneTurn = !playerOneTurn;

		print(board);
		winStatus = win(board);
	} while (winStatus == 0);
}
