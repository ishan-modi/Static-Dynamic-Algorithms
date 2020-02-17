#include<iostream>
#include<stdlib.h>
#include<time.h>

#define N 10

int count=0;

void mergesort(int arr[],int low,int high);
void merge(int arr[],int low,int mid,int high);
void copy(int arr1[],int arr2[]);
void quicksort(int arr[],int low,int high);
int partition(int arr[],int low,int high);
void display(int arr[]);
void reversearr(int arr[]);

using namespace std;

int main()
{
 int cnt1,cnt2,cnt3;
 clock_t start,end;
 double total,sum1,sum2,sum3; 
 
 sum1=sum2=sum3=0; 

 int arr[N],arr1[N],arr2[N],temp[N]; 
 for(int i=0;i<N;i++)
	arr[i]=rand();
 
 copy(arr,arr1);
 copy(arr,arr2); 
 display(arr);

for(int i=0;i<100;i++)
  {
	count=0;
	start=clock();
	mergesort(arr,0,N-1);
	end=clock();	
	cnt1=count;
  	total=((double)end-start)*1000/CLOCKS_PER_SEC;
	sum1 += total;

	count=0;
	start=clock();
	mergesort(arr,0,N-1);
	end=clock();	
	cnt2=count;	
	total=((double)end-start)*1000/CLOCKS_PER_SEC;
	sum2 += total;

	count=0;
	reversearr(arr1);
	start=clock();
	mergesort(arr,0,N-1);
	end=clock();	
	cnt3=count;	
	total=((double)end-start)*1000/CLOCKS_PER_SEC;
	sum3 += total;
	
	copy(arr,arr1);
  }
 cout<<"time(average case) is : "<<sum1/100<<endl<<"swaps(average case) is : "<<cnt1<<endl;
 cout<<"time(best case) is : "<<sum2/100<<endl<<"swaps(best case) is : "<<cnt2<<endl;
 cout<<"time(worst case) is : "<<sum3/100<<endl<<"swaps(worst case) is : "<<cnt3<<endl;

 cout<<endl;

 for(int i=0;i<100;i++)
  {
	count=0;
	start=clock();
	quicksort(arr,0,N-1);
	end=clock();	
	cnt1=count;	
	total=((double)end-start)*1000/CLOCKS_PER_SEC;
	sum1 +=total;
	
	count=0;
	start=clock();
	quicksort(arr,0,N-1);
	end=clock();	
	cnt2=count;	
	total=((double)end-start)*1000/CLOCKS_PER_SEC;
	sum2 += total;

	count=0;
	reversearr(arr2);
	start=clock();
	quicksort(arr,0,N-1);
	end=clock();	
	cnt3=count;	
	total=((double)end-start)*1000/CLOCKS_PER_SEC;
	sum3 += total;
	
	
	copy(arr,arr2);
  }
 cout<<"time(average case) is : "<<sum1/100<<endl<<"swaps(average case) is : "<<cnt1<<endl;
 cout<<"time(best case) is : "<<sum2/100<<endl<<"swaps(best case) is : "<<cnt2<<endl;
 cout<<"time(worst case) is : "<<sum3/100<<endl<<"swaps(worst case) is : "<<cnt3<<endl;
}


void mergesort(int arr[],int low,int high)
{
 int mid=(high+low)/2;
 
 if(high>low)
  {
	 mergesort(arr,low,mid);
	 mergesort(arr,mid+1,high);
	 merge(arr,low,mid,high);
  }
}

void merge(int arr[],int low,int mid,int high)
{
 int n1=mid-low+1,n2=high-mid;
 int L[n1+1],R[n2+1],i,j;
  
 for(i=0;i<n1;i++)
	L[i]=arr[low+i];
 
 for(j=0;j<n2;j++)
	R[j]=arr[mid+j+1];
 
 L[n1]=RAND_MAX;
 R[n2]=RAND_MAX;

 i=0;
 j=0;

 for(int k=low;k<=high;k++)
 {
 	if(L[i]<=R[j])
 	{
 		arr[k]=L[i++];
 		count++;
 	}
 	else
 	{
 		arr[k]=R[j++];
 		count++;
 	}	
 }
} 
 
void quicksort(int arr[],int low,int high)
{
 if(low<high)
  {
	int q=partition(arr,low,high);
	quicksort(arr,low,q-1);
	quicksort(arr,q+1,high);
  }
}

int partition(int arr[],int low,int high)
{
 int pivot=arr[high];
 int i=low-1;
 for(int j=low;j<high;j++)
 {
	if(arr[j]<=pivot)
	{
		i++;
		swap(arr[i],arr[j]);
		count++;
	}
 } 
 swap(arr[i+1],arr[high]);
 count++;
 return i+1;
}

void swap(int *x,int *y)
{
 int *temp;
 (*temp)=(*x);
 (*x)=(*y);
 (*y)=(*temp);
}

void copy(int arr1[],int arr2[])
{
 for(int i=0;i<N;i++)
	arr2[i]=arr1[i];
}

void display(int arr[])
{
 for(int i=0;i<N;i++)
 	cout<<arr[i]<<endl;
} 
 
void reversearr(int arr[])
{
 int arr1[N],j=0;
 copy(arr,arr1);
 
 for(int i=N-1;i>=0;i--)
  {
	arr[i]=arr1[j];
	j++;
  }
}
