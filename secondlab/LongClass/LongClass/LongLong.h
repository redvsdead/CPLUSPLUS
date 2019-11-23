#pragma once
#include <cstring>
#include <iostream>

using namespace std;

class CLongLong
{
	int32_t High;
	uint32_t Low;
	bool Check(string& num);
	const uint32_t max = 4294967295;

public:

	CLongLong();
	~CLongLong();
	
	void SetNum(string num);	//сеттер для старшей/младшей частей

	void Addition();			//сумма
	void Subtraction();			//разность
	void Multiplication();		//произведение
	void Division();			//частное
	void Equality();			//равенство
	void Print();				//печать на экран
};