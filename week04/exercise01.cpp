#include <iostream>

// Подточка а)

unsigned long long tenTo(unsigned long long power) {
	unsigned long long result = 1;
	while (power > 0) {
		result *= 10;
		power--;
	}
	return result;
}

unsigned numLen(unsigned long long n) {
	unsigned len = 0;
	while (n > 0) {
		len++;
		n /= 10;
	}
	return len;
}

unsigned long long get(unsigned long long n, unsigned start, unsigned end) {
	return (n / tenTo(numLen(n) - end)) % tenTo(end - start + 1);
}

unsigned long long remove(unsigned long long n, unsigned start, unsigned len) {
	unsigned numDigits = numLen(n);
	return (n / tenTo(numDigits - start + 1)) * tenTo(numDigits - start + 1 - len)
	       + n % tenTo(numDigits - start + 1 - len);
}

unsigned long long insert(unsigned long long n, unsigned start, unsigned len, unsigned long long toInsert) {
	unsigned numDigits = numLen(n);
	return (n / tenTo(numDigits - start + 1)) * tenTo(numDigits - start + len + 1)
	       + toInsert * tenTo(numDigits - start + 1)
	       + n % tenTo(numDigits - start + 1);
}

// Подточка б)

unsigned long long copy(unsigned long long n, unsigned from, unsigned len, unsigned to) {
	return insert(n, to, len, get(n, from, from + len - 1));
}

unsigned long long cut(unsigned long long n, unsigned from, unsigned len, unsigned to) {
	unsigned long long cutNum = get(n, from, from + len - 1);
	return insert(remove(n, from, len), to, len, cutNum);
}

unsigned long long replace(unsigned long long n, unsigned from, unsigned len, unsigned long long replaceWith) {
	return insert(remove(n, from, len), from, numLen(replaceWith), replaceWith);
}

unsigned long long prepend(unsigned long long n, unsigned long long prependWith) {
	return insert(n, 1, numLen(prependWith), prependWith);
}

unsigned long long append(unsigned long long n, unsigned long long appendWith) {
	return insert(n, numLen(n) + 1, numLen(appendWith), appendWith);
}

// Подточка в)

int main() {
	char command;
	std::cin >> command;
	switch (command) {
		case 'c': unsigned long long n; unsigned from, len, to;
		          std::cin >> n >> from >> len >> to;
		          std::cout << copy(n, from, len, to) << std::endl;
		          break;
		case 'x': 
		          std::cin >> n >> from >> len >> to;
		          std::cout << cut(n, from, len, to) << std::endl;
		          break;
		case 'r': unsigned long long replaceWith;
		          std::cin >> n >> from >> len >> replaceWith;
		          std::cout << replace(n, from, len, replaceWith) << std::endl;
		          break;
		case 'p': unsigned long long prependWith;
		          std::cin >> n >> prependWith;
		          std::cout << prepend(n, prependWith) << std::endl;
		          break;
		case 'a': unsigned long long appendWith;
		          std::cin >> n >> appendWith;
		          std::cout << append(n, appendWith) << std::endl;
		          break;
	}
}
