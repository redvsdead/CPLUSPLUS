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
	
	void SetNum(string num);	//������ ��� �������/������� ������

	void Addition();			//�����
	void Subtraction();			//��������
	void Multiplication();		//������������
	void Division();			//�������
	void Equality();			//���������
	void Print();				//������ �� �����
};