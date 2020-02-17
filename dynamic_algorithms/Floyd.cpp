#include<iostream>

using namespace std;

#define N 3

void Floyd(int D[][N+1], int P[][N+1]);
void Path(int P[][N+1], int q, int r);

int main()
{
	int i,j,k;
	int D[N+1][N+1], P[N+1][N+1];
	cout<<"Enter the Weight Matrix(999 for Infinity):-\n";
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			cout<<"Enter Path from "<<i<<" to "<<j<<":- ";
			cin>>D[i][j];			
			P[i][j]=0;
		}
	}
	Floyd(D,P);	
	cout<<"\nPaths are:-\n";
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			if(i!=j)
			{
				if(D[i][j]<999)
				{
					cout<<i<<"-->";
					Path(P,i,j);
					cout<<j<<endl;			
				}
			}
		}
	}
}

void Floyd(int D[][N+1], int P[][N+1])
{
	int i,j,k;
	for(k=1;k<=N;k++)
	{
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=N;j++)
			{
				if(D[i][j]>D[i][k]+D[k][j])
				{
					D[i][j]=D[i][k]+D[k][j];
					P[i][j]=k;
				}
				else
					D[i][j]=D[i][j];
			}
		}
	}
}

void Path(int P[][N+1], int q, int r)
{
	if(P[q][r]!=0)
	{
		Path(P,q,P[q][r]);
		cout<<P[q][r]<<"-->";
		Path(P,P[q][r],r);
		return;
	}
	else
		return;
}

