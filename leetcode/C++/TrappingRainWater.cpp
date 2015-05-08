// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

// For example, 
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


// 对于每个柱子，找到其左右两边最高的柱子，该柱子能容纳的面积就是{min(max_left, max_right) – height}。所以，

// 从左往右扫描一遍，对于每个柱子，求取左边最大值； 
// 从右往左扫描一遍，对于每个柱子，求最大右值； 
// 再扫描一遍，把每个柱子的面积并累加。 

// 也可以，
// 扫描一遍，找到最高的柱子，这个柱子将数组分为两半； 
// 处理左边一半； 
// 处理右边一半。 


class Solution {
public:
    int trap(vector<int>& height) {
        int max=0;
        for(int i=0;i<height.size();i++)
        {
        	if(height[i]>height[max])
        		max=i;
        }

        int water=0;

        for(int i=0,peak=0;i<max;i++)
        	if(height[i]>peak)
        		peak=height[i];
        	else
        		water=water+peak-height[i];

        for(int i=height.size()-1,top=0;i>max;i--)
        	if(height[i]>top)
        		top=height[i];
        	else
        		water=water+top-height[i];

        return water;
    }
};


// LeetCode, Trapping Rain Water
// 思路1，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    int trap(int A[], int n) {
        int *max_left = new int[n]();
        int *max_right = new int[n]();

        for (int i = 1; i < n; i++) {
            max_left[i] = max(max_left[i - 1], A[i - 1]);
            max_right[n - 1 - i] = max(max_right[n - i], A[n - i]);

        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            int height = min(max_left[i], max_right[i]);
            if (height > A[i]) {
                sum += height - A[i];
            }
        }

        delete[] max_left;
        delete[] max_right;
        return sum;
    }
};


// LeetCode, Trapping Rain Water
// 思路2，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int trap(int A[], int n) {
        int max = 0; // 最高的柱子，将数组分为两半
        for (int i = 0; i < n; i++)
            if (A[i] > A[max]) max = i;

        int water = 0;
        for (int i = 0, peak = 0; i < max; i++)
            if (A[i] > peak) peak = A[i];
            else water += peak - A[i];
        for (int i = n - 1, top = 0; i > max; i--)
            if (A[i] > top) top = A[i];
            else water += top - A[i];
        return water;
    }
};


// LeetCode, Trapping Rain Water
// 用一个栈辅助，小于栈顶的元素压入，大于等于栈顶就把栈里所有小于或
// 等于当前值的元素全部出栈处理掉，计算面积，最后把当前元素入栈
// 时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    int trap(int a[], int n) {
        stack<pair<int, int>> s;
        int water = 0;

        for (int i = 0; i < n; ++i) {
            int height = 0;

            while (!s.empty()) { // 将栈里比当前元素矮或等高的元素全部处理掉
                int bar = s.top().first;
                int pos = s.top().second;
                // bar, height, a[i] 三者夹成的凹陷
                water += (min(bar, a[i]) - height) * (i - pos - 1);
                height = bar;

                if (a[i] < bar) // 碰到了比当前元素高的，跳出循环
                    break;
                else
                    s.pop(); // 弹出栈顶，因为该元素处理完了，不再需要了
            }

            s.push(make_pair(a[i], i));
        }

        return water;
    }
};
