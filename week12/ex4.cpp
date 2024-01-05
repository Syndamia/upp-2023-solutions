#include <iostream>

// Главното неприятно нещо в тази задача е, че трябва да обгърнем вградените оператори във фунцкии
int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a * b;
}
int divi(int a, int b) {
	return a / b;
}
int pow(int a, int b) {
	int res = 1;
	while (b-- > 0) {
		res *= a;
	}
	return res;
}

int recRPN(int (*&op)(int, int), int &on) {
	int num;
	std::cin >> num;

	// Ако имаме операция, "връщаме" указател към конкретната функция
	if (std::cin.fail()) {
		std::cin.clear();
		char c;
		std::cin >> c;
		if (c == '\'') std::cin >> c;

		switch (c) {
			case '+': op = add; on = 2; break;
			case '-': op = sub; on = 2; break;
			case '*': op = mul; on = 2; break;
			case '/': op = divi; on = 2; break;
			case '^': op = pow; on = 2; break;
			case '$': on = -1; break;
		}
		return 0;
	}

	// Докато не плучим "операция" $, гледаме следващите изрази какво ще върнат
	do {
		int rightValue = recRPN(op, on);
		// Ако сегашната стойност е дясната страна на оператора
		if (on == 2) {
			on = 1;
			return num;
		}
		// Ако сегашната стойност е лявата страна на оператора
		if (on == 1) {
			on = 0;
			num = (*op)(num, rightValue);
		}
	} while(on > -1);

	return num;
}

int main() {
	int (*op)(int, int);
	int on;
	std::cout << recRPN(op, on) << std::endl;
}
