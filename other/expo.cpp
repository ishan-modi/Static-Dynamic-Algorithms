#include<iostream>

using namespace std;

int Nexpo(int x,int n);
int Dexpo(int x,int n);

int main()
{
 int x,n,ans;
 cout<<"Enter base number and power :"<<endl;
 cin>>x>>n;
 ans=Nexpo(x,n);
 cout<<"Ans "<<ans<<endl;
 
 ans=Dexpo(x,n);
 cout<<"Ans "<<ans<<endl;
}

int Nexpo(int x,int n)
{
 int i=n,r=1;
 while(i>0)
 {
	if(i%2!=0)
		r=r*x;
	x=x*x;
	i=i/2;
 }
 return r;
}

int Dexpo(int x,int n)
{
 if(n==0)
	return 1;
 int r=Dexpo(x,(n/2));
 if((n%2)==0)
	return r*r;
 else
	return x*r*r;
}
