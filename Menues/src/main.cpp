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
	std::cout << R"(�������� ���� ����������:
	1 - ������ �������
	2 - ������ �������
	3 - ������ �������
	4 - �����)";
	switch (std::cin.get())
	{
	case '1':
		//����� �����
		break;
	case '2':
		//����� �����
		break;
	case '3':
		//����� �����
		break;
	case '4':
		//����� �� ���������
		::exit(0);
	default:
		break;
	}




	return 0;
}
