// Given a collection of numbers, return all possible permutations.

// For example,
// [1,2,3] have the following permutations:
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

//在num中拿出1个数字放在第一个，然后剩下的数字做一个全排列
class Solution{
public:
	vector<vector<int>>permute(vector<int> &num){
		int N=num.size();
		vector<vector<int>> result;

		if(N==1)
		{
			result.push_back(num);
			return result;
		}

		vector<vector<int>> post;

		vector<int> cur;
		vector<int> tmp;

		for(int i=0;i<N;i++)
		{
			cur=num;
			cur.erase(cur.begin()+i);
			post=permute(cur);
			for(int j=0;j<post.size();j++)
			{
				tmp=post[j];
				tmp.insert(tmp.begin(),num[i]);
				result.push_back(tmp);
			}
		}
		
		return result;
	}
};


//建立一棵树
//         1234
//1234  2134  3214  4231
//  2134 2314  2431
//			2431  2413
// 对于第k层节点来说，就是交换固定了前面 k-1 位，然后分别 swap(k,k), 
// swap(k, k+1) , swap(k, k+2) ...

// 第三层，固定了第一位（即2），然后分别交换第1，1位，1，2位，1，3位

class Solution {
    
    vector<vector<int> > ret;
    int N;
    
public:
    void perm(vector<int> &num, int i){
        if( i == N){
            ret.push_back(num);
        }
        
        for(int j = i; j < N; j++){
            swap(num[i], num[j]);
            perm(num, i + 1);
            swap(num[j], num[i]);
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        N = num.size();
        ret.clear();   
        perm(num, 0);  
        return ret;  
    }
};

// stl的algorithm里面其实是有next permutation的算法的，那其实用next permutation的方法也是一个不错的选择

// 这个思路可以保证遍历的顺序是字典序，即按照从小到大的顺序

// next permutation的算法就是。。。swap + reverse。。。交换 & 倒叙

// 比如 1，2，3的下一个就是1，3，2这个很容易理解，因为2和3是升序的，只需要交换这两位，那么132 > 123，但是如果后面几位都是倒序的怎么办？

// 例如 5，4，7，5，3，2 这个序列

// 我们知道答案应该是 5，5，2，3，4，7

// 从直观上来说，7，5，3，2已经是这四位排列的最大值了，所以一定要动到 4 这个数字了，所以我们选了刚好比4大的5来和4进行交换，得到 5，5，。。。后面几位就按照升序放进去就可以了

// 但是令人兴奋的一点是，当4和5交换以后，后面的序列一定是倒序的，所以我们不需要重新sort，只需要将其reverse就可以了

// 这就是swap  + reverse的思路

// 注意，下面这个代码里面交换的是 i-1 和 j-1 所以i指向的是7，而j指向的是3

class Solution {
public:
     void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        //5,4,7,5,3,2
        //    |   |
        //    i   j
        //5,5,7,4,3,2
        //5,5,2,3,4,7
        int i = num.size()-1;
        while(i > 0 && num[i-1] >= num[i] ){
            i--;
        }
        
        int j = i;
        
        while(j < num.size() && num[j] > num[i-1]) j++;
        
        if(i == 0){
            reverse(num.begin(), num.end());
        }else{
            swap(num[i-1], num[j-1]);
            reverse(num.begin() + i, num.end());
        }
        
        
    }
    
    int factorial(int n){
        return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
    }


    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = num.size();
        vector<vector<int> > ret;
        
        ret.push_back(num);
        
        for(int i = 1; i < factorial(N); i++){
            nextPermutation(num);
            ret.push_back(num);
        }
        
        return ret;
        
    }
};


// 思路4是一个很常规的思路，很多把recursive的code改成iterative的code都会用到这样的方法，其实呢，它的本质就是把N个for改成while的方法。介个方法在编程之美里面的“电话号码”那一节提到过，不明白的童鞋可以去看一看，我觉得第一次想写粗来还是很难的，不过多写几个，就会很熟练啦

// 对应介个题目的思路捏就是。。。举个例子来说吧
// 如果我想求1,2,3,4的全排列
// 偶的思路就是建一个特殊的数，它的进位方法是 3, 2, 1, 0
// 所以，这个数的++过程就是
// 0000 -> 0010 -> 0100 -> 0110 ->0200 -> 0210 -> 
// 1000 -> 1010 -> 1100 -> 1110 ->1200 -> 1210 -> 
// 2000 -> 2010 -> 2100 -> 2110 ->2200 -> 2210 -> 
// 3000 -> 3010 -> 3100 -> 3110 ->3200 -> 3210
// 哇哈哈哈，刚好是24个！
// 然后捏？ b0 b1 b2 b3就代表在当前剩下的数字中选择第bi个
// 哇！好复杂。。。
// 比如0210
// 0: 在1234中选择第0个，就是1
// 2: 在234中选择滴2个，就是4
// 1: 在23中选择第1个，就是3
// 0: 在2中选择第0个，就是2
// 所以0210对应点就素 1432
class Solution {
public:
    int factorial(int n){
        return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
    }
    
    void plusp(vector<int> &p, const vector<int> &bound){
        int i = p.size()-1;
        while(i >= 0){
            if(p[i] < bound[i]){
                p[i]++;
                break;
            }else{
                p[i] = 0;
                i--;
            }
        }
        
    }
    
    
    
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        vector<int> ori_num = num;
        vector<int> tmp = num;
        
        int N = num.size();
        
        vector<int> p(N, 0);
        
        vector<int> bound = num;
        for(int i = 0; i < N; i++){
            bound[i] = N - 1 - i;
        }
        
        for(int i = 0; i < factorial(N); i++){
            num = ori_num;
            for(int j = 0; j < N; j++){
                tmp[j] = num[p[j]];
                num.erase(num.begin() + p[j]);
            }
            ret.push_back(tmp);
            plusp(p, bound);
            
        }
        
        return ret;
        
    }
};

