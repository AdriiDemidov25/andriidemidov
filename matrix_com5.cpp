#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#define size 5
//9 24 -2 86 -3
//40 49 -4 -3 0
//27 -76 77 -1 69
//71 -89 -94 -51 50
//2 96 42 36 -1

using namespace std;
class Matrix{
private:
   int value[5][5];
   string log = "result";
public:
   void InputMatrix();
   void OutputMatrix();
   void Sort();
   void Srgeom();
   void OutputSrgeom();
};

void Matrix::InputMatrix(){
   int i,m;
   for (i=0;i<size;i++){
       for (m=0;m<size;m++){
           cout<<"Enter value:";
           cin>>value[i][m];
       }
   }
}
void Matrix::Sort() {
   int k =0;
   for (int j = 0; j<size; j++) {
       for (int l = 0; l<5; l++) {
           for (int i = 0; i<size-1; i++) {
               if (value[j][i] > value[j][i+1]) {
                   k = value[j][i+1];
                   value[j][i+1] = value[j][i];
                   value[j][i] = k;
               }
           }
       }
   }
}

void Matrix::Srgeom(){
   double srgeom1,srgeom2,srgeom3,srgeom4,sum;
   srgeom1=value[1][0];
   srgeom2=pow(value[2][0]*value[2][1],1.0/2);
   srgeom3=pow(value[3][0]*value[3][1]*value[3][2],1.0/3);
   srgeom4=pow(fabs(value[4][0]*value[4][1]*value[4][2]*value[4][3]), 1.0/4);
   sum=srgeom1+srgeom2+srgeom3+srgeom4;
}

void Matrix::OutputSrgeom(){
   double srgeom1,srgeom2,srgeom3,srgeom4,sum;
   cout<<"srgeom1="<<srgeom1<<endl;
   cout<<"srgeom2="<<srgeom2<<endl;
   cout<<"srgeom3="<<srgeom3<<endl;
   cout<<"srgeom4="<<srgeom4<<endl;
   cout<<endl;
   cout<<"sum="<<sum<<endl;
}

void Matrix::OutputMatrix(){
   for(int i=0;i<size;i++){
       for(int m=0;m<size;m++){
           cout<<value[i][m]<<"\t";
       }
       cout<<endl;
   }
}

int main(void){
   cout << log;
   Matrix matrix;
   matrix.InputMatrix();
   cout << "Input:" << endl;
   matrix.OutputMatrix();
   matrix.Sort();
   cout << "Sorted" << endl;
   matrix.OutputMatrix();
   matrix.Srgeom();
   matrix.OutputSrgeom();
}
