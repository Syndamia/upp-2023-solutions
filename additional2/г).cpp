#include <iostream>
#include <cstring>

void resize(char**& text, int& size) {
	char** biggerText = new char*[size * 2];
	for (int i = 0; i < size; i++) {
		biggerText[i] = text[i];
	}
	delete[] text;
	text = biggerText;
	size *= 2;
}

// б) подточка

void skipWhiteSpace(char*& str) {
	while (str[0] == ' ') {
		str++;
	}
}

void extractCommand(char* line, char**& commandAndParameters, int& size) {
	skipWhiteSpace(line);

	if (line[0] != ':') {
		commandAndParameters = nullptr;
		size = 0;
		return;
	}
	line++;

	skipWhiteSpace(line);

	size = 0;
	int reservedSize = 2;
	commandAndParameters = new char*[reservedSize];

	commandAndParameters[0] = new char[2];
	commandAndParameters[0][0] = line[0];
	commandAndParameters[0][1] = '\0';
	size++;


	line++;

	skipWhiteSpace(line);

	// в този цикъл изкарваме конкретните аргументи
	while (line[0] != '\0') {
		// ако commandAndParameters не може да побере още един параметър
		if (size == reservedSize) {
			resize(commandAndParameters, reservedSize);
		}

		// дължината на сегашния параметър
		int parameterLength = 0;
		for (int i = 0; line[i] != ' ' && line[i] != '\0'; i++) {
			parameterLength++;
		}

		// вкарваме сегашния параметър в commandAndParameters
		commandAndParameters[size] = new char[parameterLength+1];
		for (int i = 0; i < parameterLength; i++) {
			commandAndParameters[size][i] = line[i];
		}
		commandAndParameters[size][parameterLength] = '\0';
		size++;

		line += parameterLength;
		skipWhiteSpace(line);
	}
}

// в) подточка

int digitsLength(int num) {
	if (num == 0) return 1;
	int length = 0;
	while (num != 0) {
		num /= 10;
		length++;
	}
	return length;
}

void printNumber(int num, int digitLength) {
	int printZeroes = digitLength - digitsLength(num);
	while (printZeroes > 0) {
		std::cout << "0";
	}
	std::cout << num << " ";
}

void print(char** text, int count) {
	int countLength = digitsLength(count);
	for (int i = 0; i < count; i++) {
		printNumber(i+1, countLength);
		std::cout << text[i] << std::endl;
	}
}

void tryExcessParametersError(int parametersSize, int maxSize) {
	// Изваждаме 1, защото parametersSize включва и самата буква, определяща командата
	if (parametersSize - 1 > maxSize) {
		std::cout << "; Excess parameters" << std::endl;
	}
}

int main() {
	int size = 2;  // колко клетки сме заделили (колко редове можем да вкараме)
	int count = 0; // колко клетки използваме (колко редове сме вкарали)
	char** text = new char*[2];

	char buf[1024];
	std::cin.getline(buf, 1024, '\n');
	bool stopProgram = false;
	while (!stopProgram) {
		// ако text не може да запази още един ред
		if (count == size) {
			resize(text, size);
		}

		char** commandAndParameters;
		int commandAndParametersSize;
		extractCommand(buf, commandAndParameters, commandAndParametersSize);
		// ако сегашния ред не е команда
		if (commandAndParametersSize == 0) {
			// вкарваме сегашния ред в text
			int lineLength = strlen(buf);

			text[count] = new char[lineLength + 1];
			for (int i = 0; i < lineLength; i++) {
				text[count][i] = buf[i];
			}
			text[count][lineLength] = '\0';
			count++;
		}
		else {
			switch (commandAndParameters[0][0]) {
				// в) подточка
				case 'P': tryExcessParametersError(commandAndParametersSize, 0);
				          print(text, count);
				          break;
				// г) подточка
				case 'Q': tryExcessParametersError(commandAndParametersSize, 0);
				          stopProgram = true;
				          break;
				default: std::cout << "; Not an editor command" << std::endl; break;
			}

			// освобождаваме памет
			for (int i = 0; i < commandAndParametersSize; i++) {
				delete[] commandAndParameters[i];
			}
			delete[] commandAndParameters;
		}

		// вземаме следващия ред
		if (!stopProgram) {
			std::cin.getline(buf, 1024, '\n');
		}
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
