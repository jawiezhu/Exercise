#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
	string s;
	getline(cin,s);
	int i;
	int j;
	int p;
	int q;
	j=s.length();
	for(q=s.length()-1;q>=0;q--)
	{
		s[q+1]=s[q];
	}

	s[0]=' ';

	for(i=s.length();i>=0;i--)
	{
		if(s[i]==' ')
		{
			//p=i;
			for(p=i+1;p<=j;p++)
				cout<<s[p];
			cout<<' ';
			j=i;
		}
	}
	cout<<endl;
	return 0;

}