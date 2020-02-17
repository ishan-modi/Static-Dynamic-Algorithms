#include<iostream>
#include<cmath>

//€5, €10, €20, €50, €100, €200 and €500 
//1, 2, 5, 10, 20 and 50 cent, €1 and €2

using namespace std;

void makingchange(double amount,double array[]);

int main()
{
 double value,paid;
 double array[]={500,200,100,50,20,10,5,2,1,0.5,0.2,0.1,0.05,0.02,0.01};
 cout<<"Enter value amount and paid amount :"<<endl;
 while(1)
  {
	cin>>value>>paid;
	if(value<=paid)
		break;
  	else
		cout<<" invalid input"<<endl;
  }
 if(paid-value==0)
	cout<<"0 notes are to be paid";
 else
 	makingchange(paid-value,array);
}

void makingchange(double amount,double array[])
{
 int i=0,q;
 
 if(amount>=array[i])
  {
	q=amount/array[i];
	amount=fmod(amount,array[i]);
	cout<<array[i]<<"-"<<q<<endl;
  }
 i++;
 if(amount>=array[i])
  {
	q=amount/array[i];
	amount=fmod(amount,array[i]);
	cout<<array[i]<<"-"<<q<<endl;
  }
 i++;
 if(amount>=array[i])
  {
	q=amount/array[i];
	amount=fmod(amount,array[i]);
	cout<<array[i]<<"-"<<q<<endl;
  }
 i++;
 if(amount>=array[i])
  {
	q=amount/array[i];
	amount=fmod(amount,array[i]);
	cout<<array[i]<<"-"<<q<<endl;
  }
 i++;
 if(amount>=array[i])
  {
	q=amount/array[i];
	amount=fmod(amount,array[i]);
	cout<<array[i]<<"-"<<q<<endl;
  }
 i++;
 if(amount>=array[i])
  {
	q=amount/array[i];
	amount=fmod(amount,array[i]);
	cout<<array[i]<<"-"<<q<<endl;
  }
 i++;
 if(amount>=array[i])
  {
	q=amount/array[i];
	amount=fmod(amount,array[i]);
	cout<<array[i]<<"-"<<q<<endl;
  }
 i++;
 if(amount>=array[i])
  {
	q=amount/array[i];
	amount=fmod(amount,array[i]);
	cout<<array[i]<<"-"<<q<<endl;
  }
 i++;
 if(amount>=array[i])
  {
	q=amount/array[i];
	amount=fmod(amount,array[i]);
	cout<<array[i]<<"-"<<q<<endl;
  }
 i++;
 if(amount>=array[i])
  {
	q=amount/array[i];
	amount=fmod(amount,array[i]);
	cout<<array[i]<<"-"<<q<<endl;
  }
 i++;
 if(amount>=array[i])
  {
	q=amount/array[i];
	amount=fmod(amount,array[i]);
	cout<<array[i]<<"-"<<q<<endl;
  }
 i++;
 if(amount>=array[i])
  {
	q=amount/array[i];
	amount=fmod(amount,array[i]);
	cout<<array[i]<<"-"<<q<<endl;
  }
 i++;
 if(amount>=array[i])
  {
	q=amount/array[i];
	amount=fmod(amount,array[i]);
	cout<<array[i]<<"-"<<q<<endl;
  }
 i++;
 if(amount>=array[i])
  {
	q=amount/array[i];
	amount=fmod(amount,array[i]);
	cout<<array[i]<<"-"<<q<<endl;
  }
 i++;
 if(amount>=array[i])
  {
	q=amount/array[i];
	amount=fmod(amount,array[i]);
	cout<<array[i]<<"-"<<q<<endl;
  }
 i++;
}
