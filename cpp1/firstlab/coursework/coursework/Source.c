#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

int checkanswer(int i);
int Min(FILE *f);
int Max(FILE *f);
int newfile(FILE *f);

int main(void)
{
	FILE *f1 = fopen("digits1.txt", "r");
	FILE *f2 = fopen("digits2.txt", "r");
	setlocale(LC_ALL, "Rus");

	printf("Начать работать с уже существующим первым файлом (введите 0) или создать новый (введите 1)?\n");
	int i;
	scanf_s("%d", &i);
	i = checkanswer(i);
	printf("Введите имя файла\n");
	char name1[40];
	scanf_s("%s", name1, sizeof(name1));
	if (i = 0)
	{
		f1 = fopen(name1, "r");
		if (f1 == NULL)
		{
			fclose(f1);
			f1 = fopen(name1, "w+");
			newfile(f1);
		}
	}
	else
	{
		fclose(f1);
		f1 = fopen(name1, "w+");
		newfile(f1);
	}

	printf("Начать работать с уже существующим вторым файлом (введите 0) или создать новый (введите 1)?\n");
	scanf_s("%d", &i);
	i = checkanswer(i);
	printf("Введите имя файла\n");
	char name2[40];
	scanf_s("%s", name2, sizeof(name2));
	if (i = 0)
	{
		f2 = fopen(name2, "r");
		if (f2 == NULL)
		{
			fclose(f2);
			f2 = fopen(name2, "w+");
			newfile(f2);
		}
	}
	else
	{
		fclose(f2);
		f2 = fopen(name2, "w+");
		newfile(f2);
	}

	if (Min(f1) > Max(f2))
		printf("Минимум первого файла больше максимума второго.\n");
	else
		printf("Минимум первого файла меньше или равен максимуму второго.\n");
	fclose(f1);
	fclose(f2);
	_getch();
	return 0;

}

int checkanswer(int i)
{
	while (i != 0 && i != 1)
	{
		printf("\n");
		scanf_s("%d", &i);
	}
	return i;
}

int newfile(FILE *F)
{
	printf("Введите количество чисел, которые Вы хотите записать в файл.\n");
	int n;
	scanf_s("%d", &n);
	while (n < 1)
	{
		printf("Файл должен содержать хотя бы одно число\n");
		scanf_s("%d", &n);
	}
	printf("Введите %d чисел\n", &n);
	int a;
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &a);
		fwrite(&a, sizeof(int), 1, F);
	}
	return 0;
}

int Min(FILE *f)
{
	int i;
	int min = fscanf(f, "%d", &i);
	while (fscanf(f, "%d", &i) != EOF)
	{
		fscanf(f, "%d", &i);
		if (i < min);
		min = i;
	}
	return min;
}

int Max(FILE *f)
{
	int i;
	int max = fscanf(f, "%d", &i);
	while (fscanf(f, "%d", &i) != EOF)
	{
		fscanf(f, "%d", &i);
		if (i < max);
		max = i;
	}
	return max;
}

