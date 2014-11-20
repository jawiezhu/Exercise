#include<iostream>
#include<string>
using namespace std;

struct car
{
	string fac;
	int year;
};

int main()
{
	int n;
	int i;
	cout<<"How many cars do you have?:";
	cin>>n;
	cin.get();   

	car *mycar=new car[n];

	for(i=0;i<n;i++)
	{
		cout<<"Car # "<<i+1<<":"<<endl;
		cout<<"Please enter the make:";
		getline(cin,mycar[i].fac);

		cout<<"Please enter the year:";
		cin>>mycar[i].year;
		cin.get();
	}

	cout<<"here is your cars:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<mycar[i].year<<" "<<mycar[i].fac<<endl;
	}

	return 0;
}