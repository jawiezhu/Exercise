// 分布式系统中的RPC请求经常出现乱序的情况。 
// 写一个算法来将一个乱序的序列保序输出。例如,假设起始序号是1，对于(1, 2, 5, 8, 10, 4, 3, 6, 9, 7)这个序列，输出是: 
// 1 
// 2 
// 3, 4, 5 
// 6 
// 7, 8, 9, 10

// 上述例子中，3到来的时候会发现4,5已经在了。因此将已经满足顺序的整个序列（3, 4, 5）输出为一行。

// 要求： 
// 1. 写一个高效的算法完成上述功能，实现要尽可能的健壮、易于维护 
// 2. 为该算法设计并实现单元测试

#include <iostream>
using namespace std;
int main()
{
	int a[10]={1,2,5,8,10,4,3,6,9,7};
	int book[11];
	memset(book,0,sizeof(book));
	int j=1;
	int flag=0;

	for(int i=0;i<10;i++)
	{
		book[a[i]]=1;
		while(book[j]&&j<11)
		{
			if(flag==1)
				cout<<",";
			else
				flag=1;
			cout<<j;
			j++;
		}

		if(flag==1)
		{
			flag=0;
			cout<<endl;
		}
	}
	return 0;
}