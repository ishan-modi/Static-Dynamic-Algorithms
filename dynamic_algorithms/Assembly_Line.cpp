#include<iostream>

using namespace std;

void printstations(int l1[],int l2[],int f,int l,int n);
void Assembly_Line(int f1[],int f2[],int a1[],int a2[],int t1[],int t2[],int e1,int e2,int x1,int x2,int n);

int main()
{
	int i,j,e1,e2,x1,x2,n;
	cout<<"Enter the Number of Stations:- ";
	cin>>n;
	int f1[n+1], f2[n+1], a1[n+1], a2[n+1], t1[n+1], t2[n+1];
	cout<<"Enter entry time for Line 1:- ";
	cin>>e1;
	cout<<"Enter exit time for Line 1:- ";
	cin>>x1; 
	cout<<"Enter entry time for Line 2:- ";
	cin>>e2;
	cout<<"Enter exit time for Line 2:- ";
	cin>>x2;
	for(i=1;i<=2;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<"Enter time for Station("<<i<<","<<j<<"):- ";
			if(i==1)
				cin>>a1[j];
			else
				cin>>a2[j];
		}
	}
	for(i=1;i<n;i++)
	{
		cout<<"Enter time for Station(1,"<<i<<") to Station(2,"<<i+1<<"):- ";
		cin>>t1[i];
	}	
	for(i=1;i<n;i++)
	{
		cout<<"Enter time for Station(2,"<<i<<") to Station(1,"<<i+1<<"):- ";
		cin>>t2[i];
	}	
	Assembly_Line(f1,f2,a1,a2,t1,t2,e1,e2,x1,x2,n);
}

void printstations(int l1[],int l2[],int f,int l,int n)
{
	int i=l;
	cout<<"\nSolution is:-\n";
	cout<<"Line "<<l<<", Station "<<n<<endl;
	for(int j=n;j>=2;j--)
	{
		if(i==1)
			i=l1[j];
		else
			i=l2[j];
		cout<<"Line "<<i<<", "<<" Station "<<j-1<<endl;
	}
	cout<<"\nTotal Time is:- "<<f<<endl;
}

void Assembly_Line(int f1[],int f2[],int a1[],int a2[],int t1[],int t2[],int e1,int e2,int x1,int x2,int n)
{
	int j,f,l,l1[n],l2[n];
	f1[1]=e1+a1[1];
	f2[1]=e2+a2[1];
	for(j=2;j<=n;j++)
	 {
		if(f1[j-1]+a1[j]<=f2[j-1]+t2[j-1]+a1[j])
		 {
			f1[j]=f1[j-1]+a1[j];
			l1[j]=1;
		 }
		else
		 {
			f1[j]=f2[j-1]+t2[j-1]+a1[j];
			l1[j]=2;
		 }
		if(f2[j-1]+a2[j]<=f1[j-1]+t1[j-1]+a2[j])
		 {
			f2[j]=f2[j-1]+a2[j];
			l2[j]=2;
		 }
		else
		 {	
			f2[j]=f1[j-1]+t1[j-1]+a2[j];
			l2[j]=1;
		 }
	 }
	if(f1[n]+x1<=f2[n]+x2)
	{
		f=f1[n]+x1;
		l=1;
	}
	else
	{
		f=f2[n]+x2;
		l=2;
	}
	printstations(l1,l2,f,l,n);
}

