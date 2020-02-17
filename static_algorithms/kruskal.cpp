#include<iostream>
#include<vector>
#include<bits/stdc++.h> 

using namespace std;

void setdata(int v,vector <vector<int>> &graph);
void display(int v,vector <vector<int>> graph);
void kruskal(int v,vector <pair<int,pair<int,int>>> mst,vector <vector<int>> graph);
void Union(vector <int> &parent, int x, int y); 
int find(vector <int> &parent, int i);
int iscycle(vector <pair<int,pair<int,int>>> mst ,int v,vector <int> &parent,int i);

int main()
{
 int i,j,v;
 cout<<"Enter number of vertices"<<endl;
 cin>>v;
 vector<vector<int>> graph(v,vector<int> (v,0));
 vector<pair<int,pair<int,int>>> mst; 
 setdata(v,graph);
 display(v,graph);
 kruskal(v,mst,graph);
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


void kruskal(int v,vector <pair<int,pair<int,int>>> mst,vector <vector<int>> graph)
{
 int i,j,e,k=0,total=0;
 vector <int> visited(v,0); 
 for(i=0;i<v;i++)
  {
	for(j=0;j<v;j++)
	 {
		if(visited[j]!=1 && graph[i][j]!=0)
			mst.push_back(make_pair(graph[i][j],make_pair(i,j)));
	 }
	visited[i]=1;
  }
 sort(mst.begin(),mst.end()); 
 vector<int> parent(v,-1);
 e=mst.size();

 for(i=0;i<mst.size();i++)
  {
	int temp=0;
	while(1)
	 { 
		if(iscycle(mst,v,parent,i)==0)
		 {
			total+=mst[i].first;
		 	temp++;	
		 }
		else
			mst.erase(mst.begin()+i);
		k++; 
		if(temp>0 || k>=e)
			break;	
  	 }
   }
 cout<<endl;
 for(i=0;i<mst.size();i++)
	cout<<mst[i].second.first<<" - "<<mst[i].second.second<<endl;
 cout<<total<<endl;
}

int iscycle(vector <pair<int,pair<int,int>>> mst ,int v,vector<int> &parent,int i)
{ 
 int x = find(parent, (mst[i].second.first)); 
 int y = find(parent, (mst[i].second.second)); 
 if (x == y) 
	return 1;
 Union(parent, x, y); 
 return 0;	
}

int find(vector <int> &parent, int i) 
{ 
 if (parent[i] == -1) 
        return i;
 //cout<<parent[i]; 
 return find(parent, parent[i]); 
} 
  
void Union(vector <int> &parent, int x, int y) 
{ 
 int xset = find(parent, x); 
 int yset = find(parent, y); 
 if(xset!=yset)
       parent[xset] = yset;
 }  
