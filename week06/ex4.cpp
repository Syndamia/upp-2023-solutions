#include <iostream>

int main() {
	char chocolate[41][41] = { { '#' } };
	size_t N, M;
	std::cin >> N >> M;

	bool firstPlayerTurn = false;
	size_t row, col;
	unsigned winStatus = 0;
	do {
		firstPlayerTurn = !firstPlayerTurn;
		winStatus = chomp(chocolate, row, col);
	} while(winStatus == 0);
}
