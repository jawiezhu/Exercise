#include<iostream>
using namespace std;

int main()
{
	int a[6]={1,2,7,11,9,22};
	int *p=a;
	++p;
	cout<<*p<<endl;
	cout<<*++p<<endl;
	int x=(*p)++;
	cout<<a[2]<<endl;
	cout<<*p++<<endl;
	cout<<*p<<endl;
	return 0;
}