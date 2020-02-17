#include<iostream>

#define N 100

using namespace std;

int itterbinarysearch(int arr[],int val);
int reccbinarysearch(int arr[],int val,int low,int high);

int main()
{
 int arr[N],val,i;
 for(int i=1;i<N+1;i++)
	arr[i]=i;
 cout<<"Enter value to be searched"<<endl;
 cin>>val;
 i=itterbinarysearch(arr,val);
 if(i!=0)
 	cout<<"Value is : "<<val<<endl<<"Index is : "<<i<<endl;
 
 cout<<endl;
 
 i=reccbinarysearch(arr,val,1,N);
 if(i!=0)
 	cout<<"Value is : "<<val<<endl<<"Index is : "<<i<<endl;
 
}

int itterbinarysearch(int arr[],int val)
{
 int low=1,high=N,mid;
 while(high>=low)
  {
	mid=(high+low)/2;
	if(val==arr[mid])
		return mid;
	else if(val<arr[mid])
		high=mid-1;
	else
		low=mid+1;
  }
 cout<<"Element not found"<<endl;
 return 0;
}

int reccbinarysearch(int arr[],int val,int low,int high)
{
 int mid=(high+low)/2;
 if(high<low)
  {
	cout<<"Element not found"<<endl;
	return 0;
  }
 if(val==arr[mid])
	return mid;
 else if(val<arr[mid])
 	reccbinarysearch(arr,val,1,mid-1);
 else
	reccbinarysearch(arr,val,mid+1,N);
}

