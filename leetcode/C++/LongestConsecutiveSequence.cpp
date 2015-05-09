// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

// Your algorithm should run in O(n) complexity.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int cnt=0;
        int max=0;

        for(int i=1;i<nums.size();i++)
        {

        	if(nums[i]-nums[i-1]==1)
        		cnt++;
        	else if(nums[i]-nums[i-1]>1)
        	{
        		if(max<cnt)
        			max=cnt;
        		cnt=0;
        	}
        }
        if(max<cnt)
        	max=cnt;

        return max+1;
    }
};



// 如果允许$O(n*log n)$的复杂度，那么可以先排序，可是本题要求$O(n)$。
// 由于序列里的元素是无序的，又要求$O(n)$，首先要想到用哈希表。
// 用一个哈希表 {unordered_map<int, bool> used}记录每个元素是否使用，对每个元素，
// 以该元素为中心，往左右扩张，直到不连续为止，记录下最长的长度。
// Leet Code, Longest Consecutive Sequence
// 时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    int longestConsecutive(const vector<int> &num) {
        unordered_map<int, bool> used;

        for (auto i : num) used[i] = false;

        int longest = 0;

        for (auto i : num) {
            if (used[i]) continue;

            int length = 1;

            used[i] = true;

            for (int j = i + 1; used.find(j) != used.end(); ++j) {
                used[j] = true;
                ++length;
            }

            for (int j = i - 1; used.find(j) != used.end(); --j) {
                used[j] = true;
                ++length;
            }

            longest = max(longest, length);
        }

        return longest;
    }
};

// Leet Code, Longest Consecutive Sequence
// 时间复杂度O(n)，空间复杂度O(n)
// Author: @advancedxy
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> map;
        int size = num.size();
        int l = 1;
        for (int i = 0; i < size; i++) {
            if (map.find(num[i]) != map.end()) continue;
            map[num[i]] = 1;
            if (map.find(num[i] - 1) != map.end()) {
                l = max(l, mergeCluster(map, num[i] - 1, num[i]));
            }
            if (map.find(num[i] + 1) != map.end()) {
                l = max(l, mergeCluster(map, num[i], num[i] + 1));
            }
        }
        return size == 0 ? 0 : l;
    }

private:
    int mergeCluster(unordered_map<int, int> &map, int left, int right) {
        int upper = right + map[right] - 1;
        int lower = left - map[left] + 1;
        int length = upper - lower + 1;
        map[upper] = length;
        map[lower] = length;
        return length;
    }
};

//Python
// '''

// @author: gaotong
// '''

// class Solution:
//     # @param num, a list of integer
//     # @return an integer
//     def longestConsecutive(self, num):
//         numset = {}
//         for n in num:
//             numset[n] = True
//         ans = 1
//         clen = 1
//         for n in num:
           
//             if numset.get(n) == None:
//                 continue
//             clen = 1
//             nextNum = n-1
//             while numset.get(nextNum) != None:
//                 numset.pop(nextNum)
//                 nextNum -= 1
//                 clen += 1
                
//             nextNum = n+1
//             while numset.get(nextNum) != None:
//                 numset.pop(nextNum)
//                 nextNum += 1
//                 clen += 1
            
//             if clen > ans:
//                 ans = clen
                
//         return ans
//         


// "排序转换成经典的动态规划问题"的话排序至少需要时间复杂度为O(nlog(n))——pass
// 利用c++中的set，直接会排序，并且没有重合的，但是set背后实现的原理牵扯到红黑树，时间复杂度不满足——pass
// 建立hash索引，把查找的元素周围的都访问个遍，求出个临时最大值跟全局最大值比较。
// 当再次访问该段的元素的时候，直接跳过。这样保证时间复杂度为O(n)，c++11中数据结构为unordered_set，
// 保证查找元素的时间复杂度为O(1).

// 建立无序集合existSet visitedSet分别表示原集合中包含的元素和已经访问了的元素
// 全局最大个数maxLen
// 顺序遍历原集合中的元素
//     临时计数count=1
//     如果该元素在visitedSet，停止往下执行，进行下一次循环
//     否则，把改元素小的并且在existSet中的元素存放在visitedSet中，count++
//          把改元素大的并且在existSet中的元素存放在visitedSet中, count++
//     maxLen = max(maxLen, count)

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if(num.empty())
            return 0;
        unordered_set<int> existSet;
        unordered_set<int> visitedSet;
        int maxLen;
        for(int i = 0; i < num.size(); ++i)
            existSet.insert(num[i]);
        for(int i = 0; i < num.size(); ++i)
        {
            if(visitedSet.find(num[i]) != visitedSet.end())
                continue;
            int count = 1;
            int left = num[i];
            while(existSet.find(--left) != existSet.end())
            {
                ++count;
                visitedSet.insert(left);
            }
            int right = num[i];
            while(existSet.find(++right) != existSet.end())
            {
                ++count;
                visitedSet.insert(right);
            }
            maxLen = maxLen > count ? maxLen : count;
        }
        return maxLen;
    }
};



// 一看呢，就是排序，然后找就好了，但是要求是O(n),排序明显是个O(n*logn)的算法.

// 只是找连续的嘛,我们可以把所有的数字都存入hash表,然后随意从某个数字开始找他的前面和后面那个是否存在.

// 然后得到一个最大的长度.当然找过的就可以删掉了...你想,一个连续的序列,你从中间任意位置开始往两边找不都一样么.
class Solution {
public:
    set<int> flag;
    int findBound(int n , bool asc){
        int ans = 0;
        set<int>::iterator iter;
        while((iter = flag.find(n)) != flag.end()){
            flag.erase(iter);
            ans ++;
            if(asc) n-- ; else n++;
        }
        return ans;
    }
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
             
        int ans = 0;
        flag.clear();
        for(int i = 0 ; i < num.size() ; i++)
           flag.insert(num[i]);
        for(int i = 0 ; i < num.size(); i++){
            ans = max(findBound(num[i],true) + findBound(num[i]+1,false) , ans); 
        }
        return ans;
    }
};


//想要达到线性，必定需要借助hash表，所以思路就是利用hash进行扩展，记录length的长度即可
class Solution
{
public:
    int longestConsecutive(vector<int> &num)
    {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        map<int,int> hashtable;
        for(int i = 0;i < num.size();i++)
        {
            hashtable[num[i]] = i;
        }
         
        int count = 0;
        int max = 0;
        for(int i = 0;i < num.size();i++)
        {
            count = 1;
            int curincrease = num[i] + 1;
            while( hashtable.find(curincrease) != hashtable.end() )
            {
                count++;
                hashtable.erase(hashtable.find(curincrease));
                curincrease++;
            }
            int curdecrease = num[i] - 1;
            while( hashtable.find(curdecrease) != hashtable.end() )
            {
                count++;
                hashtable.erase(hashtable.find(curdecrease));
                curdecrease--;
            }
            if(count > max)
                max = count;
        }
        return max;
    }
};


lass Solution {
public:
    int longestConsecutive(vector<int> &num) {
        //why I don't have no idea for this problem???O(n) imply that you must use hashtable???
        unordered_map<int,int> hashtable;
        for(int i = 0;i < num.size();i++) {
            if(hashtable.find(num[i]) != hashtable.end())
                continue;
            int minus_1 = num[i] - 1;
            int plus_1 = num[i] + 1;
            unordered_map<int,int>::iterator minus_1iter,plus_1iter;
            minus_1iter = hashtable.find(minus_1);
            plus_1iter = hashtable.find(plus_1);
            if(minus_1iter != hashtable.end() && plus_1iter != hashtable.end()) {
                hashtable[num[i]] = hashtable[minus_1] + hashtable[plus_1] + 1;
                hashtable[num[i] - hashtable[minus_1]] = hashtable[num[i]];
                hashtable[num[i] + hashtable[plus_1]] = hashtable[num[i]];
            }
            else if(minus_1iter == hashtable.end() && plus_1iter == hashtable.end()) {
                hashtable[num[i]] = 1;
            }
            else if(minus_1iter != hashtable.end()) {
                hashtable[num[i]] = hashtable[minus_1] + 1;
                hashtable[num[i] - hashtable[minus_1]] = hashtable[num[i]];
            }
            else {
                hashtable[num[i]] = hashtable[plus_1] + 1;
                hashtable[num[i] + hashtable[plus_1]] = hashtable[num[i]];
            }
        }
         
        //find the maxlen
        int ans = INT_MIN;
        for(unordered_map<int,int>::iterator iter = hashtable.begin();iter != hashtable.end();++iter) {
            if(iter->second > ans)
                ans = iter->second;
        }
        return ans;
    }
};