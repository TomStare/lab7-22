
#include <iostream>

using namespace std;

void mas_add_numbers(int mas[100][100], int lines, int columns)
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> mas[i][j];
		}
	}
}

void mas_add_numbers(int mas[100][100], int lines, int columns, int num)
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			mas[i][j] = num;
		}
	}
}

bool giagonal_check(int mas[100][100], int lines, int columns)
{
	if (lines > columns) lines = columns;
	bool test_result = true;
	int i = 0, num1 = 0, num2 = 0, ch_1 = 0, ch_2 = 0;
	while (test_result && i < lines)
	{
		num1 = mas[i][i];
		num2 = mas[lines - i - 1][lines - i - 1];
		if (num1 <= 0 || num2 <= 0)
		{
			test_result = false;
		}
		while (num1 > 0)
		{
			if (num1 % 10 == 3) ch_1++; else if (num1 % 10 == 5) ch_2++;
			num1 /= 10;
		}
		if (ch_1 == 0 && ch_2 == 0) test_result = false;
		ch_1 = 0;
		ch_2 = 0;
		while (num2 > 0)
		{
			if (num2 % 10 == 3) ch_1++; else if (num2 % 10 == 5) ch_2++;
			num2 /= 10;
		}
		ch_1 = 0;
		ch_2 = 0;
		i++;
	}
	return(test_result);
}

void work_mas(int mas[100][100], int lines, int columns)
{
	int min, sum = 0;
	for (int i = 0; i < columns; i++)
	{
		min = mas[0][i];
		for (int j = 0; j < lines; j++)
		{
			sum += pow(mas[j][i], 2);
			if (mas[j][i] > min) min = mas[j][i];
		}
		for (int j = 0; j < lines; j++)
		{
			if (mas[j][i] == min) mas[j][i] = min;
		}
		sum = 0;
	}
}

void output_mas(int mas[100][100], int lines, int columns)
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << mas[i][j] << "\t";
		}
		cout << "\n";
	}
}


void dsf(int x)
{
	x += 5;
	cout << x << "\n";
}

void dsfx(int &x)
{
	x += 5;
	cout << x << "\n";
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int x = 5;
	cout << x << "\n";
	dsf(x);
	cout << x << "\n";
	dsfx(x);
	cout << x << "\n";

	/*
	int n, m;
	int mas[100][100];
	cout << "Введите размер матрицы \n";
	cin >> n >> m;
	mas_add_numbers(mas, n, m);
	if (giagonal_check(mas, n, m)) work_mas(mas, n, m);
	output_mas(mas, n, m);
	*/
	return(0);
}