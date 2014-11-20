#include<iostream>
#include<array>
using namespace std;
const int ArSize=110;

int main()
{
	array<long double,ArSize>factorials;
	factorials[1]=factorials[0]=1;
	int i;


	// for(int i=2;i<ArSize;i++)
	// 	factorials[i]=i*factorials[i-1];

	cout<<"100!="<<sizeof(long long)<<endl;
}