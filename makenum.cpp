/*
1.sort the numbers and make a new file to store them.
2.fine one number that the user want return the no.
3.
*/

#include<iostream>
#include<fstream>
#include<array>
#include<cstdlib>
#include<ctime>
const int MAX=100;
using namespace std;
typedef double TYPE;

void makenum(void);
void calnum(void);


int main()
{
	time_t t1,t2,t3;
	t1=clock();
	makenum();
	t2=clock();
	calnum();
	t3=clock();
	cout<<t1<<endl;
	cout<<t2<<endl;
	cout<<t3<<endl;
	cout<<"----time------"<<endl;
	cout<<t2-t1<<endl;
	cout<<t3-t2<<endl;

	return 0;
}

void makenum()
{
	ofstream outFile;
	outFile.open("1.textile",ios_base::app);

	array<TYPE,MAX>a;


	srand((TYPE)time(NULL));



	for(int i=0;i<MAX;i++)
		 a[i]=((rand()%(10000+1))-1)/100.0;

	for(int i=0;i<MAX;i++)
	{
		outFile<<a[i];
		outFile<<" ";
	}
	outFile.close();
}

void calnum()
{
	ifstream inFile;
	int i=0;
	inFile.open("1.textile");

	if(!inFile.is_open())
	{
		exit(EXIT_FAILURE);
	}

	array<TYPE,MAX*10>b;
	TYPE sum=0.0;
	int cnt=0;



	//int tmp=i;
	//inFile>>b[0];

	while(!inFile.eof())
	{			
		i=0;
		inFile>>b[i];
		sum=sum+b[i];
		cnt++;
		i++;
		
	}

	cout<<"sum:"<<sum<<endl;
	cout<<"numbers: "<<cnt<<endl;

	inFile.close();

}
