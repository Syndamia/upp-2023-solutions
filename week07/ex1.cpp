#include <iostream>

void coordSum(double x1, double y1, double x2, double y2, double& sumx, double& sumy) {
	sumx = x1 + x2;
	sumy = y1 + y2;
}

int main() {
	double x1, y1, x2, y2, sumx, sumy;
	std::cin >> x1 >> y1 >> x2 >> y2;
	coordSum(x1, y1, x2, y2, sumx, sumy);
	std::cout << sumx << " " << sumy << std::endl;
}
