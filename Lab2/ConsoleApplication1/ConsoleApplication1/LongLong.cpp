#include "pch.h"
#include "LongLong.h"
#include <ctime>
using namespace std;

void LongLong::SetNum(string num)
{				
	if ((atoll(num.c_str()) >= 0) && ((atoll(num.c_str()) <= 0xFFFFFFFFLL)))
	{
		high = static_cast<int32_t> (((atoll(num.c_str())) & 0xFFFFFFFF00000000LL) >> 32);
		low = static_cast<uint32_t>((atoll(num.c_str())) & 0xFFFFFFFFLL);
	}
	else
	{
		high = 0xFFFFFFFFFLL;
		low = -1*(atoll(num.c_str()));
	}
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
	long long n;
	if (high == -4294967295)
	{
		n = -1 * low;
		std::cout << "���" << endl;
	}
	else
	{
		n = (static_cast<long long>(high) << 32) | low;
		std::cout << "���" << endl;
	}
	std::cout << n << "\n";
}

////////////////////////

bool LongLong::Equality(class LongLong a, class LongLong b) 				//���������
{
	bool ok = (a.high == b.high) && (a.low == b.low);
	if (ok)
	{
		std::cout << "����� �����" << "\n";
		return true;
	}
	else
	{
		if (a.high > b.high)
		{
			std::cout << "������ ����� ������" << endl;
			return true;
		}
		else
		{
			if (a.high < b.high)
			{
				std::cout << "������ ����� ������" << endl;
				return false;
			}
			else
				if (a.low > b.low)
				{
					std::cout << "������ ����� ������" << endl;
					return true;
				}
				else
					std::cout << "������ ����� ������" << endl;
			return false;
		}
	}
	}

void LongLong::Multiplication(class LongLong a, class LongLong b)					//������������
{
	long long overflow;

	overflow = a.low * b.low;
	high = static_cast<int32_t>((overflow & 0xFFFFFFFF00000000LL) >> 32);			//������� � �������
	low = static_cast<uint32_t>(overflow & 0xFFFFFFFFLL);
	
	high += (a.high * b.low) & 0xFFFFFFFFLL;										//�������� � ������� �������
														
	high = (a.low * b.high) & 0xFFFFFFFFLL;											//������� � ������� �������

	high += (a.high * b.high) << 32;												// ������� � �������
}

void LongLong::Division(class LongLong a, class LongLong b)							//�������
{

}

void LongLong::Addition(class LongLong a, class LongLong b)							//�����
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

void LongLong::Subtraction(class LongLong a, class LongLong b)			//��������
{
	//high = a.high - b.high;
	if (a.low < b.low)
	{
		
		low = a.low << 32 - b.low;
		a.high >> 32;
	}
	else
	{
		low = a.low - b.low;
	}
	if (a.high < b.high)
	{

		high = a.high << 32 - b.high;
	}
	else
	{
		high = a.high - b.high;
	}
}