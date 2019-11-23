#include "pch.h"
#include "LongLong.h"
#include <ctime>
using namespace std;


	/*CLongLong::high = 0;
	CLongLong::low = 0;*/

bool CLongLong::Check(string& num)
{
	int i = 0;
	while (num[i] == ' ' || num[i] == '\t')
	{
		i++;
	}
	if (i > 0)
	{
		int j;
		for (j = 0; j < num.length; j++)
		{
			num[j] = num[j + 1];
		}
		num[j] = '\0';
	}
	if (num[0] == '-' || (num[0] >= '0' & num[0] <= '9'))
	{
		bool ok = true;
		int k = 0;
		while (ok)
		{
			k++;
			ok = k < (num.length) & num[k] >= '0' & num[k] <= '9';
		}
		if (k = num.length)
		{
			return true;
		}
	}
	return false;
}


void CLongLong::SetNum(string num)
{
	High = (int32_t)(atol(num.c_str()) & 0xFFFFFFFF00000000LL >> 32);
	Low = (uint32_t)(atol(num.c_str()) & 0xFFFFFFFFLL);
}

void Addition();			//сумма
void Subtraction();			//разность
void Multiplication();		//произведение
void Division();			//частное
void Equality();			//равенство
void Print();				//печать на экран