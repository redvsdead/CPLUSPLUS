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

	printf("������ �������� � ��� ������������ ������ ������ (������� 0) ��� ������� ����� (������� 1)?\n");
	int i;
	scanf_s("%d", &i);
	i = checkanswer(i);
	printf("������� ��� �����\n");
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

	printf("������ �������� � ��� ������������ ������ ������ (������� 0) ��� ������� ����� (������� 1)?\n");
	scanf_s("%d", &i);
	i = checkanswer(i);
	printf("������� ��� �����\n");
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
		printf("������� ������� ����� ������ ��������� �������.\n");
	else
		printf("������� ������� ����� ������ ��� ����� ��������� �������.\n");
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
	printf("������� ���������� �����, ������� �� ������ �������� � ����.\n");
	int n;
	scanf_s("%d", &n);
	while (n < 1)
	{
		printf("���� ������ ��������� ���� �� ���� �����\n");
		scanf_s("%d", &n);
	}
	printf("������� %d �����\n", &n);
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

