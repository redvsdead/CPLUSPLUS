#include "pch.h"
#include "LongLong.h"
#include <iostream>
#include <string>
using namespace std;


//проверка строки на то, является ли она числом
string EnterNum(int i)
{
	std::cout << "Введите " << i << "-е число" << endl;
	string num;
	bool ok;
	bool again = true;
	while (again)
	{
		int i = 1;
		std::cin >> num;
		ok = (num[0] == '-') || ((num[0] <= '9') && (num[0] >= '0'));	//проверка на наличие минуса или цифр в начале
		while (ok && i < num.length())
		{
			ok = (num[i] <= '9') && (num[i] >= '0');					//проверка на цифры
			i++;
		}
		again = !ok;
		if (again)
		{
			std::cout << "Введенная строка не является числом. Попробуйте снова." << endl;
		}
	}
	return num;
}



int main()
{
	setlocale(LC_ALL, "Russian");
	LongLong one, two, answer;
	one.SetNum(EnterNum(1));
	two.SetNum(EnterNum(2));
	std::cout << "\n";
	one.Print();
	two.Print();

	answer.Equality(one, two);

	answer.Addition(one, two);
	std::cout << "Сумма: ";
	answer.Print();

	answer.Subtraction(one, two);
	std::cout << "Разность: ";
	answer.Print();

	answer.Multiplication(one, two);
	std::cout << "Произведение: ";
	answer.Print();

	answer.Division(one, two);
	std::cout << "Частное: ";
	answer.Print();
}
