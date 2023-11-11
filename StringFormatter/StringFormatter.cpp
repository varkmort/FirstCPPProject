// StringFormatter.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// форматирование вывода текста
//

#include <iostream>
#include <cstdio> //stdio.h
#include <format>

void C_style() {
    char simbol{'q'};
    std::string str{ "words" };
    double numbers{ 48.76539 };
    int int_numb{ 65498 };
    bool logic{ true };
    printf("Hello! We print %s\n",str.c_str());
    printf("Also we can put '%-7i' in the phrase\n", int_numb);
    printf("Floated point %e in scientific form \n", numbers);
    printf("Floated point %5.2f in floated form\n", numbers);
    printf("Floated point %g in shorter posible form\n", numbers);
    printf("integer %x in hex form\n", int_numb);
    printf("integer %o in oct form\n", int_numb);
    printf("char \"%c\" as is and \'%d\' as int\n", simbol, simbol);
    //%p - указатели
    //https://www.c-cpp.ru/content/printf
}

template<typename... Args>
std::string dyna_print(std::string_view rt_fmt_str, Args&&... args)
{
    return std::vformat(rt_fmt_str, std::make_format_args(args...));
}

void CPP_style() {
    std::string fmt{ "string {}, with {}, putted {}, walues\n" };
    int int_numb{ 65498 };
    std::cout <<
        std::format("Hello, {}, {}", "world\n", int_numb);
    std::cout <<
        dyna_print(fmt,1,"sdfgsdfg", 6.7) <<'\n';
//https://en.cppreference.com/w/cpp/utility/format/formatter
}

int main()
{
    C_style();
    CPP_style();
}
