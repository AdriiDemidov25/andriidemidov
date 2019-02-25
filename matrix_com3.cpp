#include <cstdlib>
#include<iostream>
using namespace std;

#define n 5
class matrix
 {
private:
    int a[n][n];
    public:
    matrix();
    void input();
    void output();
    void sort();
    void count();
    void arythmetic();
 };
 matrix::matrix(){

 }
 void matrix::input()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
                //a[i][j]=rand()%10;
            }
        }

    }
 void matrix :: output()
 {
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
 }
 void matrix :: sort()
 {
    for (int k = 0; k < n; k++)
    {
        for(int i = 0;i < n; i++)
        {
            for(int j=k;j<n-1;j++)
            {
                if (a[k][i] < a[j+1][i])
                {
                    int tmp = a[k][i];
                    a[k][i] = a[j+1][i];
                    a[j+1][i] = tmp;
                }
            }
        }
    }
 }
 void matrix::count()
 {
     int m[4];
     m[0]=a[1][4];
     m[1]=a[2][4]*a[2][3];
     m[2]=a[3][4]*a[3][3]*a[3][2];
     m[3]=a[4][4]*a[4][3]*a[4][2]*a[4][1];
     for(int i=0;i<n-1;i++)
     {
         cout<<"Res of multiply of row = "<<m[i]<<endl;
     }
     double a=(double)(m[0]+m[1]+m[2]+m[3])/4;
     cout<<"Mid arythmetic = "<<a<<endl;
 }
 int main()
 {
 matrix m1;
 m1.input();
 cout<<"\nunsorted matrix\n";
 m1.output();
 cout<<"\nsorted matrix\n";
 m1.sort();
 m1.output();
 m1.count();

 return 0;
 }
