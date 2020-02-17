#include<iostream>
#include<stdlib.h>
#include<cstdlib>

using namespace std;

void makingchange(int N,int d[],int amount);

int main()
{
 int amount,N;
 cout<<"Enter amount :"<<endl;
 cin>>amount;
 cout<<"Enter no. of denominations :"<<endl;
 cin>>N;
 int d[N];
 for(int i=0;i<N;i++)
	cin>>d[i];

 makingchange(N,d,amount);
}

void makingchange(int N,int d[],int amount)
{
 int matrix[N][amount+1];
 int i,j;

 for(i=0;i<N;i++)
	matrix[i][0]=0;

 for(i=0;i<N;i++)
 {
	for(j=1;j<=amount;j++)
 	{
		if(i==0 && j<d[i])
			matrix[i][j]=rand()%RAND_MAX;
		else if(i==0)
			matrix[i][j]=1+matrix[0][j-d[0]];
		else if(j<d[i])
			matrix[i][j]=matrix[i-1][j];
		else
			matrix[i][j]=min(matrix[i-1][j],1+matrix[i][j-d[i]]);	
	}
 }
for(int i=0;i<N;i++)
 {
	for(int j=0;j<=amount;j++)
	{
		cout<<matrix[i][j]<<" ";
	}
 cout<<endl;
}

 cout<<matrix[N-1][amount]<<endl;
}

int min(int a,int b)
{
 return((a>b) ?b :a);
}
