#include "pch.h"
#include "LongLong.h"
#include <ctime>
using namespace std;

void LongLong::SetNum(string num)
{																									
	cout << atoll(num.c_str()) << endl;
	high = static_cast<int32_t> (((atoll(num.c_str())) & 0xFFFFFFFF00000000LL) >> 32);
	low = static_cast<uint32_t>((atoll(num.c_str())) & 0xFFFFFFFFLL);
}

int32_t LongLong::GetHigh()
{
	return high;
}

uint32_t LongLong::GetLow()
{
	return low;
}

void LongLong::SetHigh(int32_t n)
{
	high = n;
}

void LongLong::SetLow(uint32_t n)
{
	low = n;
}

void LongLong::Print()
{
	long long n = (static_cast<long long>(high) << 32) | low;
	std::cout << n << "\n";
}

////////////////////////

bool LongLong::Equality(class LongLong a, class LongLong b) 				//сравнение
{
	bool ok = (a.high == b.high) && (a.low == b.low);
	if (ok)
	{
		std::cout << "Числа равны" << "\n";
		return true;
	}
	else
	{
		if (a.high > b.high)
		{
			std::cout << "Первое число больше" << endl;
			return true;
		}
		else
		{
			if (a.high < b.high)
			{
				std::cout << "Первое число меньше" << endl;
				return false;
			}
			else
				if (a.low > b.low)
				{
					std::cout << "Первое число больше" << endl;
					return true;
				}
				else
					std::cout << "Первое число меньше" << endl;
			return false;
		}
	}
	}

void LongLong::Multiplication(class LongLong a, class LongLong b)					//произведение
{
	long long overflow;

	overflow = a.low * b.low;
	high = static_cast<int32_t>((overflow & 0xFFFFFFFF00000000LL) >> 32);			//младшая х младшая
	low = static_cast<uint32_t>(overflow & 0xFFFFFFFFLL);
	
	high += (a.high * b.low) & 0xFFFFFFFFLL;										//старшаяя х младшая накрест
														
	high = (a.low * b.high) & 0xFFFFFFFFLL;											//младшая х старшая накрест

	high += (a.high * b.high) << 32;												// старшая х старшая
}

void LongLong::Division(class LongLong a, class LongLong b)							//частное
{

}

void LongLong::Addition(class LongLong a, class LongLong b)							//сумма
{
	bool overflow = (0xFFFFFFFFLL - a.low) <= b.low;
	if (overflow)
	{
		low = a.low - 0xFFFFFFFFLL+ 1 + b.low;
		high++;
	}
	else
	{
		low = a.low + b.low;
	}
	high = a.high + b.high;
}

void LongLong::Subtraction(class LongLong a, class LongLong b)			//разность
{
	high = a.high - b.high;
	if (a.low < b.low)
	{
		
		low = a.low << 32 - b.low;
	}
	else
	{
		low = a.low - b.low;
	}
}