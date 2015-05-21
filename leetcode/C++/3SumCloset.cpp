// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

//     For example, given array S = {-1 2 1 -4}, and target = 1.

//     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

//ERROR WRONG ANSWER
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum=0;
        int tmp=0;
        int min=INT_MAX;
        int ret=0;
        for(int i=0;i<nums.size()-2;i++)
        {
        	sum=nums[i]+nums[i+1]+nums[i+2];

        	tmp=abs(sum-target);

        	if(min>tmp)
        	{
        		min=tmp;
        		ret=sum;
        	}
        }

        return ret;
    }
};

//先对数组排个序。枚举第一个数，然后设两个指针，在第一个数的后半段开始王中间收缩，if sum > target则右指针往左移， if sum < target则左指针往右移。
//排序O(nlogn) + 查找O(n^2) = O(n^2)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int ret;
        bool first=true;

        for(int i=0;i<nums.size();i++)
        {
        	int j=i+1;
        	int k=nums.size()-1;

        	while(j<k)
        	{
        		int sum=nums[i]+nums[j]+nums[k];

        		if(first)
        		{
        			ret=sum;
        			first=false;
        		}else
        		{
        			if(abs(sum-target)<abs(ret-target))
        				ret=sum;
        		}

        		if(ret==target)
        			return ret;

        		if(sum>target)
        			k--;
        		else
        			j++;
        	}
        }

        return ret;
    }
};


//先排序，然后左右夹逼，复杂度 $O(n^2)$。
// LeetCode, 3Sum Closest
// 先排序，然后左右夹逼，时间复杂度O(n^2)，空间复杂度O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& num, int target) {
        int result = 0;
        int min_gap = INT_MAX;

        sort(num.begin(), num.end());

        for (auto a = num.begin(); a != prev(num.end(), 2); ++a) {
            auto b = next(a);
            auto c = prev(num.end());

            while (b < c) {
                const int sum = *a + *b + *c;
                const int gap = abs(sum - target);

                if (gap < min_gap) {
                    result = sum;
                    min_gap = gap;
                }

                if (sum < target) ++b;
                else              --c;
            }
        }

        return result;
    }
};


//========
int three_sum_closest(vector<int> &num, int target) 
{
    int result = 0;
    int dist = INT_MAX;
    
    sort(num.begin(), num.end());
    
    for (vector<int>::const_iterator it = num.begin();
        it != num.end();
        ++it)
    {
        vector<int>::const_iterator front = it + 1;
        vector<int>::const_iterator back = num.end() - 1;
        
        while (front < back)
        {
            const int sum = *it + *front + *back;
            
            if (sum < target)
            {
                if (target - sum < dist)
                {
                    dist = target - sum;
                    result = sum;
                }
                
                ++front;
            }
            else if (sum > target)
            {
                if (sum - target < dist)
                {
                    dist = sum - target;
                    result = sum;
                }
                
                --back;
            }
            else
            {
                dist = 0;
                result = target;
                break;
            }
        }
    }
    
    return result;
}


//先排序，然后对任意a[i]取j = i + 1，k = S.size() - 1，比较abs(a[i] + a[j] + a[k] - target)，当差小于等于0时，j往后走，反之k往前走。
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int closet_sum = 0, diff = INT_MAX, size = num.size();
        
        sort(num.begin(), num.end());
        
        for (int i = 0; i < size; ++i) {
            int j = i + 1, k = size - 1;
            
            while (j < k) {
                int sum = num[i] + num[j] + num[k];
                int d = abs(sum - target);
                
                if (d < diff) {
                    diff = d;
                    closet_sum = sum;
                }
                
                if (d > 0) {
                    int tmp;
                    
                    if ((sum - target) < 0) {
                        tmp = j + 1;
                        
                        while ((tmp < k) && (num[j] == num[tmp])) {
                            ++tmp;
                        }
                        
                        j = tmp;
                    }
                    else {
                        tmp = k - 1;
                        
                        while ((tmp > j) && (num[tmp] == num[k])) {
                            --tmp;
                        }
                        
                        k = tmp;
                    }
                }
                else {
                    return closet_sum;
                }
            }
        }
        
        return closet_sum;
    }
};

//=======
 // * 主要思路：
 // * 1、设置判断上限表示距离类型的最大值（距离为有符号数，表示正向距离或方向距离）
 // * 2、穷举法选取符合条件的三元组，由于每个元素只能取一次，所以当前循环的起始为上次循环起始之后
 // *	  同时在穷举的过程中跳过求和结果和上次相同的计算和判断过程，加速判断过程
 // * 3、对于穷举的每个三元组求和后，获取绝对距离最小的那一组。如果遇到和目标值相同的结果则直接返回该结果
 // * 提交结果： 
 // * (Judge Small) 
 // * Run Status: Accepted! 
 // * Program Runtime: 0 milli secs （基本在几毫秒） 
 // * Progress: 28/28 test cases passed. 
 // * (Judge Large) 
 // * Run Status: Accepted! 
 // * Program Runtime: 248 milli secs （基本稳定在二百五十毫秒左右） 
 // * Progress: 311/311 test cases passed. 
 //
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
//		copy(num.begin(), num.end(), ostream_iterator<int>(cout, " "));
//		cout << endl;
		size_t size = num.size();
		if (size < 3)
		{
			cout << "num size must bigger than there!" << endl;
			return 0;
		}
//		vector<int> triplet;	// 存放符合条件的那个三元组，输出只有一组，所以保证输入时符合条件的三元组只有一组
		int result = 0;
		int distance = numeric_limits<int>::max();	// signed int
//		cout << " max int: " << distance << endl;

		int sum = 0;
		for (size_t i = 0; i < size; i++)
		{
			// 去重，
			if (i > 0 && num[i] == num[i-1])
			{
				continue;
			}
			for (size_t j = i+1; j < size; j++)
			{
				// 去重
				if (j > i+1 && num[j] == num[j-1])
				{
					continue;
				}
				for (size_t k = j+1; k < size; k++)
				{
					// 去重
					if (k > j+1 && num[k] == num[k-1])
					{
						continue;
					}
					sum = num[i] + num[j] + num[k];
					
					// 其他距离则选取最小的
					if (abs(sum - target) < abs(distance))	// static_cast<unsigned int>(tmp) < static_cast<unsigned int>(result)
					{
						// 如果找到距离最近的，即与目标值相同，则选取这个三元组的元素和作为结果
						if (sum == target)
						{
							return sum;
						}
						result = sum;
						distance = result-target;
//						triplet.clear();
//						triplet.push_back(num[i]);
//						triplet.push_back(num[j]);
//						triplet.push_back(num[k]);
					}
				}
			}
		}

		// 输出唯一的一组符合条件的三元组
//		copy(triplet.begin(), triplet.end(), ostream_iterator<int>(cout, " "));
//		cout << endl;

		return result;
	}
};

int main()
{
	vector<int> num;
	int target = 0;
	cout << "input the target: ";
	cin >> target;
	int number = 0;
	cout << "input some numbers: ";
	while (cin >> number)
	{
		num.push_back(number);
	}

	int result;
	Solution s;
	result = s.threeSumClosest(num, target);

	cout << "result: " << result << endl;

	return 0;
}


//
//可以在穷举之前先排序，因为中间的去重过程是考虑在排序后的基础上，考察的某个元素重复元素才会连续。
// (i<j<k && num[i]<=num[j]<=num[k]) 分别为三元组的三个元素
/** 整理的提交代码
 * 处理复杂度为O(n2)
 * 主要思路：
 * 1、先对输入数组进行排序，主要为了计算中的首尾逼近，还有在数组含有重复元素时可以避免重复计算
 * 2、设置判断上限为表示距离类型的最大值
 *   （距离为相对距离，判断过程中：如果小于目标值，则目标值减中间结果；如果大于目标值则中间结果减目标值）
 * 3、穷举法选取符合条件的三元组中的第一个元素，范围为[0...n-3]。
 *    对于剩下的两个元素则从第一个元素之后的位置与数组结尾位置之间通过首尾逼近的方法来选取最小距离
 *    由于每个元素只能取一次，所以当前循环的起始为上次循环起始之后
 *	  同时在穷举和逼近的过程中跳过求和结果和上次相同的计算和判断过程，加速判断过程
 * 4、对于穷举的每个三元组求和后，获取距离最近（可能大于目标值也可能小于目标值）的那一组。如果遇到和目标值相同的结果则直接返回该结果
 * 提交结果： 
 * (Judge Small) 
 * Run Status: Accepted! 
 * Program Runtime: 8 milli secs （基本在几毫秒） 
 * Progress: 28/28 test cases passed. 
 * (Judge Large) 
 * Run Status: Accepted! 
 * Program Runtime: 48 milli secs （基本稳定在五十毫秒左右） 
 * Progress: 311/311 test cases passed. 
 */
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		size_t size = num.size();
		if (size < 3)
		{
			cout << "num size must bigger than there!" << endl;
			return 0;
		}
		sort(num.begin(), num.end());	// 对于以下的处理过程必须事先排序，类似二分搜索
//		vector<int> triplet;	// 存放符合条件的那个三元组，输出只有一组，所以保证输入时符合条件的三元组只有一组
		int result = 0;		// 记录最终结果
		int distance = numeric_limits<int>::max();	// signed int
		int sum = 0;		// 中间结果
		size_t i = 0, j = i + 1, k = size - 1;

		// (i<j<k && num[i]<=num[j]<=num[k]) 分别为三元组的三个元素
		for(i = 0; i < size - 2; i++)	// 三元组的第一个元素一次遍历，范围为[0...n-3]
		{
			// 去重避免重复计算，如果和上次同则跳过
			if (i > 0 && num[i] == num[i-1])
			{
				continue;
			}
			
			j = i + 1;	// 选定三元组第一个元素后，第二个元素从第一个元素的下一个位置开始考察
			k = size - 1;	// 选定三元组第一个元素后，第三个元素从数组末尾开始考察
			while (j < k)	// 三元组的后两个元素利用左右逼近来跳过效率，选定第一个元素后，其后的所有元素只需考察一遍
			{
				sum = num[i] + num[j] + num[k];
				if (sum == target)	// 存在距离最近为0则直接返回，否则穷举选取非0最小距离
				{
					return sum;
				}
				else if(sum < target)
				{
					if((target - sum) < distance)
					{
						result = sum;
						distance = target - sum;
					}
					j = j + 1;
					// 避免重复计算，如果和上次同则跳过
					if (num[j] == num[j-1])
					{
						j = j + 1;
					}
				}
				else if(sum > target)
				{
					if((sum - target) < distance)
					{
						result = sum;
						distance = sum - target;
					}
					k = k - 1;
					// 避免重复计算如果和上次同则跳过
					if (num[k] == num[k+1])
					{
						k = k -1;
					}
					
				}
			}
		}
		return result;
	}
};

