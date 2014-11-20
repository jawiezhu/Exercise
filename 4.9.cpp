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
	CandyBar * snack=new CandyBar[3];

	getline(cin,snack[0].logo);
	cin>>snack[0].weight;
	cin>>snack[0].cal;


	cout<<snack[0].logo<<endl;
	cout<<snack[0].weight<<endl;
	cout<<snack[0].cal<<endl;

	delete [] snack;
	return 0;
}