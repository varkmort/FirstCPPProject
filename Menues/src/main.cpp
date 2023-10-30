#include <iostream>
#include <string>
#include <ctime>
#include <random>
void Name() {
	std::random_device rd{};
	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> distr(1, 14);

	int rNum = distr(gen);
	std::cout << distr(gen);
}

int main() {
	///demo for menue exploring
	::srand(time(NULL));
	//main menue
	std::cout << R"(основное меню приложения:
	1 - первое подменю
	2 - второе подменю
	3 - третье подменю
	4 - выход)";
	switch (std::cin.get())
	{
	case '1':
		//новый свитч
		break;
	case '2':
		//новый свитч
		break;
	case '3':
		//новый свитч
		break;
	case '4':
		//выход из программы
		::exit(0);
	default:
		break;
	}




	return 0;
}
