#include<iostream>
#include<cctype>
using namespace std;
int main()
{
	char ch;
	cin.get(ch);
	while(ch!='@')
	{
		if(!isdigit(ch))
		{
			if(isupper(ch))
				ch=tolower(ch);
			else if(islower(ch))
				ch=toupper(ch);
			cout<<ch;
		}

		cin.get(ch);

	}

	return 0;
}