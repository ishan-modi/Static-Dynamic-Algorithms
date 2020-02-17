#include<iostream>

using namespace std;

void insertionsort(int profit[],int job[],int deadline[],int n);
int max_deadline(int deadline[],int n);
void job_scheduling(int profit[],int job[],int deadline[],int n,int maxd);


int main()
{
 int n,maxd;
 cout<<"Enter no of jobs";
 cin>>n;
 int job[n],profit[n],deadline[n];
 cout<<"Enter the profit and corresponding deadline\n";
 for(int i=0;i<n;i++)
  {
	job[i]=i+1;	/* job number starts from 1 to n */
	cin>>profit[i];
	cin>>deadline[i];
  }
 maxd=max_deadline(deadline,n);
 insertionsort(profit,job,deadline,n);
 job_scheduling(profit,job,deadline,n,maxd);
 return 0;
}

int max_deadline(int deadline[],int n)
{
 int temp=0;
 for(int i=0;i<n;i++)
 {
	 if(deadline[i]>temp)
		temp=deadline[i];	
 }
 return temp;
}

void insertionsort(int profit[],int job[],int deadline[],int n)
{
 int key1,key2,key3;
 int i,j;
 for(i=1;i<n;i++)
  {
	 key1=profit[i];
	 key2=job[i];
	 key3=deadline[i];
	 for(j=i-1;j>=0;j--)
 	  {
		 if(key1>profit[j])
		  {
			 profit[j+1]=profit[j];
			 job[j+1]=job[j];
			 deadline[j+1]=deadline[j];
			 
		  }
		 else 
 		  	break;
	  }
	 profit[j+1]=key1;
	 job[j+1]=key2;
	 deadline[j+1]=key3;
  }
}


void job_scheduling(int profit[],int job[],int deadline[],int n,int maxd)
{
 int i,total_profit=0,temp;
 int sol[maxd];
 for(i=1;i<=maxd;i++)
	sol[i]=-1;
 i=0;
 while(i<n)
  {
 	if(sol[deadline[i]]==-1)
  	 {
		sol[deadline[i]]=job[i];
		total_profit+=profit[i];

		i++;
  	 }
 	else
 	 {
		temp=deadline[i];
		while(sol[temp]!=-1&&temp>=0)
		 	temp-=1;
		if(sol[temp]==-1)
		 {
			sol[temp]=job[i];
			total_profit+=profit[i];
		 }
		i++;
 	 }
  }
 for(i=1;i<=maxd;i++)
  {
	if(sol[i]!=-1)
		cout<<endl<<"deadline :"<<i<<"   "<<"job number :"<<sol[i];
  }
 cout<<endl<<"profit :"<<total_profit<<endl;
}
