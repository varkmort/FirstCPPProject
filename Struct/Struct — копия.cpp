#include <iostream>
#include <string>
#include <time.h> //ctime
#include <chrono>

struct Date {
    std::chrono::year year;
    std::chrono::month month;
    std::chrono::day day;
};

struct Student {
    std::string name;
    std::string surename;
    Date dateofbirth;//структура или относительная дата
    std::string studak;
};


int main()
{
    using std::cout;
    int arr[4]{9,4,3,96};
    Student stud{ 
        "ivan",
        "pupkin",
        Date{
            std::chrono::year(1992),
            std::chrono::month(4),
            static_cast<std::chrono::day>(5)},
        "PK-08993" 
};    
    Student group[]{
        stud,
        {"Frodo",
        "Baggins",
        Date{
            std::chrono::year(503),
            std::chrono::month(4),
            static_cast<std::chrono::day>(5)},
        "PK-08973" },
        {"Adolph",
        "Shekelgrubber",
        Date{
            std::chrono::year(1890),
            std::chrono::month(12),
            static_cast<std::chrono::day>(7)},
        "PK-07973" },
        {"Lambargini",
        "Mavlianov",
        Date{
            std::chrono::year(3992),
            std::chrono::month(1),
            static_cast<std::chrono::day>(16)},
        "PK-08979" },
        {"Fin",
        "Geckelberry",
        Date{
            std::chrono::year(1756),
            std::chrono::month(7),
            static_cast<std::chrono::day>(17)},
        "PK-08173" },
        {"Farit",
        "Mullagaliev",
        Date{
            std::chrono::year(1998),
            std::chrono::month(12),
            static_cast<std::chrono::day>(22)},
        "PK-08993" },
        {"Vladimir",
        "Jirinovskiy",
        Date{
            std::chrono::year(1932),
            std::chrono::month(3),
            static_cast<std::chrono::day>(17)},
        "PK-18973" }
    };

    for (int i = 0; i < std::size(group); i += 1) {
        cout << group[i].name << ' ' <<
            group[i].surename << ' ' <<
            group[i].dateofbirth.day << '.' <<
            group[i].dateofbirth.month << '.' <<
            group[i].dateofbirth.year << ' ' <<
            "No. stud: " << group[i].studak << '\n';
    }
    for (int i = 0; i < std::size(group); i += 1) {
        cout << "Enter name of student: ";
        std::cin >> group[i].name;
        cout << "Enter surename of student: ";
        std::cin >> group[i].surename;
        //    group[i].dateofbirth.day << '.' <<
        //    group[i].dateofbirth.month << '.' <<
        //    group[i].dateofbirth.year << ' ' <<
        cout << "Enter date of birth [dd mm yyyy]: ";
        {
            int tmp{};
            std::cin >> tmp;
            group[i].dateofbirth.day = 
                static_cast<std::chrono::day>(tmp);
            std::cin >> tmp;
            group[i].dateofbirth.month =
                static_cast<std::chrono::month>(tmp);
            std::cin >> tmp;
            group[i].dateofbirth.year =
                static_cast<std::chrono::year>(tmp);
        }
        cout << "Enter studak of student: ";
        std::cin >> group[i].studak;
    }
    for (int i = 0; i < std::size(group); i += 1) {
        cout << group[i].name << ' ' <<
            group[i].surename << ' ' <<
            group[i].dateofbirth.day << '.' <<
            group[i].dateofbirth.month << '.' <<
            group[i].dateofbirth.year << ' ' <<
            "No. stud: " << group[i].studak << '\n';
    }
    return 0;
}
/*
    создать программу для проведения соревнований
    всегд участвует всегда 10 участников

    программа различает участников по именам,
    номеру выступления, результату забега

    при регистрации вводится имя и номер выступления

    во время соревнования программе сообщают 
    номер забега и результат

    когда все результаты изветсны нужно вывести 
    на экран победителя и аутсайдера соревнований
*/

struct Runner {
    int num;
    std::string name;
    double result;
};

void Register(Runner *run, int size) {
    for (int i = 0; i < size; i++)
    {
        std::cout << "enter runner " << i + 1 <<
            " name: ";
        std::cin >> run[i].name;
        run[i].num = i + 1;
    }
}

void Runs(Runner* run, int size) {
    for (int i = 0; i < size; i++)
    {
        std::cout << "enter runners num: ";
        int tmp{};
        std::cin >> tmp;
        std::cout << "enter runners result: ";
        std::cin >> run[tmp - 1].result;
    }
}

Runner Min(Runner* run, int size) {
    Runner result{ run[0] };
    for (int i = 0; i < size; i++)
    {
        if (result.result > run[i].result) {
            result = run[i];
        }
    }
    return result;
}

Runner Max(Runner* run, int size) {
    Runner result{ run[0] };
    for (int i = 0; i < size; i++)
    {
        if (result.result < run[i].result) {
            result = run[i];
        }
    }
    return result;
}

void Task() {
    Runner runners[10]{};
    //============================================
    Register(runners, std::size(runners));
    //============================================
    Runs(runners, std::size(runners));
    //============================================
    Runner max{ Max(runners, std::size(runners)) };
    Runner min{ Min(runners, std::size(runners)) };
   
    //============================================
    std::cout << "Best " << min.num << ' ' <<
        min.name << ' ' << min.result << '\n';
    std::cout << "Worst " << max.num << ' ' <<
        min.name << ' ' << max.result << '\n';
}