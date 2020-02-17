#include<iostream>
#include<queue>

#define N 10000

using namespace std;

int v;

struct node 
{
 int val;
 int weight;
 struct node *ptr;
};

 
void setdata(struct node graph[]);
void dfstraverse(int value, struct node graph[],int traverse[]);
void dijkstra(int value,struct node graph[],int visited[]);
//int minimum(int *a,int b,int c);
void display(int value,struct node graph[]);


int main()
{
 int value;
 cout<<"Enter the number of vertices"<<endl;
 cin>>v;
 int traverse[v+1],visited[v+1];
 for(int i=1;i<=v;i++)
  {
	traverse[i]=0;
	visited[i]=0;
  }
 struct node *graph;
 graph=new struct node[v];
 setdata(graph);
 cout<<endl;
 dfstraverse(1,graph,traverse);
 cout<<"Enter the source vertex";
 cin>>value;
 dijkstra(value,graph,visited);
 display(value,graph);
}

void setdata(struct node graph[])
{
 int link,w;
 struct node *temp;
 for(int i=1;i<=v;i++)
  {
	graph[i].val=i;
	graph[i].ptr=NULL;
	temp=&graph[i];
 	while(1)
	 {
	 	cout<<"Enter links and corresponding weights for node "<<i<<" (-1 to exit) "<<endl;		
		cin>>link;
		if(link==-1)
			break;			
 		cin>>w;
		//cout<<w;
		if(link > v || link==i)
			cout<<"link not found"<<endl;
		else
		 {	
			struct node *newnode = new node;	
			newnode->val=link;
			newnode->weight=w;
			newnode->ptr==NULL;
			while(temp->ptr!=NULL)
				temp=temp->ptr;
			temp->ptr=newnode;
		 }
	 }
  }
}

void dfstraverse(int value, struct node graph[],int traverse[])
{
 int i;
 struct node *temp,x;
 
 traverse[value]=1;
 cout<<"traversed "<<graph[value].val<<endl;
 temp=graph[value].ptr;
 while(temp!=NULL)
  {
	while(traverse[temp->val]!=1)
  	 {
		x.val=temp->val;
		dfstraverse(x.val,graph,traverse);
 	 }		
	temp=temp->ptr;
  }
}


void dijkstra(int value,struct node graph[],int visited[])
{
 int min=N,i,j=0;
 queue <int> que;
 struct node *source,*temp;
 for(i=1;i<=v;i++)
  {
	if(graph[i].val!=value)
		graph[i].weight=N;
	else
	 {
		graph[i].weight=0;
	 	source=&graph[i];
	 }
  }
 temp=source;
while(!que.empty() || j==0)
 {
	visited[temp->val]=1;
 	while(1)
 	 {
		temp=temp->ptr;
		if(temp==NULL)
			break;		
		if(visited[temp->val]!=1)
			que.push(temp->val);		
		if((temp->weight+source->weight)<graph[temp->val].weight)
			graph[temp->val].weight=(temp->weight+source->weight);
	cout<<(temp->weight+source->weight)<<endl;
 	 }
	source=temp=&graph[que.front()];
 	que.pop();
	j++;
 }
}

void display(int value,struct node graph[])
{
 for(int i=1;i<=v;i++)
	cout<<value<<" to "<<i<<" - "<<graph[i].weight<<endl; 
}


/*int minimum(int *a,int b,int c)
{
 if(*a>b)
  {
	(*a)=b;	5
	return c;
  }
}*/
