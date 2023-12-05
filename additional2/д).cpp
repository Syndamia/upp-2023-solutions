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

// д) подточка

void deleteRow(char**& text, int& size, int& count, int rowNumber) {
	if (rowNumber <= 0 || count < rowNumber) {
		std::cout << "; Invalid row number" << std::endl;
		return;
	}

	// Освобождаваме паметта на реда
	rowNumber--;
	delete[] text[rowNumber];

	// Преместваме всички редове "назад" с една позиция (вече имаме "дупка" в масива)
	for (int i = rowNumber; i < count - 1; i++) {
		text[i] = text[i+1];
	}
	text[count-1] = nullptr;
	count--;

	// Променяме размера на text, този код е доста близък до кода при resize
	if (count == 0) {
		return;
	}

	char** smallerText = new char*[count];
	for (int i = 0; i < count; i++) {
		smallerText[i] = text[i];
	}
	delete[] text;
	text = smallerText;
	size = count;
}

void tryExcessParametersError(int parametersSize, int maxSize) {
	// Изваждаме 1, защото parametersSize включва и самата буква, определяща командата
	if (parametersSize - 1 > maxSize) {
		std::cout << "; Excess parameters" << std::endl;
	}
}

bool tryNotEnoughParametersError(int parametersSize, int minSize) {
	// Изваждаме 1, защото parametersSize включва и самата буква, определяща командата
	if (parametersSize - 1 < minSize) {
		std::cout << "; Not enough parameters" << std::endl;
	}
	return parametersSize - 1 >= minSize;
}

bool tryParameterIsNumber(char* param) {
	while (param[0] != '\0') {
		if (param[0] < '0' || param[0] > '9') {
			std::cout << "; Invalid parameter type" << std::endl;
			return false;
		}
		param++;
	}
	return true;
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
			bool canCont;
			switch (commandAndParameters[0][0]) {
				// в) подточка
				case 'P': tryExcessParametersError(commandAndParametersSize, 0);
				          print(text, count);
				          break;
				// г) подточка
				case 'Q': tryExcessParametersError(commandAndParametersSize, 0);
				          stopProgram = true;
				          break;
				// д) подточка
				case 'D': tryExcessParametersError(commandAndParametersSize, 1);
				          // Ако има достатъчно параметри
				          canCont = tryNotEnoughParametersError(commandAndParametersSize, 1);
				          if (!canCont) break;
				          // Ако параметъра е число
				          canCont = tryParameterIsNumber(commandAndParameters[1]);
				          if (!canCont) break;

				          deleteRow(text, size, count, atoi(commandAndParameters[1]));
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
