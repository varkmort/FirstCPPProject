#include <iostream>
#include <set>

#include <string>
#include <Windows.h>

#ifdef WIN32

#include <clocale>

#else

#include <posix>

#endif // WIN32

#ifdef _HAS_CXX20

#endif // _HAS_CXX20

int summ(int a, int b) {
    return a + b;
}

float summ(float a, float b) {
    return a + b;
}

#include "Phisics.hpp"
#include "Examples.hpp"

int main()
{
#ifdef WIN32
    ::SetConsoleCP(CP_UTF8);
    ::SetConsoleOutputCP(CP_UTF8);
    ::setlocale(LC_ALL, "RUS");
#endif // WIN32
    Ex();
    std::wstring str;
    str = L"Влад молодец";

    std::wcout << Velocity(1.,5.) << EnergyFull(123);

    return 0;
}
