
#include "pch.h"
#include <iostream>
#include <locale.h>
#include <direct.h>
#include <ctime>
#include <fstream>

/*В матрице найти наибольшее количество подряд идущих нулей по горизнтали, вертикали и диагонали*/

using namespace std;

const int maxsize = 100;

void ReadArray(int Arr[][maxsize], int& size)  //читает массив из файла, первая строчка - размерность квадратной матрицы
{
	string path = "matrix.txt";
	ifstream f;
	f.open(path);
	if (!f.is_open())
	{
		std::cout << "Возникла ошибка при чтении файла.\n";
	}
	else
	{
		f >> size;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				f >> Arr[i][j];
			}
		}
	}
	f.close();
}

void PrintArr(int Arr[][maxsize], int size) //выводит прочитанный массив на экран
{
	std::cout << "Ваш массив:\n";
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << Arr[i][j] << " ";
		}
		std::cout << "\n";
	}
}

int CheckRow(int Arr[][maxsize], int size) //последовательность по горизонтали
{
	int count = 0;
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		count = 0;
		for (int j = 0; j < size; j++)
		{
			if (Arr[i][j] == 0)
			{
				count++;
			}
			else
			{
				if (count > max)
				{
					max = count;
				}
				count = 0;
			}
		}
		if (count > max)
		{
			max = count;
		}
	}
	std::cout << "По горизонтали: " << max << "\n";
	return max;
}

int CheckCol(int Arr[][maxsize], int size) //последовательность по вертикали
{
	int count;
	int max = 0;
	for (int j = 0; j < size; j++)
	{
		count = 0;
		for (int i = 0; i < size; i++)
		{
			if (Arr[i][j] == 0)
			{
				count++;
			}
			else
			{
				if (count > max)
				{
					max = count;
				}
				count = 0;
			}
		}
		if (count > max)
		{
			max = count;
		}
	}
	std::cout << "По вертикали: " << max << "\n";
	return max;
}

int CheckDiag1(int Arr[][maxsize], int size)  //считает для прямых диагоналей
{
	int count;
	int max = 0;
	for (int i = 0; i < size; i++)	//под главной диагональю
	{
		count = 0;
		for (int k = 0; k < size - i; k++)
		{
			int j = i;
			while (j <= size)
			{
				if (Arr[j+k][j] == 0)
				{
					count++;
				}
				else
				{
					if (count > max)
					{
						max = count;
					}
					count = 0;
				}
				j++;
			}
		}
		if (count > max)
		{
			max = count;
		}

	}

	for (int i = 0; i < size; i++)	//над главной диагональю
	{
		count = 0;
		for (int k = 0; k < size - i; k++)
		{
			int j = i;
			while (j <= size)
			{
				if (Arr[j - k][j] == 0)
				{
					count++;
				}
				else
				{
					if (count > max)
					{
						max = count;
					}
					count = 0;
				}
				j++;
			}
		}
		if (count > max)
		{
			max = count;
		}

	}
	std::cout << "По прямой диагонали: " << max << "\n";
	return max;
}

int CheckDiag2(int Arr[][maxsize], int size)  //считает для обратных диагоналей
{
	int count;
	int max = 0;
	for (int i = 0; i < size; i++)	//под побочной диагональю
	{
		count = 0;
		for (int k = 0; k < size - i; k++)
		{
			int j = size - i - 1;
			while (j > -1)
			{
				if (Arr[k][j - k] == 0)
				{
					count++;
				}
				else
				{
					if (count > max)
					{
						max = count;
					}
					count = 0;
				}
				j--;
			}
		}
		if (count > max)
		{
			max = count;
		}

	}

	for (int i = 0; i < size; i++)	//над побочной диагональю
	{
		count = 0;
		for (int k = 0; k < size - i; k++)
		{
			int j = size - i - 1;
			while (j > -1)
			{
				if (Arr[k][j + k] == 0)
				{
					count++;
				}
				else
				{
					if (count > max)
					{
						max = count;
					}
					count = 0;
				}
				j--;
			}
		}
		if (count > max)
		{
			max = count;
		}

	}

	std::cout << "По обратной диагонали: " << max << "\n";
	return max;
}

int MainTask(int Arr[][maxsize], int size) //для наглядности выводит максимальные длины последовательностей нулей
{										   //для вертикали, горизонтали и диагоналей, затем находит максимальную из них
	int maxcount = 0;
	int count = CheckRow(Arr, size);
	if (count > maxcount)
	{
		maxcount = count;
	}
	count = CheckCol(Arr, size);
	if (count > maxcount)
	{
		maxcount = count;
	}
	count = CheckDiag1(Arr, size);
	if (count > maxcount)
	{
		maxcount = count;
	}
	count = CheckDiag2(Arr, size);
	if (count > maxcount)
	{
		maxcount = count;
	}
	return maxcount;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int size = 0;
	int Array[maxsize][maxsize];
	ReadArray(Array, size);
	PrintArr(Array, size);
	std::cout << "Наибольшее количество подряд идущих нулей в массиве: " << MainTask(Array, size) << ".\n";
}