#pragma once
#include <string.h>
#include <iostream>
using namespace std;

template <typename T>
class dynamic
{
	T *mas;
	int size;
	int maxs;
public:
	dynamic<T>();
	~dynamic<T>();

	void print();			//вывод на экран содержимого массива
	void push_tail(T);		//добавление в конец
	void push_head(T);		//добавление в начало
	void delete_tail();		//удаление последнего эл.
	void delete_head();		//удаление первого эл.
	bool empty();
	int get_size();
	void clear();			//очистка массива
};

template <typename T>
dynamic<T>::dynamic()
{
	size = 0;
	maxs = 100;
	mas = new T[maxs];
}

template <typename T>
dynamic<T>::~dynamic()
{
}

template <typename T>
void dynamic<T>::print()
{
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << "\n";
	}
	cout << endl;
}

template <typename T>
void dynamic<T>::push_tail(T value)
{
	if (maxs == size)
	{
		T *buf = new T[maxs*2];
		this->size = this->size++;
		for (int i = 0; i < this->size - 1; i++)
			buf[i] = this->mas[i];
		buf[this->size - 1] = value;
		delete[] mas;
		mas = buf;
	}
	else
	{
		this->size = this->size++;
		mas[this->size - 1] = value;
	}
}

template <typename T>
void dynamic<T>::push_head(T value)
{
	if (maxs == size)
	{
		this->size = this->size++;
		T *buf = new T[maxs*2];
		buf[0] = value;
		for (int i = 0; i < this->size - 1; i++)
		{
			buf[i + 1] = this->mas[i];
		}
		delete[]mas;
		mas = buf;
	}
	else
	{
		this->size = this->size++;
		for (int i = size - 1; i >= 0; i--)
		{
			mas[i + 1] = this->mas[i];
		}
		mas[0] = value;
	}
}

template <typename T>
void dynamic<T>::delete_tail()
{
	if (size * 2 <= maxs)
	{
		this->size = this->size--;
		int new_s = static_cast<int>(maxs / 2);
		T *buf = new T[new_s];
		for (int i = 0; i < this->size; i++)
		{
			buf[i] = this->mas[i];
		}
		delete[] mas;
		mas = buf;
	}
	else
	{
		this->size = this->size--;
		for (int i = 0; i < this->size; i++)
		{
			mas[i] = this->mas[i];
		}
	}
}

template <typename T>
void dynamic<T>::delete_head()
{
	if (size * 2 <= maxs)
	{
		this->size = this->size--;
		int new_s = static_cast<int>(maxs / 2);
		T *buf = new T[new_s];
		for (int i = 0; i < this->size; i++)
		{
			buf[i] = this->mas[i + 1];
		}
		delete[]mas;
		mas = buf;
	}
	else
	{
		this->size = this->size--;
		for (int i = 0; i < this->size; i++)
		{
			mas[i] = this->mas[i + 1];
		}
	}
}

template <typename T>
bool dynamic<T>::empty()
{
	if (size == 0)
	{
		return true;
	}
	return false;
}

template <typename T>
int dynamic<T>::get_size()
{
	return size;
}

template <typename T>
void dynamic<T>::clear()
{
	delete[] mas;
}
