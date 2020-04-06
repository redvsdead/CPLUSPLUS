#pragma once
#include <cstring>
#include <iostream>

using namespace std;

class LongLong
{
public:
	int32_t high;
	uint32_t low;



	////////////////// ���������������
	void SetNum(string num);	//������ ��� �������/������� ������
	int32_t GetHigh();
	uint32_t GetLow();
	void SetHigh(int32_t n);
	void SetLow(uint32_t n);
	void Print();				//������ �� �����

	////////////////// �������������� ��������
	bool Equality(class LongLong a, class LongLong b);				//���������
	void Multiplication(class LongLong a, class LongLong b);		//������������
	void Division(class LongLong a, class LongLong b);				//�������
	void Addition(class LongLong a, class LongLong b);				//�����
	void Subtraction(class LongLong a, class LongLong b);			//��������
};

