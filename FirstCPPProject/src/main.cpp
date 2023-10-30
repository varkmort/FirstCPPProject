#include <iostream>
#include <string>
#include <iomanip>
#include <format>

// форматирование вывода
// реализуется через флаги потока
//		любая библиотека работы с потоками
//		даёт метод setf для потока
// std::cout.setf(std::ios::scientific);
// второй вариант - манипуляторы потоков
// хранятся в библиотеке iomanip

// cout - console output, стандартное 
//				общение с пользователем
// cerr - console error, сообщение об ошибках
// clog - console log, служебные сообщения программы
// cin - console input, стандартный 
//				поток ввода данных
//

/*
	основные типы данных
	int			- целые числа
		char, short, int, long, long long
		__int8, __int16,
		8 >= 8
	double		- числа с плавающей точкой
		float double long double
		ieee
		98568,95367
	bool		- логические значения
	char		- символы
	std::string	- строки
*/


int main1() {
	
	int age{};
	std::cout << "Hello! \n";
	std::cout << "Huw old are you?\n";
	std::cin >> age;
	if (age < 10 && age > 0) {
		std::cout << "go away kid!";
	}
	else if (age < 18) {
		std::cout << "good luck fellow!";
	}
	else {
		std::cout << "doomsday are near!";
	}
	//using namespace std;
	std::cout << "\n" << (char)201 << (char)205 <<
		(char)205 << 
		static_cast<char>(187);
	return 0;
}

int main() {
	int arrNums[]{ 9,45,8,15,3,0,7,9 };
	bool arrLogic[]{ 0,1,1,1,0,0,0,1 };
	int i = 0;
	while (i < 8) {
		std::cout << '|' << std::setw(5) <<
			std::setfill(' ')<<
			arrNums[i] << '|' << std::setw(7) <<
			std::setfill('_') << arrLogic[i] <<
			"|\n";
		i += 1;
	}
	//auto tmp = std::format("54654654{}", 12);
}