#include <iostream>
#include <cstring>

// Получава text (масив от низове, т.е. масив от редове) и размер
// Удвоява размера на text
// Бележка: може да се даде аргумента, че е по-добре да увеличаваме text със
// само една клетка всеки път, за да не заделяме излишна памет, но да кажем, че
// в този конкретен случай не е проблем.
void resize(char**& text, int& size) {
	char** biggerText = new char*[size * 2];
	for (int i = 0; i < size; i++) {
		biggerText[i] = text[i];
	}
	delete[] text;
	text = biggerText;
	size *= 2;
}

int main() {
	int size = 2;  // колко клетки сме заделили (колко редове можем да вкараме)
	int count = 0; // колко клетки използваме (колко редове сме вкарали)
	char** text = new char*[2];

	char buf[1024];
	std::cin.getline(buf, 1024, '\n');
	while (buf[0] != 'Q') {
		// ако text не може да запази още един ред
		if (count == size) {
			resize(text, size);
		}

		// вкарваме сегашния ред в text
		int lineLength = strlen(buf);

		text[count] = new char[lineLength + 1];
		for (int i = 0; i < lineLength; i++) {
			text[count][i] = buf[i];
		}
		text[count][lineLength] = '\0';
		count++;

		// вземаме следващия ред
		std::cin.getline(buf, 1024, '\n');
	}

	// изкарваме всички редове
	for (int i = 0; i < count; i++) {
		std::cout << text[i] << std::endl;
	}

	// освобождаваме памет
	for (int i = 0; i < count; i++) {
		delete[] text[i];
	}
	delete[] text;
}
