#include<iostream>
#include<string>
using namespace std;

struct CandyBar
{
	/* data */
	string logo;
	double weight;
	int cal;
};

int main()
{
	//CandyBar snack={"Mocha Munch",2.3,350};
	CandyBar snack[3]=
	{
		{"Mocha Munch",2.3,350},
		{"Mocha1 Munch",2.3,350},
		{"Mocha2 Munch",2.3,350}	};
	cout<<snack[0].logo<<endl;
	cout<<snack[0].weight<<endl;
	cout<<snack[0].cal<<endl;
	return 0;
}