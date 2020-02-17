#include<iostream>

using namespace std;

#define N 2
	
void inputmatrix(int A[N][N]);
void displaymatrix(int A[N][N]);
void naivemul(int A[N][N],int B[N][N],int result[N][N]);

int main()
{
 int A[N][N],B[N][N],result[N][N];
 inputmatrix(A); 
 inputmatrix(B);
 naivemul(A,B,result);
 displaymatrix(result);
}

void inputmatrix(int A[N][N])
{
 cout<<"Enter matrix"<<endl;
 for(int i=0;i<N;i++)
 {
	for(int j=0;j<N;j++)
	{
		cin>>A[i][j];
	}
 }
}

void displaymatrix(int A[N][N])
{
 for(int i=0;i<N;i++)
 {
	for(int j=0;j<N;j++)
	{
		cout<<A[i][j]<<" ";
	}
 cout<<endl;
 }
}


void naivemul(int A[N][N],int B[N][N],int result[N][N])
{
for(int k=0;k<N;k++)
 {
	for(int i=0;i<N;i++)
	 {
	 result[k][i]=0;
		for(int j=0;j<N;j++)
		{	
			result[k][i]+=A[k][j]*B[j][i];
		}
	 }
 }
}
