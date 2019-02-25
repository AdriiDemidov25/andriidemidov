#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
using namespace std;

class TwoDimensionalArray
{
private:
	vector<vector<double> > a;
	int size;

	double calcAverage(int row)
	{
		double res = 1;
		for (int i = row + 1; i < size; i++)
			res *= a[i][row];
		return pow(res, 1.0 / (size - row - 1));
	}

	void bubbleSort(vector<double>& m)
	{
		for (int j = 0; j < size - 1; j++)
			for (int i = 0; i < size - j - 1; i++)
				if (m[i] < m[i + 1])
					swap(m[i], m[i + 1]);
	}

public:
	TwoDimensionalArray(int size)
	{
		this->size = size;
		a = vector<vector<double> >(size);
		for (int i = 0; i < size; i++)
			a[i] = vector<double>(size);
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
			bubbleSort(a[column]);
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
		for (int i = 0; i < size - 1; i++)
		{
			f = calcAverage(i);
			cout << f << " ";
			F += f;
		}

		cout << endl << F << endl;;
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
