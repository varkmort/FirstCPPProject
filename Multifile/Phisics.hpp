#pragma once

#ifndef PHISICS_HPP
#define PHISICS_HPP

extern const double c;// ���������� ���������� ��������� ����������� � ������������
// ��� ������ ����������

double Velocity(double a, double t);

inline double EnergyFull(double mass) {
	return mass * c;
}//������������ ������� ����������� ����� � �������������


template <typename Type>
Type ContertTime(double t)
{
	return Type(t);
}// ������� ������ ����� � ������������ �����

#endif //PHISICS_HPP