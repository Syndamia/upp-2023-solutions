#include <iostream>
#include <cstring>

void skipWhitespaces(char*& str) {
	while (*str == ' ') str++;
}

int calculateExpression(char*& expr) {
	if (*expr == '\0') return 0;

	skipWhitespaces(expr);

	// Ако започваме с цифра, връщаме числото и го пропускаме в израза
	if ('0' <= expr[0] && expr[0] <= '9') {
		int ret = atoi(expr);
		while ('0' <= *expr && *expr <= '9') expr++;
		return ret;
	}

	expr++; // пропускаме (
	int leftHandSide = calculateExpression(expr);
	skipWhitespaces(expr);

	char op = *expr;
	expr++;

	skipWhitespaces(expr);
	int rightHandSide = calculateExpression(expr);

	skipWhitespaces(expr);
	expr++; // пропускаме )
	
	if (op == '+') {
		return leftHandSide + rightHandSide;
	}
	return leftHandSide * rightHandSide;
}

int main() {
	char buf[1025];
	std::cin.getline(buf, 1025);
	char* ptrCopy = buf;
	std::cout << calculateExpression(ptrCopy) << std::endl;
}
