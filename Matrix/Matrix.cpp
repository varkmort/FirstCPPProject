#include <iostream>
#include <iomanip>
#include <random>


void TaskOneMatrix(int coll, int rows) {
	int** Arr = new int* [rows] {};
	for (int i = 0; i < rows; i++) {
		Arr[i] = new int [coll] {};
	}
	//================================
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distr(10, 99);
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < coll; j++){
			Arr[i][j] = distr(gen);
		}
	}
	//================================
	std::cout << "Matrix:\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < coll; j++) {
			std::cout << std::setw(3) << 
				Arr[i][j] << ' ';
		}
		std::cout << '\n';
	}
	//================================
	int avg{};
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < coll; j++) {
			avg += Arr[i][j];
		}
	}
	avg = static_cast<double>(avg) / (coll * rows);
	std::cout << "Average value = " << avg << '\n';
	//================================
	int minorCount{};
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < coll; j++) {
			if (Arr[i][j] < avg) {
				minorCount += 1;
			}

		}
	}
	int* minors = new int [minorCount] {};
	for (int i = 0, k = 0; i < rows; i++) {
		for (int j = 0; j < coll; j++) {
			if (Arr[i][j] < avg) {
				minors[k] = Arr[i][j];
				k += 1;
			}
		}
	}
	std::cout << "Minors elements:\n";
	for (int i = 0; i < minorCount; i++)	{
		std::cout << std::setw(3) <<
			minors[i]<< ' ';
	}
	//================================
	delete[] minors;
	for (int i = 0; i < rows; i++) {
		delete[] Arr[i];
	}
	delete[] Arr;
}

int main() {
	TaskOneMatrix(3, 3);
	return 0;
}


void main2() {
	//создание матрицы
	int collumns{ 8 };
	int rows{ 3 };
	int **Arr = new int* [rows]{};
	for (int i = 0; i < rows; i++){
		Arr[i] = new int [collumns]{};
	}
	//==============================
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < collumns; j+=1 ){
			std::cout << std::setw(3) << 
				Arr[i][j] << ' ';
		}
		std::cout << '\n';
	}
	//===============================
	//удаление матрицы
	for (int i = 0; i < rows; i++)	{
		delete[] Arr[i];
	}
	delete[] Arr;
}

// задание 1
/*
	запросить у пользователя сколько столбцов 
	и строк должно быть в матрице.
	создать матрицу и заполнить её случайными 
	двузначными числами
	найти среднее значение матрицы
	создать новый динамический массив
	в котором будут содержаться все элементы 
	меньше среднего значения
*/
/*
	создать двумерный массив на 11 строк
	первая строка 5 элементов
	каждая последующая на 1 элемент больше

	заполнить элементы числами от -10 до 10
	вывести на экран массивтак чтобы 
	отрицательные элементы заменялись на звёздочки
*/


