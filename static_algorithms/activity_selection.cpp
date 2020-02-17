#include<iostream>

using namespace std;

void insertionsort(int start_end_time[][2],int iniarr[],int n);
void activity_selector(int start_end_time[][2],int iniarr[],int n);

int main()
{
 int n;
 cout<<"Enter number of activities :";
 cin>>n;
 int start_end_time[n][2],iniarr[n];
 for(int i=0;i<n;i++)
	iniarr[i]=i+1; /* activity number starts from 1 to n */
 cout<<"Enter the start time and corresponding end time:";
 for(int i=0;i<n;i++)
  {
	cin>>start_end_time[i][0];
	cin>>start_end_time[i][1];
  }
 insertionsort(start_end_time,iniarr,n);
 activity_selector(start_end_time,iniarr,n);
 return 0;
}

void insertionsort(int start_end_time[][2],int iniarr[],int n)
{
 int key1,key2,key3;
 int i,j;
 for(i=1;i<n;i++)
  {
	 key1=start_end_time[i][0];
	 key2=start_end_time[i][1];
	 key3=iniarr[i];
	 for(j=i-1;j>=0;j--)
 	  {
		 if(key2<start_end_time[j][1])
		  {
			 start_end_time[j+1][1]=start_end_time[j][1];
			 start_end_time[j+1][0]=start_end_time[j][0];
			 iniarr[j+1]=iniarr[j];
		  }
		 else 
 		  	break;
	  }
	 start_end_time[j+1][1]=key2;
	 start_end_time[j+1][0]=key1;
	 iniarr[j+1]=key3;
  }
}

void activity_selector(int start_end_time[][2],int iniarr[],int n)
{
 int i=0,j=1;
 cout<<endl<<"activity :"<<iniarr[i]<<endl;
 while(j<n)
  {
	if(start_end_time[i][1]<=start_end_time[j][0])
	 {
		cout<<"activity :"<<iniarr[j]<<endl;
		i=j++;		
 	 }
	else
		j++;
  }
}
