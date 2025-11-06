#include <iostream>

void task1() {
	int x = 100;
	int* p = &x;
	int* q = p - 1;

	std::cout << "p = " << p << std::endl;
	std::cout << "q = " << q << std::endl;
	std::cout << "p - q = " << p - q << std::endl;

	std::cout << *q << std::endl;
	// ЌеопределЄнное поведение, потому что поинтер q
	// указывает на рандомный адрес в стеке
}

void task2() {
    const int size = 12;
    short* p_arr = new short[size];

    short* p = p_arr + size - 1;

    for (int i = 0; i < size; ++i) {
        *p = (i + 1) * 2;
        p--;
    }

    short* q = p_arr;
    for (int i = 0; i < size; ++i) {
        std::cout << *(q + i) << " ";
    }
    std::cout << std::endl;

    delete[] p_arr;
}

int main() {
    task1();
    std::cout << "\n\n\n";
    task2();
}
