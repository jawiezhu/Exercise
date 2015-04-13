#include <iostream>
#include <cmath>
using namespace std;

int a[13]={0};
int n=12,cnt=0;

bool isSafe(int a[],int n)
{
	int i=0;
	int j=0;

	for(i=2;i<=n;i++)
		for(j=1;j<=i-1;j++)
			if((a[i]==a[j])||(abs(a[i]-a[j])==i-j))
				return false;
	return true;
}

void Queen(int k)
{
	int i=0;
	if(k>n)
	{
		cnt++;
		cout<<cnt<<endl;
		for(i=1;i<=n;i++)
			cout<<a[i];
		cout<<endl;
	}else{

		for(i=1;i<=n;i++)
		{
			a[k]=i;
			if(isSafe(a,k))
				Queen(k+1);
		}
	}
	return ;
}

int main()
{
	Queen(1);
	return 0;
}

//================================================================================================


// void EightQueen (int row)
// {
//         if(row>N)
//         {
//                PrintMap();    //打印棋盘
//          }
//         else
//         {
//         int column;
//         for (column = 0; column < N; ++column)
//         {
//                 A[row]= column;                    //代表第row行的第column列放皇后
//                 if (IsCorrect (row, column))    //判断在第row行的第column列放皇后是否可行
//                 {
//                         EightQueen (row + 1);
//                 }
//               //将标记数组修改回原来
//         }
//         }
// }


// //================================================================================================


// //位置冲突算法 
// bool Chongtu(int a[], int n)//a[]位置数组，n皇后个数 
// {
// 	int i = 0, j = 0;

// 	for (i = 2; i <= n; ++i)//i：位置 
// 		for (j = 1; j <= i-1; ++j)//j：位置 
// 			if ((a[i] == a[j]) || (abs(a[i]-a[j]) == i-j))//1：在一行；2：在对角线上 
// 				return false;   //冲突 
// 	return true;//不冲突 
// }

// //八皇后问题：回溯法（非递归） 
// void Queens8()
// {
// 	int n = 8;        //8个皇后 
// 	int count = 0;    //记录当前第几情况 
// 	int a[9] = {0};   //存放皇后位置，如：a[2] = 4;表示第2列第4行有一个皇后（a[0]不用） 
// 	int i = 0,k = 1;  //初始化k为第一列 

// 	a[1] = 0;         //初始化a[1] = 0 
	
// 	while (k > 0)     //k==0时：表示摆放第1个皇后就超过了列底部（即已经找完所有情况） 
// 	{
// 		a[k] += 1;    //a[k]位置，摆放一个皇后 
// 		while ((a[k] <= n) && (!Chongtu(a,k)))//如果a[k]（即皇后摆放位置）没有到列最底部，且摆放冲突。 
// 			a[k] += 1;//将皇后列下移一位 
// 		if (a[k] <= n)//皇后摆放位置没有到达列最底部 
// 		{
// 			if (k == n)//k==n表示，8列皇后全部摆放完毕 
// 			{
// 				printf("第%d种情况：",++count);
// 				for (i = 1; i <= n; ++i)//打印情况 
// 					printf("%d ",a[i]);
// 				printf("\n");
// 			}
// 			else      //皇后还未摆放完毕 
// 			{
// 				k += 1;    //继续摆放下一列 
// 				a[k] = 0;  //此行初始化a[k] = 0;表示第k列，从第一行开始摆放皇后 
// 			}
// 		}
// 		else  //回溯：当a[k]>8进入else,表示在第k列中没有找到合适的摆放位置 
// 			k -= 1;//回溯到k-1步：k表示第几个皇后，a[k]表示第k个皇后摆放的位置 
// 	}
// 	return;
// }

// //主函数 
// int main()
// {
// 	Queens8();

// 	return 0;
// }