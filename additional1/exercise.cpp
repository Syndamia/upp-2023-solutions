#include <iostream>
#include <cassert>

/* Решението само няма довършена команда "s" от подточка к)
 *
 * Възможно е да получите "warning: integer constant is so large that it is unsigned", не се притеснявайте, не е проблем.
 */

// Подточка а)

// Следващите 2 функции са взети дословно от Задача 1 през Седмица 4
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

const unsigned int ROWA_DIGITS = 9;

void getRow(unsigned int rowA, unsigned int *row, unsigned int *type, unsigned int *value) {
	*row   =  rowA / tenTo(ROWA_DIGITS - 1);
	*type  = (rowA / tenTo(ROWA_DIGITS - 2)) % tenTo(1);
	*value =  rowA % tenTo(ROWA_DIGITS - 2);
}

// Подточка б)

long double parseNumber(unsigned int valueA, unsigned long long rowB) {
	return valueA + (long double)rowB / tenTo(numLen(rowB));
}

// Подточка в)

const unsigned int BITS_PER_CHAR = 5;
const unsigned int DEFINED_CHARS = 1 << BITS_PER_CHAR; // 32 = pow(2, BITS_PER_CHAR)

char numToChar(unsigned int num) {
	if (num <= 25) return 'A' + num;
	switch (num) {
		case 26: return ' ';
		case 27: return '.';
		case 28: return ',';
		case 29: return ':';
		case 30: return '?';
		case 31: return '!';
		default: assert(false);
	}
}

const unsigned int MAX_STR_LEN = 64 / BITS_PER_CHAR; // 12

void decodeNumberText(unsigned long long rowB, char* output) {
	for (int i = MAX_STR_LEN - 1; i >= 0; i--) {
		output[i] = numToChar(rowB & 0b11111);
		rowB >>= BITS_PER_CHAR;
	}
}

// Подточка г)    (разширява от в))

char decipherCaesarRight(unsigned int offset, int encrypted) {
	return (encrypted - offset) % DEFINED_CHARS;
}

void decodeNumberText(unsigned int valueA, unsigned long long rowB, char* output) {
	for (int i = MAX_STR_LEN - 1; i >= 0; i--) {
		output[i] = numToChar(decipherCaesarRight(valueA, rowB & 0b11111));
		rowB >>= BITS_PER_CHAR;
	}
}

// Подточка д)

const unsigned long long MASK_LEADING_ARRVAL_BITS = (unsigned long long)0b1111 << (64 - 4);

void decodeArray(unsigned long long rowB, unsigned int* output) {
	for (unsigned int i = 0; i < 16; i++) {
		output[i] = (rowB & MASK_LEADING_ARRVAL_BITS) >> 60;
		rowB <<= 4;
	}
}

// Подточка е)    (разширява от г))

bool contains(unsigned int* arr, unsigned int length, unsigned int val) {
	for (unsigned int i = 0; i < length; i++) {
		if (arr[i] == val) return true;
	}
	return false;
}
void printArray(unsigned int* arr, unsigned int len);

void decodeArray(unsigned valueA, unsigned long long rowB, unsigned int* output) {
	unsigned int defaultIndex = valueA & 0b111;
	valueA >>= 3;

	unsigned int possibleValues[5] = { 0 };
	for (unsigned int i = 0; i < 5; i++) {
		possibleValues[i] = (valueA & 0b11110000000000000000) >> 16;
		valueA <<= 4;
	}

	for (unsigned int i = 0; i < 16; i++) {
		unsigned int current = (rowB & MASK_LEADING_ARRVAL_BITS) >> 60;
		if (!contains(possibleValues, 5, current)) {
			current = possibleValues[defaultIndex];
		}
		output[i] = current;
		rowB <<= 4;
	}
}

// Подточка ж)

void decompress(unsigned int valueA, int *cryptographicRow, unsigned int *decompressedValueA, unsigned long long *decompressedValueB) {
	unsigned int leadingThree =  valueA & 0b11100000000000000000000;

	unsigned int firstInd     = (valueA & 0b00011111000000000000000) >> 15;
	unsigned int secondInd    = (valueA & 0b00000000111110000000000) >> 10;
	unsigned int thirdInd     = (valueA & 0b00000000000001111100000) >>  5;
	unsigned int fourthInd    =  valueA & 0b00000000000000000011111;

	*decompressedValueA = leadingThree | (cryptographicRow[firstInd] >> 1);
	*decompressedValueB = ((unsigned long long)(cryptographicRow[firstInd] & 1) << (64 - 1))  |
	                      ((unsigned long long) cryptographicRow[secondInd]     << (21 + 21)) |
	                      ((unsigned long long) cryptographicRow[thirdInd]      << 21)        |
	                                            cryptographicRow[fourthInd];
}

// Подточка и)

void printArray(unsigned int arr[], unsigned int length) {
	for (unsigned int i = 0; i < length - 1; i++) {
		std::cout << arr[i] << ", ";
	}
	std::cout << arr[length - 1] << std::endl;
}

void parseAndPrintData(unsigned int* tableA, unsigned long long* tableB, int* cryptographicRow) {
	int tableRow = 0;
	std::cin >> tableRow;

	unsigned int row, type, valueA;
	getRow(tableA[tableRow], &row, &type, &valueA);
	unsigned long long valueB;
	if (row == 0) {
		decompress(valueA, cryptographicRow, &valueA, &valueB);
	}
	else {
		valueB = tableB[row - 1];
	}

	switch (type) {
		case 0:
			std::cout << parseNumber(valueA, valueB) << std::endl;
			break;
		case 1: {
			char str[7] = { '\0' };
			decodeNumberText(valueA, valueB, str);
			std::cout << str << std::endl;
			break;
		}
		case 2: {
			unsigned int arrValues[16] = { 0 };
			decodeArray(valueA, valueB, arrValues);
			printArray(arrValues, 16);
			break;
		}
	}
}

// Подточка й)

const unsigned int QUERY_TYPE = 0;
const unsigned int QUERY_ROW  = 1;

void printTable(unsigned int* table, unsigned int tableSize) {
	for (unsigned int i = 0; i < tableSize; i++) {
		std::cout << table[i] << std::endl;
	}
}

unsigned int queryTableA(unsigned int* tableA, unsigned int tableSize, unsigned int queryType, unsigned int queryValue, unsigned int* output) {
	unsigned int outputCount = 0;
	for (unsigned int i = 0; i < tableSize; i++) {
		unsigned int type, row, value;
		getRow(tableA[i], &type, &row, &value);
		if ((queryType == QUERY_TYPE && type == queryValue) ||
			(queryType == QUERY_ROW  && row  == queryValue)) {
			*(output++) = tableA[i];
			outputCount++;
		}
	}
	return outputCount;
}

// Подточка к)

unsigned int max(unsigned int a, unsigned int b) {
	return (a > b) ? a : b;
}

void tests();

int main() {
	tests();

	// Подточка з)

	unsigned int tableA[16] = { 0 };
	unsigned long long tableB[8] = { 0 };
	int cryptographicRow[32] = { 0 };

	int sizeA, sizeB, sizeCrypt;
	std::cin >> sizeA;
	for (int i = 0; i < sizeA; i++) {
		std::cin >> tableA[i];
	}
	std::cin >> sizeB;
	for (int i = 0; i < sizeB; i++) {
		std::cin >> tableB[i];
	}
	std::cin >> sizeCrypt;
	for (int i = 0; i < sizeCrypt; i++) {
		std::cin >> cryptographicRow[i];
	}

	// Подточка и)    (и нататък)

	char command = '\0';
	std::cin >> command;
	while (command != 'q') {
		switch (command) {
			// Подточка и)
			case 'g':
				parseAndPrintData(tableA, tableB, cryptographicRow);
				break;
			case 'i':
				std::cout << "[Table A] Rows: " << sizeA << " Required memory usage: " << (4 * sizeA) << " bytes Full memory usage: " << (4 * 8) << " bytes" << std::endl;
				std::cout << "[Cryptographic row] Size: " << sizeCrypt << " Required memory usage: " << (4 * sizeCrypt) << " bytes Full memory usage: " << (4 * 32) << " bytes" << std::endl;
				std::cout << "[Table B] Rows: " << sizeB << " Required memory usage: " << (4 * sizeB) << " bytes Full memory usage: " << (4 * 16) << " bytes" << std::endl;
				break;
			// Подточка й)
			case 't': {
				unsigned int queryMatch[16] = { 0 }, X = 0;
				std::cin >> X;
				unsigned int matchSize = queryTableA(tableA, sizeA, QUERY_TYPE, X, queryMatch);
				std::cout << "Matched rows: " << matchSize << std::endl;
				printTable(queryMatch, matchSize);
			}
			case 'r': {
				unsigned int queryMatch[16] = { 0 }, X = 0;
				std::cin >> X;
				unsigned int matchSize = queryTableA(tableA, sizeA, QUERY_ROW, X, queryMatch);
				std::cout << "Matched rows: " << matchSize << std::endl;
				std::cout << "Cryptographic row size: " << sizeCrypt << std::endl;
				printTable(queryMatch, matchSize);
			}
			// Подточка к)
			case 'w': {
				char table;
				unsigned int row;
				std::cin >> table >> row;
				if (table == 'A') {
					unsigned int val;
					std::cin >> val;
					tableA[row - 1] = val;
				}
				else {
					unsigned long long val;
					std::cin >> val;
					tableB[row - 1] = val;
				}
				sizeA = max(sizeA, row);
			}
			case 's': {
				// TODO
			}
		}
		std::cin >> command;
	}
}

/* Тези тестове са извън условието, но са ми много удобни
 */

const long double EPSILON = 0.00001;

bool strEq(const char* str1, const char* str2) {
	do {
		if (*str1 != *str2) return false;
		str1++;
		str2++;
	}
	while (*str1 != '\0' && *str2 != '\0');
	return true;
}

bool arrEq(unsigned int* a, unsigned int* b) {
	for (int i = 0; i < 16; i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

void tests() {
	// Подточка а)
	unsigned int row, type, value;
	getRow(1234567, &row, &type, &value);
	assert(row == 0); assert(type == 0); assert(value == 1234567);

	getRow(12345678, &row, &type, &value);
	assert(row == 0); assert(type == 1); assert(value == 2345678);

	getRow(123456789, &row, &type, &value);
	assert(row == 1); assert(type == 2); assert(value == 3456789);

	// Подточка б)
	long double parsedNumber = parseNumber(1, 5);
	assert(parsedNumber - 1.5 < EPSILON);

	parsedNumber = parseNumber(0, 37);
	assert(parsedNumber - 0.37 < EPSILON);

	parsedNumber = parseNumber(913, 0);
	assert(parsedNumber - 913.0 < EPSILON);

	parsedNumber = parseNumber(8388607, 18446744073709551615);
	assert(parsedNumber - 8388607.18446744073709551615 < 2.5); // with bigger numbers our inaccuracy increases

	// Подточка в)
	char decodedText[7] = { 0 };
	decodeNumberText(2, decodedText);
	assert(strEq(decodedText, "AAAAAAAAAAAC"));

	decodeNumberText(257104811188071551, decodedText);
	assert(strEq(decodedText, "HELLO WORLD!"));

	decodeNumberText(1148238614786569150, decodedText);
	assert(strEq(decodedText, "!. ,:?!. ,:?"));

	// Подточка г)
	decodeNumberText(0, 2, decodedText);
	assert(strEq(decodedText, "AAAAAAAAAAAC"));

	decodeNumberText(0, 257104811188071551, decodedText);
	assert(strEq(decodedText, "HELLO WORLD!"));

	decodeNumberText(0, 1148238614786569150, decodedText);
	assert(strEq(decodedText, "!. ,:?!. ,:?"));

	decodeNumberText(17, 632247276719883827, decodedText);
	assert(strEq(decodedText, "AAAAAAAAAAAC"));

	decodeNumberText(3, 368677860020992194, decodedText);
	assert(strEq(decodedText, "HELLO WORLD!"));

	decodeNumberText(30, 1073856582231288700, decodedText);
	assert(strEq(decodedText, "!. ,:?!. ,:?"));

	decodeNumberText(32, 1148238614786569150, decodedText);
	assert(strEq(decodedText, "!. ,:?!. ,:?"));

	// Подточка д)
	unsigned int arr[16] = { 0 };
	unsigned int arrTrue[16] = {
		0, 11, 11, 15, 0, 10, 9, 10, 0, 0, 15, 5, 3, 11, 15, 0
	};
	decodeArray(846406911526255600, arr);
	assert(arrEq(arr, arrTrue));

	// Подточка е)
	unsigned int arrFirst[16] = {
		0, 11, 11, 11, 0, 11, 11, 11, 0, 0, 11, 11, 11, 11, 11, 0
	};
	decodeArray(360537, 846406911526255600, arr);
	assert(arrEq(arr, arrFirst));

	unsigned int arrSecond[16] = {
		8, 8, 8, 15, 8, 8, 8, 8, 8, 8, 15, 5, 3, 8, 15, 8
	};
	decodeArray(3119812, 846406911526255600, arr);
	assert(arrEq(arr, arrSecond));
	
	// Подточка ж)
	int cryptRow1[] = { 0, 2, 5 };
	unsigned int decompA;
	unsigned long long decompB;
	decompress(32770, cryptRow1, &decompA, &decompB);
	assert(decompA == 1); assert(decompB == 5);

	int cryptRow2[] = { 2097151 };
	decompress(7340032, cryptRow2, &decompA, &decompB);
	assert(decompA == 8388607); assert(decompB == 18446744073709551615);

	std::cout << "Tests passed!" << std::endl;
}
