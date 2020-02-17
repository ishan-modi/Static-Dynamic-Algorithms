#include<stdio.h>
#include<stdlib.h>
void Matrix_Chain_Order(int N, int p[N+1], int m[][N+1], int s[][N+1])
{
	int n=N, i, j, k, l, q;
	for(i=1;i<=n;i++)
		m[n-i+1][i]=0;
	for(l=2;l<=n;l++)	
	{
		for(i=1;i<=n-l+1;i++)	
		{
			j=i+l-1;	
			m[n-i+1][j]=RAND_MAX;
			for(k=i;k<=j-1;k++)	
			{
				q=m[n-i+1][k]+m[n-k][j]+(p[i-1]*p[k]*p[j]);
				if(q<m[n-i+1][j])
				{
					m[n-i+1][j]=q;
					s[n-i+1][j]=k;
				}
			}
		}
	}
}
void Print_Opt_Parens(int i, int j, int N, int s[][N+1])
{
	if(i==j)
		printf("A%d", i);
	else
	{
		printf("(");
		Print_Opt_Parens(i, s[N-i+1][j], N, s);
		Print_Opt_Parens(s[N-i+1][j]+1, j, N, s);
		printf(")");
	}
}
void main()
{
	int i,N;
	printf("Enter the number of matrices:- ");
	scanf("%d", &N);
	int p[N+1], m[N+1][N+1], s[N+1][N+1];	
	printf("Enter dimension of matrices:-\n");
	for(i=0;i<=N;i++)
		scanf("%d", &p[i]);
	printf("\n");
	for(i=1;i<=N;i++)
		printf("A%d:- %dX%d\n", i-1, p[i-1], p[i]);
	printf("\n");
	Matrix_Chain_Order(N, p, m, s);
	printf("Order of Matrix Multiplication is:- ");
	Print_Opt_Parens(1, N, N, s);
	printf("\n");
}







