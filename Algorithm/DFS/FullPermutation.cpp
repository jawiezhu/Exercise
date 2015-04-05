
//Use 1,2,3,4,5,6,7,8,9 makes three numbers abc,def and ghi, every number only
//use once. and make the  abc:def:ghi=1:2:3.

#include <iostream>
using namespace std;

int a[10],book[10],total=0;
int sum=0;
void dfs(int step);

int main()
{
	dfs(1);

	//cout<<total<<endl;
	return 0;
}

void dfs(int step)
{
	int i;
	if(step==10)
	{
		int n1,n2,n3;
		n1=a[1]*100+a[2]*10+a[3];
		n2=a[4]*100+a[5]*10+a[6];
		n3=a[7]*100+a[8]*10+a[9];
		if(n2==2*n1&&2*n3==3*n2&&n3==3*n1)
		{
			cout<<n1<<" "<<n2<<" "<<n3<<endl;
		}

		return ;
	}

	for(i=1;i<=9;i++)
	{
		if(book[i]==0)
		{


			a[step]=i;
			

			book[i]=1;
			dfs(step+1);
			book[i]=0;
		}
	}
	return ;
}