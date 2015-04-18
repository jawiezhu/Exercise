#include <iostream>
#include <cmath>
using namespace std;

int a[9]={0};
int n=8,cnt=0;

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
		//cout<<cnt<<endl;
		// for(i=1;i<=n;i++)
		// 	cout<<a[i];
		// cout<<endl;
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
	cout<<cnt<<endl;
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


// //================================================================================================

// 位运算
// 初始化：　upperlim =  (1 << n)-1; Ans = 0;
// 调用参数：test(0, 0, 0);
// 和普通算法一样，这是一个递归函数，程序一行一行地寻找可以放皇后的地方。函数带三个参数row、ld和rd，
// 分别表示在纵列和两个对角线方向的限制条件下这一行的哪些地方不能放。位于该行上的冲突位置就用row、ld和rd中的1来表示。把它们三个并起来，
// 得到该行所有的禁位，取反后就得到所有可以放的位置（用pos来表示）。
// p = pos & (~pos + 1)其结果是取出最右边的那个1。这样，p就表示该行的某个可以放子的位置，把它从pos中移除并递归调用test过程。
// 注意递归调用时三个参数的变化，每个参数都加上了一个禁位，但两个对角线方向的禁位对下一行的影响需要平移一位。
// 最后，如果递归到某个时候发现row=upperlim了，说明n个皇后全放进去了，找到的解的个数加一。
// void test(int row, int ld, int rd)
// {
// 	int pos, p;
// 	if ( row != upperlim )
// 	{
// 		pos = upperlim & (~(row | ld | rd ));
// 		while ( pos )
// 		{
// 			p = pos & (~pos + 1);
// 			pos = pos - p;
// 			test(row | p, (ld | p) << 1, (rd | p) >> 1);
// 		}
// 	}
// 	else
// 		++Ans;
// }


// //================================================================================================


// /*
// ** 目前最快的N皇后递归解决方法
// ** N Queens Problem
// ** 试探-回溯算法，递归实现
// */
// #include "iostream"
// using namespace std;
// #include "time.h"

// // sum用来记录皇后放置成功的不同布局数；upperlim用来标记所有列都已经放置好了皇后。
// long sum = 0, upperlim = 1;     

// // 试探算法从最右边的列开始。
// void test(long row, long ld, long rd)
// {
// 	if (row != upperlim)
// 	{
// 		// row，ld，rd进行“或”运算，求得所有可以放置皇后的列,对应位为0，
// 		// 然后再取反后“与”上全1的数，来求得当前所有可以放置皇后的位置，对应列改为1
// 		// 也就是求取当前哪些列可以放置皇后
// 		long pos = upperlim & ~(row | ld | rd); 
// 		while (pos)    // 0 -- 皇后没有地方可放，回溯
// 		{
// 			// 拷贝pos最右边为1的bit，其余bit置0
// 			// 也就是取得可以放皇后的最右边的列
// 			long p = pos & -pos;                                              

// 			// 将pos最右边为1的bit清零
// 			// 也就是为获取下一次的最右可用列使用做准备，
// 			// 程序将来会回溯到这个位置继续试探
// 			pos -= p;                           

// 			// row + p，将当前列置1，表示记录这次皇后放置的列。
// 			// (ld + p) << 1，标记当前皇后左边相邻的列不允许下一个皇后放置。
// 			// (ld + p) >> 1，标记当前皇后右边相邻的列不允许下一个皇后放置。
// 			// 此处的移位操作实际上是记录对角线上的限制，只是因为问题都化归
// 			// 到一行网格上来解决，所以表示为列的限制就可以了。显然，随着移位
// 			// 在每次选择列之前进行，原来N×N网格中某个已放置的皇后针对其对角线
// 			// 上产生的限制都被记录下来了
// 			test(row + p, (ld + p) << 1, (rd + p) >> 1);                              
// 		}
// 	}
// 	else   
// 	{
// 		// row的所有位都为1，即找到了一个成功的布局，回溯
// 		sum++;
// 	}
// }

// int main(int argc, char *argv[])
// {
// 	time_t tm;
// 	int n = 16;

// 	if (argc != 1)
// 		n = atoi(argv[1]);
// 	tm = time(0);

// 	// 因为整型数的限制，最大只能32位，
// 	// 如果想处理N大于32的皇后问题，需要
// 	// 用bitset数据结构进行存储
// 	if ((n < 1) || (n > 32))                 
// 	{
// 		printf(" 只能计算1-32之间\n");
// 		exit(-1);
// 	}
// 	printf("%d 皇后\n", n);

// 	// N个皇后只需N位存储，N列中某列有皇后则对应bit置1。
// 	upperlim = (upperlim << n) - 1;         

// 	test(0, 0, 0);
// 	printf("共有%ld种排列, 计算时间%d秒 \n", sum, (int) (time(0) - tm));
// 	system("pause");
// 	return 0;
// }