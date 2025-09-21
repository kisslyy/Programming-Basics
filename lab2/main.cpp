#include <iostream>
#include <cmath>

bool inBounds(int num) {
	return num >= -100 && num <= 100;
}

int main() {

	int originalNumber;
	std::cout << "Enter 4 digits number: ";
	std::cin >> originalNumber;

	if (originalNumber < 1000 || originalNumber > 9999) {
		std::cout << "Number must be 4 digits long\n";
		return 0;
	}

	int revercedNumber = 0;
	for (int i = 0; i < 4; i++) {
		revercedNumber = revercedNumber * 10 + originalNumber % 10;
		originalNumber = originalNumber / 10;
		//std::cout << revercedNumber << ", " << originalNumber << std::endl;
	}

	std::cout << revercedNumber << std::endl;

	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;

	std::cout << "Enter x and y coordinates for the first point: ";
	std::cin >> x1;
	std::cin >> y1;
	std::cout << "Enter x and y coordinates for the second point: ";
	std::cin >> x2;
	std::cin >> y2;

	if (!(inBounds(x1) && inBounds(y1) && inBounds(x2) && inBounds(y2))) {
		std::cout << "Coordinates must be >= -100 and <= 100\n";
		return 0;
	}

	float distance = std::sqrtf(std::powf(x2 - x1, 2) + std::powf(y2 - y1, 2));

	std::cout << "Distance: " << distance << std::endl;

	return 0;
}
