#include <iostream>
#include <string>

#include <random>//��������� ����� ��� �����
#include <cstdlib>//��������� ����� ��� ����������

#include <clocale>//��������� ����� ��� ���������
// ������� �� �������� ������ � ��������������
// � ������� �������

#include <windows.h>//��������� ����� ��� ���������
//��������� �� ����� �������� ���� ����� �� �����

/*
	1 ������� ������������ ��� ������ � ���������
		��������� ����
	2 ��������� ������ ��������� ����� ������ 
		��������� �����
	3 � ������������ ����� �������� ������� �����
	4 ������� ��� ����� ���������� ����� �� 
		�������� ��������� �������������
		�� �������� ����������(�����������)
//=================================================
	5 ��������� ��������� �������� � ������������� 
		�� ������
	6 ���������� ������ � ���������� � ���������� 
		����������� ��� ������ ��������� ����
	7 ����� � ���������(�� ���� ������������)
		������������ ��������
//=================================================
�� 13:15  - ���� ��������
*/

//����� ���� enum

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
	// ������ ���� ��� ��������
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
		//���� �� ����� �� ����� ����� ��������� switch
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
	// ������� ��� 1 ������
	// ������� ��� 2 ������
	//...
	// ������� ��� ��������� ������

	return 0;
}