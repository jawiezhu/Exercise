#include<iostream>
#include<string>
#include<cstring>
using namespace std;

struct Pizza
{
	/* data */
	string company;
	double cel;
	double weight;
};

int main(){

	// Pizza p[5];
	// getline(cin,p[0].company);
	// cin>>p[0].cel;
	// cin>>p[0].weight;

	// cout<<p[0].company<<endl;
	// cout<<p[0].cel<<endl;
	// cout<<p[0].weight<<endl;

	Pizza *p=new Pizza;
	cin>>p->cel;
	cin.get();  
	getline(cin,p->company);
	cin>>p->weight;

	cout<<p->company<<endl;
	cout<<p->cel<<endl;
	cout<<p->weight<<endl;
	delete p;
	return 0;

}