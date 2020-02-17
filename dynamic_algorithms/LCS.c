#include<stdio.h>
#include<stdlib.h>
void input(char X[], int m, int n)
{
	printf("Enter String %d:-\n", n);
	scanf("%s", X);
	for(int i=m;i>0;i--)	
		X[i]=X[i-1];
}
void PRINT_LCS(int i, int j, int n, int b[][n+1], char X[])
{
	if(i==0 || j==0)
		return;
	if(b[i][j]==2)
	{
		PRINT_LCS(i-1, j-1, n, b, X);
		printf("%c", X[i]);
	}
	else if(b[i][j]==1)
		PRINT_LCS(i-1, j, n, b, X);
	else
		PRINT_LCS(i, j-1, n, b, X);			
}
void LCS_LENGTH(char X[], char Y[], int m, int n)
{
	int C[m+1][n+1], b[m+1][n+1];
	int i, j;
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)	
			C[i][j]=b[i][j]=0;
	}
	for(i=1;i<=m;i++)
		C[i][0]=0;
	for(j=0;j<=n;j++)
		C[0][j]=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(X[i]==Y[j])
			{
				C[i][j]=C[i-1][j-1]+1;
				b[i][j]=2;
			}
			else if(C[i-1][j]>=C[i][j-1])
			{
				C[i][j]=C[i-1][j];
				b[i][j]=1;
			}
			else
			{
				C[i][j]=C[i][j-1];
				b[i][j]=3;
			}
		}
	}
	printf("\nLongest Common Subsequence is:- ");
	PRINT_LCS(m, n, n, b, X);
}
void DISPLAY(char X[], int n)
{
	for(int i=1;i<=n;i++)
		printf("%c", X[i]);
	printf("\n");
}
void main()
{
	int i,m,n;
	printf("Enter Length of String 1:-\n");
	scanf("%d", &m);
	printf("Enter Length of String 2:-\n");
	scanf("%d", &n);
	char X[m+1], Y[n+1];
	input(X, m, 1);
	input(Y, n, 2);
	printf("\nString 1 is:- ");
	DISPLAY(X, m);
	printf("String 2 is:- ");
	DISPLAY(Y, n);
	LCS_LENGTH(X, Y, m, n);
	printf("\n");
}
