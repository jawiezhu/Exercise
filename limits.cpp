#include<iostream>
#include<climits>
using namespace std;

int main()
{
	int n_int=INT_MAX;
	short n_short=SHRT_MAX;
	long n_long=LONG_MAX;
	long long n_llong=LLONG_MAX;

	cout<<"int is "<<sizeof(n_int)<<endl;
	cout<<"short is "<<sizeof(n_short)<<endl;
	cout<<"long is "<<sizeof(n_long)<<endl;
	cout<<"long long is "<<sizeof(n_llong)<<endl;

	cout<<"MAX:"<<endl;
	cout<<"int: "<<n_int<<endl;
	cout<<"short: "<<n_short<<endl;
	cout<<"long: "<<n_long<<endl;
	cout<<"long long: "<<n_llong<<endl;

	cout<<"MIN: "<<INT_MIN<<endl;
	cout<<"Bits per byte: "<<CHAR_BIT<<endl;
	return 0;

}