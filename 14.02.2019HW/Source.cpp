#include<iostream>
#include<iomanip>
#include<locale.h>
#include<Windows.h>

using namespace std;


template<typename T>
void PrintArray(T a[], int n);

template<typename T>
void FillArray(T a[], int n);

template<typename T>
int MaxNumber(T a[], int n, T &Max);

template<typename T>
void Zero(T a[], int n, int B[], int b);

template<typename T>
int XY(T x, int y)
{
	T num = 1;
	for (size_t i = 0; i < y; i++)
	{
		num = num * x;
	}
	return num;
}

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	const int n = 10;
	int a[n], b[n];
	int Max = 0;
	int flag, task;
	int x, y;
	do
	{
		cout << "Task Number";
		cin >> task;

		switch (task)
		{
		case 1:
			Max = 0;
			FillArray(a, n);
			PrintArray(a, n);
			cout << endl;

			cout << MaxNumber(a, n, Max) << endl;
			cout << Max << endl;
			break;
		case 2:
			FillArray(a, n);
			PrintArray(a, n);
			Zero(a, n, b, 0);
			break;
		case 3:
			cin >> x >> y;
			cout << XY(x,y) << endl;
		}

		cout << "Continue?1/0";
		cin >> flag;

	} while (flag == 1);

}

template<typename T>
void Zero(T a[], int n, int B[], int b)
{
	for (size_t i = 0; i < n; i++)
	{
		B[i] = -1;
	}

	for (size_t i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			B[b] = i;
			b++;
		}

	}
	for (size_t i = 0; i < n; i++)
	{
		if (B[i] >= 0)
		{
			cout << B[i] << " ";
		}

	}
}

template<typename T>
void PrintArray(T a[], int n)
{

	for (size_t i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

template<typename T>
void FillArray(T a[], int n)
{

	for (size_t i = 0; i < n; i++)
	{
		a[i] = 0 + rand() % 5;
	}

}

template<typename T>
int MaxNumber(T a[], int n, T &Max)
{
	int MaxPosition = 0;
	Max = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (Max < a[i])
		{
			MaxPosition = i;
			Max = a[i];

		}
	}

	return(MaxPosition);
}