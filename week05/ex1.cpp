#include <iostream>

void pointSum(double x1, double y1, double x2, double y2, double *x, double *y) {
	*x = x1 + x2;
	*y = y1 + y2;
}

int main() {
	double x1, y1, x2, y2, sumX, sumY;
	std::cin >> x1 >> y1 >> x2 >> y2;
	pointSum(x1, y1, x2, y2, &sumX, &sumY);
	std::cout << sumX << " " << sumY << std::endl;
}
