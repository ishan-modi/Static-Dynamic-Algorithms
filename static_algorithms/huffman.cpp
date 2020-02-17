#include<iostream>
#include<string>

#define N 50

using namespace std;

int n;
int total_bits=0;
struct treenode *root;

void setdata(string str,char carr[],int freq[],struct treenode *heap[]);
void swap(struct treenode *heap[],int i,int val);
int left(int i);
int right(int i);
void heap_sort(struct treenode *heap[]);
void display(struct treenode *heap[]);
void displaytree(struct treenode *heap);
void findheight(struct treenode *heap);
int height(struct treenode *heap,struct treenode *node,int cnt);
int size(struct treenode *heap[]);
void min_heapify(struct treenode *heap[],int i);
void build_min_heap(struct treenode *heap[]);
void huffman(struct treenode *heap[]);


struct treenode
{
 char c;
 int frequency;
 //int binary;
 int bits;
 struct treenode *lptr,*rptr;
};


int main()
{
 struct treenode *heap[N+1];
 int freq[N+1];
 char carr[N+1]={0}; 
 for(int i=1;i<=N;i++)
	heap[i]=new treenode;
 string str="";
 cout<<"Enter the sentence: ";
 getline(cin,str,'\n');
 cout<<"string input is : "<<str<<endl;
 setdata(str,carr,freq,heap);
 heap_sort(heap);
 display(heap);
 huffman(heap); 
}

void huffman(struct treenode *heap[])
{
 n=size(heap);
 for(int i=n;i>1;i--)
  {
	struct treenode *newnode1,*newnode2;
	newnode1=new treenode;
	newnode2=new treenode;
	newnode2->frequency=heap[i]->frequency;
 	newnode2->c=heap[i]->c;
	newnode2->lptr=heap[i]->lptr;
	newnode2->rptr=heap[i]->rptr;
	newnode1->frequency=heap[i]->frequency+heap[i-1]->frequency;
	newnode1->c='*';
	newnode1->lptr=heap[i-1];
	newnode1->rptr=newnode2;
	heap[i-1]=newnode1;
	delete(heap[i]);
	heap_sort(heap);
  }
 root=heap[1];
 cout<<"huffman tree : "<<endl;
 displaytree(heap[1]);
 cout<<"character and corresponding bits required : "<<endl;
 findheight(heap[1]);
 cout<<"total bits required : "<<total_bits<<endl;
}

void findheight(struct treenode *heap)
{
 if(heap==NULL)
	return;
 if(heap->lptr==NULL && heap->rptr==NULL)
  {
	int h=height(root,heap,0);
	heap->bits=h;
	cout<<heap->c<<"  "<<h<<endl;
	total_bits+=(heap->bits*heap->frequency);
	return ;
  }
findheight(heap->lptr);
findheight(heap->rptr);
}

void displaytree(struct treenode *heap)
{
  if(heap==NULL)
	return;
 displaytree(heap->lptr);
 cout<<heap->frequency<<"  "<<heap->c<<endl;
 displaytree(heap->rptr);
}

int height(struct treenode *heap,struct treenode *node,int cnt)
{
 if(heap==NULL) 
	return 0; 
  
 if(node==heap) 
        return cnt; 
  
 int downheight=height(heap->lptr,node,cnt + 1);

 if (downheight != 0) 
        return downheight; 

 downheight=height(heap->rptr,node,cnt + 1); 
	return downheight; 		

}

void heap_sort(struct treenode *heap[])
{
 build_min_heap(heap);
 n=size(heap);
 for(int i=n;i>=2;i--)		
  {
	swap(heap[1],heap[i]);
	n-=1;
	min_heapify(heap,1);
  }
}

void swap(struct treenode *heap[],int i,int val)
{
 struct treenode *temp; 
 temp=heap[i];
 heap[i]=heap[val];
 heap[val]=temp;
}

int left(int i)
{
  return(2*i);
}

int right(int i)
{
 return((2*i)+1);
}

void display(struct treenode *heap[])
{
 for(int i=1;i<=size(heap);i++)
	cout<<heap[i]->frequency<<endl;
}

void min_heapify(struct treenode *heap[],int i)
{
 int l,r,min_val;
 l=left(i);
 r=right(i);
 if(l<=n && heap[l]->frequency<heap[i]->frequency)
 	min_val=l;
 else
	min_val=i;
 if(r<=n && heap[r]->frequency<heap[min_val]->frequency)
 	min_val=r;
 if(min_val!=i)
  {
 	swap(heap,i,min_val);
	min_heapify(heap,min_val);  
  }
}

int size(struct treenode *heap[])
{
 int cnt=0,j;
 for(j=1;j<=N && heap[j]->c!='\0';j++)
	cnt++;
 return cnt;
}

void build_min_heap(struct treenode *heap[])
{
 n=size(heap);
 for(int i=n/2;i>=1;i--) 
	min_heapify(heap,i);
}

void setdata(string str,char carr[],int freq[],struct treenode *heap[])
{
 int i,j,k;
 for(i=1;i<=N;i++)
	freq[i]=0;

 i=0;
 k=1;
 do
  {
	for(j=1;j<=N&&carr[j]!='\0';j++)
	 {
		if(str[i]==carr[j])
 		 {
			freq[j]++;
			break;
		 }		
	 }
	if(carr[j]=='\0')	
	 {
		carr[k]=str[i];
		freq[k]++;		
		k++;
	 }
	i++;
  }while(i<str.length());
 
 for(i=1;i<=N&&carr[i]!='\0';i++)
  {
	heap[i]->lptr=heap[i]->rptr=NULL;
	heap[i]->frequency=freq[i];
	heap[i]->c=carr[i];
	heap[i]->bits=0;		
  }
 n=size(heap);
}
