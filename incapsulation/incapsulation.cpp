// incapsulation
// инкапсуляция - механизм языка позволяющий
// объединять данные с методами их обработки
// и дающий возможность применять сокрытие данных

#include <iostream>
#include <cmath>

struct Point2D {
    double x;
    double y;

    bool IsEqual(const Point2D& B, const double eps= 0.01) {
        double dX = ::abs(x - B.x);
        double dY = ::abs(y - B.y);
        return dX <= eps && dY <= eps;
    }
};

struct Segment {
    Point2D A;
    Point2D B;

    double Length() {
        
    }
    //написать встроенные функции нахождения длинны отрезков
    // и сравнения отрезков на равенство, больше, меньше
    // с определённой точностью
    bool IsEqual();
};


// (3.4, 5.6) (3.399999, 5.6000001)

bool IsEqual(
    const Point2D& A,
    const Point2D& B,
    const double eps= 0.01) {
    double dX = ::abs(A.x - B.x);
    double dY = ::abs(A.y - B.y);
    return dX <= eps && dY <= eps;
}

int main()
{
    Point2D One{ 3.4, 5.6 };
    Point2D Two{ 3.399999, 5.6000001 };
    Segment AB{ {0.5, 1.}, {2.9, 8.} };

    auto answer = IsEqual(One, Two, 0.0001);
    answer = One.IsEqual(Two, 0.02);
}
