#include<iostream>
#include<array>
#include<iomanip>
using namespace std;

int main()
{
	double sum;
	array<double,3>grade;

	cin>>grade[0];
	cin>>grade[1];
	cin>>grade[2];

	sum=grade[0]+grade[1]+grade[2];

	cout<<setiosflags(ios::fixed)<<setprecision(2)<<sum/3.0<<endl;

	return 0;
}