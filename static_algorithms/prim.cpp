#include<iostream>
#include<vector>

using namespace std;

void setdata(int v,vector <vector<int>> &graph);
void display(int v,vector <vector<int>> graph);
void prim(int v,vector <pair<int,int>> mst,vector <vector<int>> graph);
int min(int v,vector <pair<int,int>> mst,vector <int> visited);
int checkvisited(int v,vector <int> visited);

int main()
{
 int i,j,v;
 cout<<"Enter number of vertices"<<endl;
 cin>>v;
 vector<vector<int>> graph(v,vector<int> (v,0));
 vector<pair<int,int>> mst(v,{10000,0});
 
 setdata(v,graph);
 display(v,graph);
 prim(v,mst,graph);
}

void setdata(int v,vector <vector<int>> &graph)
{
 int link;
 for(int i=0;i<v;i++)
  {
	cout<<"Enter links and its corresponding weights for vertex "<<i<<" (-1 for next vertex) (-2 to exit) "<<endl;	
	while(1)
	 {
		cin>>link;		
		if(link==-1 || link==-2)
			break;
		if(link>v)
			cout<<"link not found"<<endl;
		else
		 {
			cin>>graph[i][link];
			graph[link][i]=graph[i][link];
		 }
	 }
 	if(link==-2)
		break;
  }
}


void display(int v,vector <vector<int>> graph)
{
 int i,j;
 for(i=0;i<v;i++)
  {
	for(j=0;j<v;j++)
		cout<<graph[i][j]<<"  ";
	cout<<endl;
  }			
}


void prim(int v,vector <pair<int,int>> mst,vector <vector<int>> graph)
{
 int i,j,k,min_val=0,total=0;
 vector <int> visited(v,0);
 while(1)
  {
	i=0;
	while(i!=min_val)
	 	i++;
		for(j=0;j<v;j++)
		 {
			if(visited[j]!=1 && graph[i][j]!=0 && graph[i][j]<mst[j].first)
			 {
				mst[j].first=graph[i][j];
				mst[j].second=i;
			 }
		 }
	visited[i]=1;
	if(!checkvisited(v,visited))
		break;
	min_val=min(v,mst,visited);
  }
 cout<<endl;
 for(i=1;i<v;i++)
  {
 	cout<<mst[i].second<<" - "<<i<<endl;
	total+=mst[i].first;
  }
 cout<<total<<endl;
}

int min(int v,vector <pair<int,int>> mst,vector <int> visited)
{
 int m=10000,temp,i;
 for(i=0;i<v;i++)
  {
	if(visited[i]!=1)
	 {
		if(mst[i].first<m)
		 {
			m=mst[i].first;
			temp=i;
		 }
		
	 }
  }
 return temp;
}

int checkvisited(int v,vector <int> visited)
{
 int cnt=0;
 for(int x=0;x<v;x++)
  {
	if(visited[x]!=1)
		cnt++;	
  }
return cnt;
}
