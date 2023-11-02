#include <iostream>

int main() {
	unsigned int time = 0;
	char input;
	unsigned int mode = 0;
	bool twelveHour = false;
	while (true) {
		std::cin >> input;
		switch (input) {
			case 'c':
				if (mode == 0) {
					unsigned newHour;
					std::cin >> newHour;
					time = 60 * newHour + time % 60;
				}
				else if (mode == 1) {
					unsigned newMinutes;
					std::cin >> newMinutes;
					time = (time - time % 60) + newMinutes;
				}
				mode = (mode + 1) % 3;
				twelveHour = !twelveHour;
			case 'f':
				twelveHour = !twelveHour;
				if (mode == 0) {
					time -= 1;
				}
			case 't':
				if (mode == 0) {
					time = (time + 1) % 1440; // 60 minutes * 24 hours
				}
				if (twelveHour) {
					bool pm = (time / 60) > 12;
					std::cout << (time / 60) - 12 * pm << ":" << (time % 60) << " " << (pm ? "PM" : "AM") << std::endl;
				}
				else {
					std::cout << (time / 60) << ":" << (time % 60) << std::endl;
				}
				break;
		}
	}
}
