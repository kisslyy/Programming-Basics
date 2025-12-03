#include <iostream>
#include <string>
#include <fstream>

int main() {

	std::fstream input("input.txt");

	if (!input.is_open()) {
		return 1;
	}

	char a = 'á';
	char b = 'b';

	std::cout << a << " " << b << std::endl;

	while (!input.eof()) {

	}
}
