#include<iostream>

using namespace std;

void setdata(int heap[]);
void max_heapify(int heap[],int i);
void build_max_heap(int heap[]);
void display(int heap[],int temp);
void heap_sort(int heap[]);
int left(int i);
int right(int i);

int n;

int main()
{
 int temp;
 cout<<"Enter the size of heap"<<endl;
 cin>>n;
 temp=n;
 int heap[n+1];
 setdata(heap);
 heap_sort(heap);
 cout<<"sorted heap is \n";
 display(heap,temp);
} 

void heap_sort(int heap[])
{
 build_max_heap(heap);
 for(int i=n;i>=2;i--)
  {
	swap(heap[1],heap[i]);
	n-=1;
	max_heapify(heap,1);
  }
}

int left(int i)
{
  return(2*i);
}

int right(int i)
{
 return((2*i)+1);
}

void display(int heap[],int temp)
{
 for(int i=1;i<=temp;i++)
	cout<<heap[i]<<endl;
}

void build_max_heap(int heap[])
{
 for(int i=n/2;i>=1;i--) 
	max_heapify(heap,i);
}

void setdata(int heap[])
{
 cout<<"Enter elements of the heap"<<endl;
 for(int i=1;i<=n;i++)  /* index of heap starts with 1 */
 	cin>>heap[i];
}

void max_heapify(int heap[],int i)
{
 int l,r,max_val;
 l=left(i);
 r=right(i);
 if(l<=n && heap[l]>heap[i])
 	max_val=l;
 else
	max_val=i;
 if(r<=n && heap[r]>heap[max_val])
	max_val=r;
 if(max_val!=i)
  {
 	swap(heap[i],heap[max_val]);
	max_heapify(heap,max_val);  
  }
}

void swap(int *x,int *y)
{
 int *temp;
 *x=*temp;
 *x=*y;
 *y=*temp;
}
