#include <iostream>

void numberGuesser() {

	std::cout << "Угадай число" << std::endl;

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
			std::cout << "Слишком много" << std::endl;
		}
		else if (guess < randomNumber) {
			std::cout << "Слишком мало" << std::endl;
		}
		else {
			std::cout << "Точно! Ты угадал за " << tries << " попыток!" << std::endl;
			break;
		}
	}
}

void processTransaction(int cost, int inputMoney) {
	if (inputMoney < cost) {
		std::cout << "Недостаточно средств! Сдача " << inputMoney << "р." << std::endl;
	}
	else
	{
		std::cout << "Покупка успешна! Сдача " << inputMoney - cost << "р." << std::endl;
	}
}

void vendingMachine() {

	std::string soda;
	int inputMoney = 0;
	int change = 0;

	while (true) {

		std::cout << "Автомат по продаже напитков" << std::endl;
		std::cout << "Какой напиток выбираете? (вода - 50р, кола - 80р, энергетик - 150р)" << std::endl;
		std::cin >> soda;

		std::cout << "Какую сумму вносите?" << std::endl;
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
			std::cout << "Напитка " << soda << " нет в наличии." << std::endl;
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