#include <iostream>

//шаблоны функций и структур

// шаблоны функций, типов данных, переопределений
// шаблон простой, зависимый, вариативный, рекурсивный

int Summ(int a, int b) { return a + b; }
bool Summ(bool a, bool b) { return a | b; }

template<typename MyPreciosName>
MyPreciosName Summ(MyPreciosName a, MyPreciosName b) { return a + b; }
// 3 если есть подходящаяя функция 
// то шаблон вызван не будет

template<>
bool Summ<bool>(bool a, bool b) { return a | b; }

// 1 шаблоны заменяют собой перегрузки функций
// 2 шаблоны инстанциируются только на этапе компиляции
// 4 при необходимости можно создать 
//      специализацию шаблона
// 5 если шаблон не используется то его нет 
//      в исполняемом файле программы


void F00() {
    Summ<long>(5.6, 2.6);
    Summ(true, false);
}

//int Func(int arg0, ...);
//
//void Ex() {
//    Func(4, 4, 2, 2, 2, 1, 3, 6, 3);
//}

//Структуры данных
//  массивы
//  списки
//  деревья
//  графы
//      стеки   FILO
//      очередь FIFO
// 
// массив линейный
// |___|___|___|___|
// ^где начало,  сколько ячеек есть
//

template<typename MyPreciosName>
struct LinearArray {
    int size;
    MyPreciosName *data;
};

// создание                         O(n)
// удаление                         O(n)
//   доступ к элементу              O(1)
//   добавить новый элемент         O(n)
//   удалить элемент из массива     O(n)
//   поиск элемента                 O(n)
// Реализовать данные функции 10.10
// преобразовать их в шаблоны 11.10

template<typename MyPreciosName, class Array=LinearArray<MyPreciosName>>
Array Create(int size) {
    Array result{};
    result.data = new MyPreciosName[size] {};
    // new - оператор для выделения памяти и
    // инициализации данных в ней
    // new new[]
    result.size = size;
    return result;
}

void Destroy(LinearArray &obj){
    delete[] obj.data;
    // delete - оператор который уничтожает
    // объекты в выделенной памяти
    // а затем освобождает память
    // delete delete[] - 2 формы
    obj.data = nullptr;
    obj.size = 0;
}

template<typename MyPreciosName>
MyPreciosName& At(LinearArray<MyPreciosName> &obj, int pos){
    return obj.data[pos];
}

template<typename MyPreciosName>
const MyPreciosName & At(const LinearArray<MyPreciosName> &obj, int pos){
    return obj.data[pos];
}

//   добавить новый элемент         O(n)
void Emplase(LinearArray& obj,int pos,int val){
    if (pos > obj.size + 1 || pos < 0) return;
    auto tmp = new int[obj.size + 1]{};
    for (int i = 0; i < pos; i++){
        tmp[i] = obj.data[i];
    }
    tmp[pos] = val;
    for (int i = pos+1; i < obj.size; i++){
        tmp[i] = obj.data[i-1];
    }
    std::swap(tmp, obj.data);
    obj.size += 1;
    delete[] tmp;
}
//   удалить элемент из массива     O(n)
void Delete(
    const LinearArray& obj,
    int pos) 
{

}
//   поиск элемента                 O(n)
//int & Find(
//    const LinearArray& obj,
//    int val) {
//
//}

int main(){
    auto arr = Create<float>(6);
    arr.data[1] = 6;
    At(arr, 0) = 8;
}