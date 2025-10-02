#include <iostream>
#include <bitset>

int main() {

	int x;
	int i;
	int bit;

	std::cin >> x;
	std::cin >> i;

	bit = (x >> i & 1);
	/*
	std::cout << std::bitset<32>(x) << "  x" << std::endl;
	std::cout << std::bitset<32>(x >> i) << "  x >> i" << std::endl;
	std::cout << std::bitset<32>(1) << "  1" << std::endl;
	std::cout << std::bitset<32>(x >> i & 1) << "  i & 1" << std::endl;
	*/
	std::cout << bit << std::endl;

	return 0;
}