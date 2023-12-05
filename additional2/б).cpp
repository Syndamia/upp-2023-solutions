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

void skipWhiteSpace(char*& str) {
	while (str[0] == ' ') {
		str++;
	}
}

// Ще обяснявам с пример: line = "   :  А  KLM   1"
// Главната идея е, че в един низ указателя към него сочи към първия елемент от низа
// затова най-удобно е да преместваме указателя напред и в доста случаи да работим с
// "първите" няколко букви.
void extractCommand(char* line, char**& commandAndParameters, int& size) {
	skipWhiteSpace(line);  // попускаме спейсовете в началото
	                       // преди този ред line сочи към:
	                       //  v
	                       // "   :  А  KLM   1"
	                       // след този ред line сочи към: 
	                       //     v
	                       // "   :  А  KLM   1"

	// ако първата не-шпация буква не е ":", тогава изобщо нямаме команда
	// примерно ако line = "     ABC"
	if (line[0] != ':') {
		commandAndParameters = nullptr;
		size = 0;
		return;
	}
	line++; // пропускаме ":"
	        // преди този ред line сочи към:
	        //     v
	        // "   :  А  KLM   1"
	        // след този ред, line сочи към:
	        //      v
	        // "   :  А  KLM   1"

	skipWhiteSpace(line); // пропускаме спейсовете след ":"
	                      // преди този ред line сочи към:
	                      //      v
	                      // "   :  А  KLM   1"
	                      // след този ред, line сочи към:
	                      //        v
	                      // "   :  А  KLM   1"

	// в момента се намираме над командата, тя е една буква,
	// затова създаваме низ с тази буква (понеже е низ, трябва да има терминираща нула)
	size = 0;
	int reservedSize = 2;
	commandAndParameters = new char*[reservedSize];

	commandAndParameters[0] = new char[2];
	commandAndParameters[0][0] = line[0];
	commandAndParameters[0][1] = '\0';
	size++;


	line++; // пропускаме командата (буквата)
	        // преди този ред line сочи към:
	        //        v
	        // "   :  А  KLM   1"
	        // след този ред, line сочи към:
	        //         v
	        // "   :  А  KLM   1"

	skipWhiteSpace(line); // пропускаме спейсове
	                      // преди този ред line сочи към:
	                      //         v
	                      // "   :  А  KLM   1"
	                      // след този ред, line сочи към:
	                      //           v
	                      // "   :  А  KLM   1"

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

		line += parameterLength; // пропускаме сегашния параметър
		                         // на първа итерация, преди този ред line сочи към:
		                         //           v
	                             // "   :  А  KLM   1"
		                         // на първа итерация, след този ред, line сочи към:
		                         //              v
	                             // "   :  А  KLM   1"
		skipWhiteSpace(line); // пропускаме спейсове
		                      // на първа итерация, преди този ред line сочи към:
		                      //              v
	                          // "   :  А  KLM   1"
		                      // на първа итерация, след този ред, line сочи към:
		                      //                 v
	                          // "   :  А  KLM   1"
	}
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
			// изкарваме командата и параметри на екрана
			for (int i = 0; i < commandAndParametersSize; i++) {
				std::cout << commandAndParameters[i] << ",";
			}
			std::cout << std::endl;

			// освобождаваме памет
			for (int i = 0; i < commandAndParametersSize; i++) {
				delete[] commandAndParameters[i];
			}
			delete[] commandAndParameters;
		}

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
