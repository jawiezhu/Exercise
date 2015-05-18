// Given a collection of integers that might contain duplicates, nums, return all possible subsets.

// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If nums = [1,2,2], a solution is:

// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

class Solution {
private:
	vector<vector<int> >ret;
public:
	void dfs(int dep,int maxDep,vector<int> &num,vector<int> a,int start)
	{
		
			ret.push_back(a);

		if(dep==maxDep) return ;

		for(int i=start;i<num.size();i++)
		{
			if(i!=start&&num[i]==num[i-1]) continue;
			vector<int> b(a);
			b.push_back(num[i]);
			dfs(dep+1,maxDep,num,b,i+1);
		}


	}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ret.clear();
        vector<int> a;
        a.clear();
        dfs(0,nums.size(),nums,a,0);
        return ret;
    }
};




// 和上一个差不多,但是有重复.
// 有重复元素就挺麻烦的.
// 比如
// 1 1 1
// 我每个1都是可以选或者不选
// 那么第一个和第三个选了,第二个不选和第一个第二个选了第三个不选是一样的效果...
// 可以按上一题的做法做,然后再去重...
// 那我们怎么搞呢?
// 想想我们的递归树
// 再每一层不选重复元素，到下一层才选，那就去重了，不是么？
// 因为这样选是唯一的啊
// ex.
// 0 1 2
// 1 1 1
// 我选了0位置的1,那在root的时候就不能选1 ,2 位置的
// 那继续,选了1位置的1,再递归可以选2位置的也可以不选,如果不选就是11
// 那我在1位置的时候不选1位置的1的话,也不能选2位置的,所以11是唯一的.
class Solution {
public:
    void dfs(vector<vector<int> >& ans , vector<int>&s , vector<int>&tmp , int start) {
        ans.push_back(tmp);
        
        for(int i = start ; i < s.size() ; ++i) {
            if(i != start && s[i] == s[i-1]) continue; //select only once in every layer
            tmp.push_back(s[i]); //select
            dfs(ans , s , tmp , i + 1); //do recusive
            tmp.pop_back(); //delete
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ans;
        if(S.size() <= 0) return ans;
        vector<int> tmp;
        sort(S.begin() , S.end()); // sort
        dfs(ans , S , tmp , 0);
        return ans;
    }
};



//===
void findsubset(vector<int> s, int index, vector<int> &subset, vector<vector<int>> &res)
	{
		res.push_back(subset);
		for(int i = index; i< s.size(); i++)
		{
			if(i!=index && s[i]==s[i-1])continue;
			subset.push_back(s[i]);
			findsubset(s,i+1,subset,res);
			subset.pop_back();
		}
	}
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Note: The Solution object is instantiated only once.
        vector<vector<int>> res;
		sort(S.begin(),S.end());
		vector<int> subset;
		findsubset(S,0,subset,res);
		return res;
    }

//======
// 思路1：递归，放与不放的问题。类似http://blog.csdn.net/lanxu_yy/article/details/11885327，但需要考虑重复。
// 思路2：在http://blog.csdn.net/lanxu_yy/article/details/11885327的基础上修改，完善针对重复数据的判断。
class Solution {
public:
    vector<vector<int> >  v;
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(),S.end());
        
        generate(vector<int>(), S, 0);
        return v;
    }
    
    void generate(vector<int> res, vector<int> &S, int i)
    {
        if(i == S.size())
        {
            for(int i = 0; i < v.size(); i++)
            {
                if(v[i] == res)
                {
                    return;
                }
            }
            v.push_back(res);
            return;
        }
        else
        {
            generate(res, S, i+1);
            res.push_back(S[i]);
            generate(res, S, i+1);
        }
    }
};


//II:
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(),S.end());
        vector<vector<int>> r;
        vector<vector<int>> pre;
        vector<vector<int>> cur;
        int len=0;
        vector<int> tmp;
        cur.push_back(tmp);
        do
        {
            pre = cur;
            cur.clear();
            for(int i=0;i<pre.size();i++)
            {
                r.push_back(pre[i]);
                if(pre[i].size()>0)
                {
                    int last=INT_MIN;
                    int duplicate = 0;
                    for(int j=0;j<S.size();j++)
                    {
                        if(S[j]<pre[i][0])
                        {
                            if(S[j]!=last)
                            { 
                                vector<int> tmp = pre[i];
                                tmp.insert(tmp.begin(),S[j]);
                                cur.push_back(tmp);
                                duplicate = 0;
                                last=S[j];
                            }
                        }    
                        else if(S[j]==pre[i][0])
                        {
                            int sum=0;
                            for(int k=0;k<pre[i].size();k++)
                            {
                                if(pre[i][k]==S[j])
                                {
                                    sum++;
                                }
                                else
                                {
                                    break;
                                }
                            }
                            duplicate++;
                            if(duplicate==sum+1)
                            {
                                vector<int> tmp = pre[i];
                                tmp.insert(tmp.begin(),S[j]);
                                cur.push_back(tmp);
                                break;
                            }
                            last=S[j];
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else
                {
                    int last=INT_MIN;
                    for(int j=0;j<S.size();j++)
                    {
                        if(S[j]!=last)
                        {
                            vector<int> tmp = pre[i];
                            tmp.insert(tmp.begin(),S[j]);
                            cur.push_back(tmp);
                        }
                        last=S[j];
                    }
                }
            }
            len++;
        }while(len<=S.size());
        return r;
    }
};


//==========用一个数组来记录某个数字是否被使用过，如果前面的数字和本数相同，则前面的数必须被使用过本数才能被使用。
class Solution {
private:
    vector<vector<int> > ret;
    bool canUse[100];
public:
    void dfs(int dep, int maxDep, vector<int> &num, vector<int> a, int start)
    {
        ret.push_back(a);
        
        if (dep == maxDep)
            return;
            
        for(int i = start; i < num.size(); i++)
            if (i == 0)
            {
                canUse[i] = false;
                vector<int> b(a);
                b.push_back(num[i]);
                dfs(dep + 1, maxDep, num, b, i + 1);
                canUse[i] = true; 
            }
            else
            {
                if (num[i] == num[i-1] && canUse[i-1])
                    continue;
                    
                canUse[i] = false;
                vector<int> b(a);
                b.push_back(num[i]);
                dfs(dep + 1, maxDep, num, b, i + 1);
                canUse[i] = true;
            }          
    }
    
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        ret.clear();
        memset(canUse, true, sizeof(canUse));
        vector<int> a;
        dfs(0, S.size(), S, a, 0);
        return ret;
    }
};



// 基本思路循环+dfs，生成指定元素数目（0，1,2,...array.size()个元素）的组合。
// 1和2的区别在于2中允许数组中出现重复的元素。
// 所以2在dfs的时候要跳过重复的元素，例如：[1,1,2] 
//  如果不加跳过处理的话，生成的子集会有两个：[1,2]，但[1,1,2]是一个合理的组合。
public class Solution {
    void dfs(int [] number_array, int start, int number, ArrayList<Integer> array, ArrayList<ArrayList<Integer>> result) {
        if(number==array.size()) {
            result.add(new ArrayList<Integer>(array));
            return;
        }
        for(int i=start;i<number_array.length;i++) {
            array.add(number_array[i]);
            dfs(number_array,i+1,number,array,result);
            array.remove(array.size()-1);
        }
    }
    public ArrayList<ArrayList<Integer>> subsets(int[] S) {
          ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
          ArrayList<Integer> array = new ArrayList<Integer>();
          result.add(array);
          if(S==null) {
              return result;
          }
          Arrays.sort(S);
          for(int i=1;i<=S.length;i++) {
              array.clear();
              dfs(S,0,i,array,result);
          }
          return result;
    }
}//

public class Solution {
    void dfs(int[] number_array, int start, int number, ArrayList<Integer> array, ArrayList<ArrayList<Integer>> result) {
        if(array.size()==number) {
            result.add(new ArrayList<Integer>(array));
            return;
        }
        int i = start;
        while(i<number_array.length) {
            array.add(number_array[i]);
            dfs(number_array,i+1,number,array,result);
            array.remove(array.size()-1);
            //跳过相同的元素
            while(i<(number_array.length-1)&&number_array[i]==number_array[i+1]) {
                i++;
            }
            i++;
        }
    }
    
    
    public  ArrayList<ArrayList<Integer>> subsetsWithDup(int[] num) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer>       array = new ArrayList<Integer>();
        result.add(array);
        if(num==null) {
            return result;
        }
        Arrays.sort(num);
        for(int i=1;i<=num.length;i++) {
            array.clear();
            dfs(num,0,i,array,result);
        }
        return result;
    }
}//



