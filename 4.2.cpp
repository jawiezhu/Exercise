#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	string name;
	string dessert;
	getline(cin,name);
	//cin.get(dessert,20).get();
	getline(cin,dessert);

	cout<<"i have dessert:"<<dessert<<endl;
	cout<<"for you: "<<name<<endl;

	return 0;
}