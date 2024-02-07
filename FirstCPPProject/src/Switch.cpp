#include <iostream>
#include <string>

#include <random>//случайные числа для умных
#include <cstdlib>//случайные числа для мазохистов

#include <clocale>//изменение языка для программы
// простая но работает только с установленными
// в системе языками

#include <windows.h>//изменение языка для программы
//посложнее но будет работать пока винда не помрёт

/*
	1 создать перечисления для мастей и номиналов
		игральных карт
	2 программа должна запомнить какую нибудь 
		игральную карту
	3 с пользователя нужно спросить номинал карты
	4 вывести все карты загаданной масти от 
		номинала введённого пользователем
		до номинала загаданной(запомненной)
//=================================================
	5 заставить программу общаться с пользователем 
		по русски
	6 обеспечить работу в восходящем и нисходящем 
		направлении при выводе номиналов карт
	7 карта в программе(не ввод пользователя)
		генерируется случайно
//=================================================
до 13:15  - надо доделать
*/

//здесь живёт enum

enum PhoneCode {
	Canada = 1,
	Chad = 2,
	NorthKorea,
	Mongolia=897,
	KiriBati,
	NewZealand,
	RUS = 7
};

int main(){
	// здесть живёт ваш алгоритм
	PhoneCode pc{};
	//std::cin >> pc;
	std::string tmp{};
	std::cin >> tmp;
	pc = static_cast<PhoneCode>(std::stoi(tmp));
	PhoneCode memoredCode{ PhoneCode::NorthKorea};

	switch (pc) {
	case PhoneCode::Canada:
		std::cout << "Canada - " << PhoneCode::Canada <<
			'\n';
		//если мы дошли до конца тогда прерываем switch
	case PhoneCode::Chad:
		std::cout << "Chad - " << PhoneCode::Chad <<
			'\n';
	case PhoneCode::NorthKorea:
		std::cout << "North Korea - " << PhoneCode::NorthKorea <<
			'\n';
	case PhoneCode::Mongolia:
		std::cout << "Mongolia - " << PhoneCode::Mongolia <<
			'\n';
	case PhoneCode::KiriBati:
		std::cout << "Kiri Bati - " << PhoneCode::KiriBati <<
			'\n';
	case PhoneCode::NewZealand:
		std::cout << "New Zealand - " << PhoneCode::NewZealand <<
			'\n';
		break;
	case PhoneCode::RUS:
		std::cout << "Russia - " << PhoneCode::RUS <<
			'\n';
	}
	// вывести код 1 страны
	// вывести код 2 страны
	//...
	// вывести код последней страны

	return 0;
}