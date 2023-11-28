#include <iostream>

#define LENGTH 20

#define MAX(A, B) (A<B)?B:A

#define DOUBLE_FUNC

const int g_length{ 10 };


#ifdef INT_FUBC

int Gen() {
	return ::rand() % 101;
}
#endif // INT_FUBC

#ifdef DOUBLE_FUNC 
double Gen() {
	return (::rand() % 100) + 1. / (::rand()%100+1);
}
#endif 


#ifdef HAS_CXX20
double Gen();
#endif // HAS_CXX20


#include "Phisics.hpp"

int main()
{
#ifdef DEBUG
	::srand(123u);
#else
	::srand(::time(NULL));
#endif // RELEASE

	double arr[LENGTH]{};
	for (auto& i : arr)
	{
		i = Gen();
		EnergyFull(i);
	}
	for (auto& i : arr)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
	for (int i = 0; i < std::size(arr); i++)
	{
		std::cout << "i - try: " << arr[i]<< " max " <<
			std::max(arr[i], double(Gen())) << '\n';
	}

	return 0;
}