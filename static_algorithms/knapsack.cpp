#include<iostream>

using namespace std;

int N;

void setdata(float weight[],float value[],float val_per_weight[],int iniarr[]);
void sort(float weight[],float value[],float val_per_weight[],int iniar[]);
void knapsack(float weight[],float value[],float val_per_weight[],int iniarr[]);
void display(float weight[],float value[],float val_per_weight[]);

int main()
{
 cout<<"Enter the no. of items";
 cin>>N;
 float weight[N],value[N],val_per_weight[N];
 int iniarr[N];
 setdata(weight,value,val_per_weight,iniarr);
 sort(weight,value,val_per_weight,iniarr);
 knapsack(weight,value,val_per_weight,iniarr);
 return 0;  
}

// PRE PROCESSING
void setdata(float weight[],float value[],float val_per_weight[],int iniarr[])
{
 int i=0;
 cout<<"Enter weight and corresponding values \n";
 while(i<N)
  { 
	cin>>weight[i];
   	cin>>value[i];
	val_per_weight[i]=value[i]/weight[i];	
	iniarr[i]=i;
	i++;		
  }
}

void sort(float weight[],float value[],float val_per_weight[],int iniarr[])
{
 float key,key1,key2,key3;
 int i,j;
 for(i=1;i<N;i++)
  {
	 key=val_per_weight[i];
	 key1=weight[i];
	 key2=value[i];
	 key3=iniarr[i];
	 for(j=i-1;j>=0;j--)
 	  {
		 if(key>val_per_weight[j])
		  {
			 val_per_weight[j+1]=val_per_weight[j];
			 weight[j+1]=weight[j];
			 value[j+1]=value[j];
		  	 iniarr[j+1]=iniarr[j];
		  }
		 else 
 		  	break;
	  }
	 val_per_weight[j+1]=key;
	 weight[j+1]=key1;
	 value[j+1]=key2;
	 iniarr[j+1]=key3;
  }
}

// ALGORITHM
void knapsack(float weight[],float value[],float val_per_weight[],int iniarr[])
{
 int i=0;
 float capacity,crrcap=0,profit=0,solvec[N];
 cout<<"Enter the capacity"<<endl;
 cin>>capacity;
 for(int j=0;j<N;j++)
	solvec[j]=0;
 while(capacity>crrcap)
  {
	if((crrcap+weight[i])<capacity)
	 {   	
		crrcap+=weight[i];
		profit+=value[i];
	 }	
	else
	 {
		profit+=(capacity-crrcap)*val_per_weight[i];	 	
		solvec[iniarr[i]]=(capacity-crrcap)/weight[i];
		crrcap+=(capacity-crrcap);
		break;
	 }   	
	solvec[iniarr[i]]=1;
	i++;
  }

 // POST PROCESSING
 cout<<"Profit :\n"<<profit<<endl; 
 cout<<"Sol vector :\n";
 for(i=0;i<N;i++)
 	cout<<solvec[i]<<" ";
 cout<<endl;
}

