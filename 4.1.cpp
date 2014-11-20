#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char fname[10];
	char lname[10];
	int i;
	char letter[2];
	int year;

	cin.getline(lname,10);
	cin.getline(fname,10);
	cin.getline(letter,2); //MAX IS 2/
	cin>>year;

	cout<<fname<<","<<lname<<endl;
	cout<<letter[0]<<endl;
	cout<<year<<endl;
	return 0;	
}