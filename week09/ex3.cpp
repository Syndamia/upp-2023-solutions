#include <iostream>
#include <cstring>

bool isSkippable(char c) {
	return c == ' ' || c == '.' || c == ',' || c == '!' || c == '?';
}

int main() {
	char str[1025];
	std::cin.getline(str, 1025);

	size_t strSize = strlen(str);
	int words = 1;
	bool lastWasSkippable = false;
	for (int i = 0; i < strSize; i++) {
		if (!isSkippable(str[i]) && lastWasSkippable) {
			words++;
			lastWasSkippable = false;
		}
		else if (isSkippable(str[i])) {
			lastWasSkippable = true;
		}
	}

	std::cout << words << std::endl;
}
