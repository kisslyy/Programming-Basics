#include <iostream>

void numberGuesser() {

	std::cout << "������ �����" << std::endl;

	srand(time(NULL));

	int randomNumber = rand() % 101;
	int guess = -1;
	int tries = 0;

	std::cout << "debug: " << randomNumber << std::endl;

	while (true)
	{
		std::cin >> guess;
		tries++;

		if (guess > randomNumber) {
			std::cout << "������� �����" << std::endl;
		}
		else if (guess < randomNumber) {
			std::cout << "������� ����" << std::endl;
		}
		else {
			std::cout << "�����! �� ������ �� " << tries << " �������!" << std::endl;
			break;
		}
	}
}

void processTransaction(int cost, int inputMoney) {
	if (inputMoney < cost) {
		std::cout << "������������ �������! ����� " << inputMoney << "�." << std::endl;
	}
	else
	{
		std::cout << "������� �������! ����� " << inputMoney - cost << "�." << std::endl;
	}
}

void vendingMachine() {

	std::string soda;
	int inputMoney = 0;
	int change = 0;

	while (true) {

		std::cout << "������� �� ������� ��������" << std::endl;
		std::cout << "����� ������� ���������? (���� - 50�, ���� - 80�, ��������� - 150�)" << std::endl;
		std::cin >> soda;

		std::cout << "����� ����� �������?" << std::endl;
		std::cin >> inputMoney;

		if (soda == "voda") {
			processTransaction(50, inputMoney);
		}
		else if (soda == "kola") {
			processTransaction(80, inputMoney);
		}
		else if (soda == "energy") {
			processTransaction(150, inputMoney);
		}
		else {
			std::cout << "������� " << soda << " ��� � �������." << std::endl;
		}

		std::cout << std::endl;
	}
}


int main() {

	setlocale(LC_ALL, "Russian");

	numberGuesser();

	std::cout << std::endl;

	vendingMachine();

	return 0;
}