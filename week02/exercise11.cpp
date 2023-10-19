#include <iostream>

int main() {
	// Много не съм ползвал константи в решенията, не защото няма смисъл да се прави, а така някои неща по-лесно се виждат
	const int LIGHT_SPEED = 29;

	int timeSent, firstSatelliteCoord, firstSatelliteTimeRecv, secondSatelliteCoord, secondSatelliteTimeRecv;
	std::cin >> timeSent >> firstSatelliteCoord >> firstSatelliteTimeRecv >> secondSatelliteCoord >> secondSatelliteTimeRecv;

	int distanceToFirst =  (firstSatelliteTimeRecv  - timeSent) / 2 * LIGHT_SPEED;
	int distanceToSecond = (secondSatelliteTimeRecv - timeSent) / 2 * LIGHT_SPEED;

	// Повтарям логиката тука: имаме 4 възможни точни, първия сателит +- дистаниця и втория сателит +- дистанция
	// Понеже данните не лъжат, трябва две от тези 4 възможности да съвпадат, и това проверяваме
	// Допускаме че входа е валиден, така че това работи
	if (firstSatelliteCoord + distanceToFirst == secondSatelliteCoord + distanceToSecond ||
		firstSatelliteCoord + distanceToFirst == secondSatelliteCoord - distanceToSecond)
		std::cout << (firstSatelliteCoord + distanceToFirst) << std::endl;
	else
		std::cout << (firstSatelliteCoord - distanceToSecond) << std::endl;
}
