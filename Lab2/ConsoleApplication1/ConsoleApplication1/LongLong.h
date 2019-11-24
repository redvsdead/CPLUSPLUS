#pragma once
#include <cstring>
#include <iostream>

using namespace std;

class LongLong
{
	int32_t high;
	uint32_t low;

public:

	////////////////// ВСПОМОГАТЕЛЬНОЕ
	void SetNum(string num);	//сеттер для старшей/младшей частей
	int32_t GetHigh();
	uint32_t GetLow();
	void SetHigh(int32_t n);
	void SetLow(uint32_t n);
	void Print();				//печать на экран

	////////////////// АРИФМЕТИЧЕСКИЕ ОПЕРАЦИИ
	void Equality(class LongLong a, class LongLong b);				//сравнение
	void Multiplication(class LongLong a, class LongLong b);		//произведение
	void Division(class LongLong a, class LongLong b);				//частное
	void Addition(class LongLong a, class LongLong b);				//сумма
	void Subtraction(class LongLong a, class LongLong b);			//разность
};

