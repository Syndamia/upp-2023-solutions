#include <iostream>

double abs(double val) {
	return (val > 0) ? val : -val;
}

double square(double val) {
	return val * val;
}

double afterFloatingPoint(double val) {
	return val - (int)val;
}

double beforeFloatingPoint(double val) {
	return (int)val;
}

int main() {
	double (*useFunc)(double);
	char buf;
	std::cin >> buf;
	switch(buf) {
		case 'a': useFunc = &abs; break;
		case 's': useFunc = &square; break;
		case 'h': useFunc = &afterFloatingPoint; break;
		case 'f': useFunc = &beforeFloatingPoint; break;
	}

	for (int i = 0; i < 5; i++) {
		double temp;
		std::cin >> temp;
		std::cout << useFunc(temp) << " ";
	}
	std::cout << std::endl;
}
