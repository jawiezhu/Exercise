//全排列
// 将每个元素放到n个元素组成的队列最前方，然后对剩余元素进行全排列，依次递归下去。
//   比如：
//   a b c
//   首先将a放到最前方（跟第一个元素交换），然后排列b c，然后将a放回本来位置 
//    结果 a b c； a c b
//   其次将b放到最前方（跟第一个元素交换），然后排列a c，然后将b放回
//    结果 b a c； b c a
//    。。。
 
//   如果是4个元素，就将元素依次放到第一个元素的位置，后面的排序类似前面的3元素排序。
#include <iostream>
using namespace std;


template<class T>
inline void Swap(T&a,T&b)
{
	T temp=a;
	a=b;
	b=temp;
}


template<class T>
void Perm(T list[],int k,int m)
{
	int i;
	if(k==m)//输出一个全排列
	{
		for(i=0;i<=m;i++)
		{
			cout<<list[i];
		}
		cout<<endl;
	}else{ //list[k:m]有多个排列方式
		//递归产生这些排列
		for(i=k;i<=m;i++)
		{
			Swap(list[k],list[i]);//交换这些位置，逐步前提
			Perm(list,k+1,m);
			Swap(list[k],list[i]);//将位子还回去，对下一次排列负责
		}
	}
}



int main()
{
	char list[]="abc";
	Perm(list,0,2);
	return 0;
}