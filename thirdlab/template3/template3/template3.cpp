// задача 11 a)
// динамический массив, хранящий элементы произвольного типа
/*
   должны быть описаны функции:
   - инициализация массива
   - добавление эл. в начало
   - добавление эл. в конец
   - показ всех эл.
   - удаление всех эл.
   - поверка на пустоту
   - удаление первого элемента
   - удаление последнего элемента
*/

#include "pch.h"
#include "dynamic.h"
#include <iostream>
#include <string>

int main()
{
	string k = "-";
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите целые числа" << endl;
	dynamic<int> arr_i;
	std::getline(std::cin, k);
	while (k != "")
	{
		arr_i.push_tail(atoi(k.c_str()));
		std::getline(std::cin, k);
	}
	if (!arr_i.empty())
	{
		std::cout << "Размер: " << arr_i.get_size() << endl;
		arr_i.print();
	}
	else
	{
		std::cout << "Массив пуст." << endl;
	}
	arr_i.delete_head();
	std::cout << "Первый элемент удален:" << endl;
	if (!arr_i.empty())
	{
		std::cout << "Размер: " << arr_i.get_size() << endl;
		arr_i.print();
	}
	else
	{
		std::cout << "Массив пуст." << endl;
	}
	arr_i.clear();

/////////////////////////////////////////////////

	k = "-";
	std::cout << "Введите строки" << endl;
	dynamic<string> arr_s;
	std::getline(std::cin, k);
	while (k != "")
	{
		arr_s.push_head(k); 
		std::getline(std::cin, k);
	}
	if (!arr_s.empty())
	{
		std::cout << "Размер: " << arr_s.get_size() << endl;
		arr_s.print();
	}
	else
	{
		std::cout << "Массив пуст." << endl;
	}
	arr_s.print();
	arr_s.delete_tail();
	std::cout << "Последний элемент удален:" << endl;
	if (!arr_s.empty())
	{
		std::cout << "Размер: " << arr_s.get_size() << endl;
		arr_s.print();
	}
	else
	{
		std::cout << "Массив пуст." << endl;
	}
	arr_s.clear();
}
