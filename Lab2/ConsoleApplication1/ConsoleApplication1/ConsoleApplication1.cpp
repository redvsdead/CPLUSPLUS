#include "pch.h"
#include "LongLong.h"
#include <iostream>
#include <string>
using namespace std;


//проверка строки на то, является ли она числом
string EnterNum(int i)
{
	cout << "Введите " << i << "-е число" << endl;
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
			cout << "Введенная строка не является числом. Попробуйте снова." << endl;
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
	one.Print();
	two.Print();

	bool ok = answer.Equality(one, two);

	answer.Addition(one, two);
	cout << "Сумма: ";
	answer.Print();

	answer.Subtraction(one, two);
	cout << "Разность: ";
	answer.Print();

	answer.Multiplication(one, two);
	cout << "Произведение: ";
	answer.Print();
}
