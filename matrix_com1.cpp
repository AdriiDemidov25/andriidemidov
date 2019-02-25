#include <iostream>
#include <cstdio>
#include <cstdlib>
#include<math.h>
using namespace std;
const short N = 5;
class Matrix
{
	private:
	double M[N][N];
	double i,j;
	public:
	void InitMatrix();
	void ShowMatrix();
	void Sorting();
	void geom();
};
void Matrix::InitMatrix()
{
	cout<<"give me your matrix: " << endl;
	for (int i = 0; i<N; i++)
		for(int j = 0; j<N; j++)
		{
			cin>>M[i][j];
		}
}
void Matrix::ShowMatrix()
{
		cout << "unsorted matrix :" << endl;
	 for (int i = 0; i<N; i++, cout<< endl)
	 {
			for(int j = 0; j<N; j++)
			{
			 		cout << M[i][j]<<"\t"<< ' ' ;
 		 	}
	 }
	 cout << endl;
}
void Matrix::Sorting()
{
	cout << "sorted matrix : "<< endl;
	for (int k = 0; k < N; k++, cout << endl)
	{
	    for ( int i = 0; i < N; i++)
	    {
		    for (int j = N-1; j > i; j--)
			if(M[k][j]<M[k][j-1])
			{
				int tmp = M[k][j];
				M[k][j]=M[k][j-1];
				M[k][j-1]=tmp;
			}
			cout << M[k][i]<<"\t" << ' ';
		}
	}
	cout << endl;
}
void Matrix::geom(){
		int i,j;
		double sergeom_of_allsym = 1;
    	for(i = 0;  i < (N-1); i++)
		{
			double sumanaddiagonal = 0;
		  for(j = 0;j < N;j++)
		  {
		  	if((i+j)<(4))
			  {
		  		sumanaddiagonal = sumanaddiagonal + M[i][j];
			  }
		  }
		  sergeom_of_allsym = sergeom_of_allsym*sumanaddiagonal;
		  cout<<"Suma="<<sumanaddiagonal<<endl;
		}
		cout<<"Seredne geometruchne="<<pow((sergeom_of_allsym),(1/4.0))<<endl;
}
intmain(void)
{
	Matrix M;
	M.InitMatrix();
	M.ShowMatrix();
	M.Sorting();
	M.geom();

}
