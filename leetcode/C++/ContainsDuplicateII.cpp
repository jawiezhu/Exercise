// Given an array of integers and an integer k, 
// return true if and only if there are two distinct indices i and j in the array such that nums[i] = nums[j]
// and the difference between i and j is at most k.

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()==0) return false;
        //if(k>nums.size()) return false;

       	map<int,int> tmp;
       	for(int i=0;i<nums.size();i++)
       	{
       		if(tmp.find(nums[i])!=tmp.end()&&i-tmp[nums[i]]<=k)
       		{
       			return true;
       		}else
       		{
       			tmp[nums[i]]=i;
       		}
       	}

        return false;
    }
};


//==============
class Solution {
public:

/*  解法一：超时
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int length=nums.size();
        if(length<=1||k<=0) return false;

        //将每一个元素与其后面k个元素进行比较
        for(int i=0;i<length;i++)
        {
            for(int j=1;j<=k&&(i+j)<length;j++)
            {
                if(nums[i]==nums[i+j])
                    return true;
            }
        }
        return false;
    }
    */


   //解法二，利用stl中的map，记录下整数以及它的下标 
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        //之前直接使用的是map，时间是96ms,后来把map替换成unordered_map时间变成了32ms
        unordered_map<int ,int> maps;
        int length=nums.size();
        for(int i=0;i<length;i++)
        {
            if(maps.count(nums[i]))//如果在maps中找到了该元素，判断它们位置是否小于等于k
            {
                if((i-maps[nums[i]])<=k) 
                    return true;
            }
            maps[nums[i]]=i;
        }
        return false;
    }

};



//这道题是之前那道Contains Duplicate 包含重复值的延伸，不同之处在于那道题只要我们判断下数组中是否有重复值，
// 而这道题限制了数组中只许有一组重复的数字，而且他们坐标差不能超过k。那么我们首先需要一个哈希表，来记录每个数字和其坐标的映射，
// 然后我们需要一个变量d来记录第一次出现重复数字的坐标差。由于题目要求只能有一组重复的数字，所以我们在遇到重复数字时，首先判断d是否已经存了值，
// 如果d已经有值了，说明之前有过了重复数字，则直接返回false即可。如果没有，则此时给d附上值。
// 在网上看到有些解法在这里就直接判断d和k的关系然后返回结果了，其实这样是不对的。因为题目要求只能有一组重复数，
// 就是说如果后面又出现了重复数，就没法继续判断了。所以正确的做法应该是扫描完整个数组后在判断，先看d有没有存入结果，如果没有，
// 则说明没出现过重复数， 返回false即可。如果d有值，再跟k比较，返回对应的结果。OJ的test case没有包含所有的情况，
// 比如当nums = [1, 2, 3, 1, 3], k = 3时，实际上应该返回false，但是有些返回true的算法也能通过OJ。个人认为正确的解法应该入下：
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int d = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) != m.end()) {
                if (d > 0) return false;
                d = i - m[nums[i]];
            }
            m[nums[i]] = i;
        }
        return d == 0 ? false : d <= k;
    }
};