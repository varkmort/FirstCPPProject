#pragma once

#ifndef PHISICS_HPP
#define PHISICS_HPP

extern const double c;// объ€влени€ глобальных пременных раздел€ютс€ с определен€ми
// это пример объ€влени€

double Velocity(double a, double t);

inline double EnergyFull(double mass) {
	return mass * c;
}//встраиваемые функции об€зательно живут в заголовочнике


template <typename Type>
Type ContertTime(double t)
{
	return Type(t);
}// шаблоны всегда живут в заголовочном файле

#endif //PHISICS_HPP