#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	char a[50];

	int year;
	double a_price;
	double b_price;

	ofstream outFile;
	outFile.open("1.textile");

	cin.getline(a,50);
	cin.get();
	cin>>year;
	cin>>a_price;
	b_price=a_price*11.82;

	outFile<<fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);

	outFile<<"MMM: "<<a<<endl;
	outFile<<"Year: "<<year<<endl;
	outFile<<"1: "<<a_price<<endl;
	outFile<<"2: "<<b_price<<endl;

	outFile.close();

	return 0;

}