#include<iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#define n 5
using namespace std;

class Matrix
{
private:
double M[n][n];
public:
void InputMatrix();
void OutputMatrix();
void Sort();
void Add();
};

void Matrix::InputMatrix()
{
for (int i=0;i<n;i++)
for (int j=0;j<n;j++)
{
cout<<"a["<<i+1<<"]["<<j+1<<"] = ";
cin>>M[i][j];
}
}

void Matrix::OutputMatrix()
{
for (int i=0;i<n;i++)
{
for (int j=0;j<n;j++)
cout<<"\t"<<M[i][j];
cout<<endl;
}
cout<<endl;
}

void Matrix::Sort()
{
int key = 0, j = 0, m = n, i,k;
for (k = 0; k < m; k++)
for (i = 1; i < m; i++)
{
key = M[k][i];
j = i - 1;
while (j >= 0 && M[k][j] < key)
{
M[k][j + 1] = M[k][j];
j--;
}
M[k][j + 1] = key;
}
}

void Matrix::Add()
{
int d[n],i,j;
for ( i = 0 ; i < n; i++)
d[i]=1;

for ( j = 0; j < n; j++)
{
for (i = 0 ; i < n; i++)
{
d[j]=d[j]*M[i][j];
}
}

cout <<"\n\nProduct of each column:\n";
for (i = 0 ; i < n; i++)
cout <<"\t"<<d[i];

double s=0;
for (i = 0 ; i < n; i++)
s=s+d[i];
s=s/n;

cout<<"\n\nMiddle arifmetric:\n";
cout<<"\t"<<fixed << s << endl<< endl;
}

int main()
{
Matrix a;
cout<<"Enter elements:\n";
a.InputMatrix();
cout<<"\nOld array:\n";
a.OutputMatrix();
a.Sort();
cout<<"New array:\n";
a.OutputMatrix();
a.Add();
system("pause");
}
