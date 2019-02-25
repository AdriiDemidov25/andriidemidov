#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class TwoDimensionalArray
{
private:
	double** a;
	int size;

	double calcMul(int row)
	{
		double res = 1;
		for (int i = 0; i < row; i++)
			res *= a[i][row];
		return res;
	}

	void selectionSort(double* m)
	{
		int min_i;
		for (int i = 0; i < size; i++)
		{
			min_i = i;
			for (int j = i + 1; j < size; j++)
				if (m[j] < m[min_i])
					min_i = j;

			swap(m[i], m[min_i]);
		}
	}

public:
	TwoDimensionalArray(int size)
	{
		this->size = size;
		a = new double*[size];
		for (int i = 0; i < size; i++)
			a[i] = new double[size];
	}

	void readFromKeyboard()
	{
		for (int i = 0; i < size; i++)
			for (int c = 0; c < size; c++)
				cin >> a[c][i];
	}

	void sortColumns()
	{
		for (int column = 0; column < size; column++)
			selectionSort(a[column]);
	}

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			for (int c = 0; c < size; c++)
				cout << a[c][i] << " ";
			cout << endl;
		}
	}

	void calculateAndPrint_fF()
	{
		double f, F = 1;
		for (int i = 1; i < size; i++)
		{
			f = calcMul(i);
			printf("%.0f ", f);
			F += f;
		}

		printf("\n%.0f\n", F);
	}
};

int main()
{
	int size;
	cin >> size;

	TwoDimensionalArray m(size);
	m.readFromKeyboard();
	m.sortColumns();

	cout << endl << "Sorted matrix: " << endl;
	m.print();

	cout << endl;
	m.calculateAndPrint_fF();
}
