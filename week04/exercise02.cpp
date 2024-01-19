#include <iostream>

unsigned long long tenTo(unsigned long long power) {
	unsigned long long result = 1;
	while (power > 0) {
		result *= 10;
		power--;
	}
	return result;
}

unsigned numLen(unsigned long long n) {
	if (n == 0) return 1;
	unsigned len = 0;
	while (n > 0) {
		len++;
		n /= 10;
	}
	return len;
}

unsigned long long insert(unsigned long long n, unsigned start, unsigned len, unsigned long long toInsert) {
	unsigned numDigits = numLen(n);
	return (n / tenTo(numDigits - start + 1)) * tenTo(numDigits - start + len + 1)
	       + toInsert * tenTo(numDigits - start + 1)
	       + n % tenTo(numDigits - start + 1);
}

unsigned long long append(unsigned long long n, unsigned long long appendWith) {
	return insert(n, numLen(n) + 1, numLen(appendWith), appendWith);
}

unsigned long long reverse(unsigned long long n) {
	unsigned long long rev = 0;
	while (n > 0) {
		rev *= 10;
		rev += n % 10;
		n /= 10;
	}
	return rev;
}

unsigned bitLength(unsigned long long num) {
	unsigned length = 0;
	while (num > 0) {
		length++;
		num >>= 1;
	}
	return length - 1;
}

unsigned max(unsigned a, unsigned b) {
	return (a > b) ? a : b;
}

unsigned nthDigit(unsigned long long n, unsigned digit) {
	while (digit > 0) {
		n /= 10;
		digit--;
	}
	return n % 10;
}

int main() {
	// TODO: make more readable
	unsigned long long p1, c1, p2, c2;
	std::cin >> p1 >> c1 >> p2 >> c2;
	unsigned long long pm = 0, cm = 0;
	unsigned maxPower = bitLength(p1) + bitLength(p2);
	for (unsigned power = 0; power <= maxPower; power++) {
		int coeff = 0;
		for (int pow1 = 0; pow1 <= power; pow1++) {
			for (int pow2 = 0; pow2 <= power; pow2++) {
				if ((pow1 + pow2 != power) || (((p1 >> pow1) & 1) == 0) || (((p2 >> pow2) & 1) == 0)) continue;
				coeff += nthDigit(c1, pow1) * nthDigit(c2, pow2);
			}
		}
		pm <<= 1;
		pm |= coeff > 0;
		cm = append(cm, coeff);
	}
	std::cout << pm << std::endl << reverse(cm) << std::endl;
}
