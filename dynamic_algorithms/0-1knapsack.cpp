#include<iostream>

using namespace std;

void knapsack(int W,int n,int arr[][2]);

int main()
{
 int W,n;
 cout<<"Enter maximum weight to be taken"<<endl;
 cin>>W;
 cout<<"Enter total number of items"<<endl;
 cin>>n;
 int arr[n+1][2];
 cout<<"Enter weight and corresponding values for items"<<endl;
 for(int i=1;i<=n;i++)
  {
	cin>>arr[i][0];
	cin>>arr[i][1];
  }
 knapsack(W,n,arr);
}

void knapsack(int W,int n,int arr[][2])
{
 int matrix[n+1][W+1];
 for(int w=0;w<=W;w++)
	matrix[0][w]=0;
 for(int i=1;i<=n;i++)
	matrix[i][0]=0;
 
 for(int i=1;i<=n;i++)
 {
	for(int w=1;w<=W;w++)
	{
		if(arr[i][0]<=w)
		{
			if((arr[i][1]+matrix[i-1][w-arr[i][0]])>matrix[i-1][w])
				matrix[i][w]=arr[i][1]+matrix[i-1][w-arr[i][0]];
			else
				matrix[i][w]=matrix[i-1][w];
		}
		else
			matrix[i][w]=matrix[i-1][w];
	}
 }
 
 cout<<"Solution matrix"<<endl;
 for(int i=0;i<=n;i++)
 {
	for(int j=0;j<=W;j++)
	{
		cout<<matrix[i][j]<<" ";
	}
 cout<<endl;
 }
 cout<<endl<<"Items to be selected"<<endl;

 //BACK-TRACKING
 int N=n;
 int w=W;
 while(w!=0)
 {
	for(int i=N;i>0;i--) 	
 	{
		if(matrix[i][w]!=matrix[i-1][w])
		{
			cout<<"Item "<<i<<endl;
			N=i-1;
			w=w-arr[i][0];
		}	
	}			
 }
}

