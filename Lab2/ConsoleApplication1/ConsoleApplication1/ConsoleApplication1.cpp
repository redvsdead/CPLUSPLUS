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
		cin >> num;
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

	one.SetNum("1");
	assert(one.low == 1);
	assert(one.high == 0);


	one.SetNum("-1");
	assert(one.low == 0xFFFFFFFF);
	assert(one.high == 0xFFFFFFFF);



	one.SetNum("-2"); 
	assert(one.low == 0xFFFFFFFE);
	assert(one.high == 0xFFFFFFFF);


	one.SetNum("+???100000000????");
	assert(one.low == 0);
	assert(one.high == 1);


	one.SetNum("-??????1");
	assert(one.low == 0xFFFFFFFF);
	assert(one.high == 0xFFFFFFFF);



	one.SetNum("-??????2");
	assert(one.low == 0xFFFFFFFE);
	assert(one.high == 0xFFFFFFFF);

	one.SetNum(EnterNum(1));
	two.SetNum(EnterNum(2));
	std::cout << std::hex << "\n";
	one.Print();
	two.Print();

	bool ok = answer.Equality(one, two);

	answer.Addition(one, two);
	std::cout << "Сумма: ";
	answer.Print();

	/*if (!ok)
	{
		answer.Subtraction(two, one);
		std::cout << "Разность: ";
		std::cout << "-";
		answer.Print();
	}
	else
	{*/
	answer.Subtraction(one, two);
	std::cout << "Разность: ";
	answer.Print();
	//}
	answer.Multiplication(one, two);
	std::cout << "Произведение: ";
	answer.Print();
	/*
	answer.Division(one, two);
	std::cout << "Частное: ";
	answer.Print();
	*/
}
