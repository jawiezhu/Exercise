#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i;

	for(i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			cout<<".";


		}


			for(int q=i+1;q>0;q--)
				cout<<"*";
		cout<<endl;
	}

	return 0;
}