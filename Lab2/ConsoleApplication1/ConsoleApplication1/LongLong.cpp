#include "pch.h"
#include "LongLong.h"
#include <ctime>
using namespace std;

void LongLong::SetNum(string num)
{				
	high = (int32_t)(((atoll(num.c_str())) & 0xFFFFFFFF00000000LL) >> 32);
	low = (uint32_t)((atoll(num.c_str())) & 0xFFFFFFFFLL);
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
	long long m;
	m = (static_cast<long long>(high) << 32) | low;
	cout << m << endl;
}

////////////////////////

bool LongLong::Equality(class LongLong a, class LongLong b) 				//���������
{
	bool ok = (a.high == b.high) && (a.low == b.low);
	if (ok)
	{
		cout << "����� �����" << "\n";
		return true;
	}
	else
	{
		if (a.high > b.high)
		{
			cout << "������ ����� ������" << endl;
			return true;
		}
		else
		{
			if (a.high < b.high)
			{
				cout << "������ ����� ������" << endl;
				return false;
			}
			else
				if (a.low > b.low)
				{
					cout << "������ ����� ������" << endl;
					return true;
				}
				else
					cout << "������ ����� ������" << endl;
			return false;
		}
	}
	}

void LongLong::Multiplication(class LongLong a, class LongLong b)						//������������
{
	high = 0;
	int32_t overf = (int32_t)(((static_cast<long long>(a.low) * static_cast<long long>(b.low)) & 0xFFFFFFFF00000000LL) >> 32);
	low = (a.low * b.low) & 0xFFFFFFFFLL;
	high += overf;
	high += a.low * b.high;
	high += a.high * b.low;
	if (a.high > 0 || b.high > 0)
	{
		high += a.high * b.high << 32;
	}
}

void LongLong::Division(class LongLong a, class LongLong b)							//�������
{

}

void LongLong::Addition(class LongLong a, class LongLong b)							//�����
{
	bool overf = 0xFFFFFFFFLL - a.low + 1 <= b.low;
	low = (a.low + b.low) & 0xFFFFFFFFLL;
	high = a.high + b.high;
	if (overf) 
	{
		high++; 
	};
}

void LongLong::Subtraction(class LongLong a, class LongLong b)			//��������
{
	bool overf = a.low < b.low;
	low = a.low - b.low;
	high = a.high - b.high;
	if (overf)
	{
		high--;
	}
}