// Given n non-negative integers a1, a2, ..., an, 
// where each represents a point at coordinate (i, ai). 
// n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
// Find two lines, which together with x-axis forms a container, 
// such that the container contains the most water.

// Note: You may not slant the container.


//头尾设置两个变量，i和j，然后 计算容量，跟maxCapacity比较，
//然后 对比 i和j对应的高度，i小，i++,j小，j--，如果cap有变化，就更新maxCapacity
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()==0) return 0;
        int n=height.size();
        int i=0;
        int j=n-1;
        int maxCapacity=0;
        int tmp=0;

        while(i!=j)
        {
            
            if(height[i]<=height[j])
            {
                tmp=height[i]*(j-i);
                i++;
            }else if(height[j]<=height[i])
            {
                tmp=height[j]*(j-i);
                j--;
            }
            
            if(maxCapacity<tmp)
            {
                maxCapacity=tmp;
            }

        }

        return maxCapacity;
    }
};

//从长最长的长方形找起，即令left = 0， right = height.size() - 1，
//但是在找下一个长方形时，长肯定会变短，要弥补这一段损失就必须加宽宽度，所以一下个就换掉两条宽中较小的那一个。

class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxArea = 0, area;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            area = (right - left) * min(height[left], height[right]);
            maxArea = (maxArea > area) ? maxArea : area;
            if (height[left] < height[right])
                ++left;
            else
                --right;
        }
        return maxArea;
    }
};

//两个指标i j往中间走。
//每次计算i和j之间的面积，如果比目前最大面积大，则更新最大面积，
//否则让两者之间较小的数的指标往前走。
int maxArea(vector<int> &height) {
     int i = 0, j = height.size() - 1;
     int result = 0;
 
     while(i < j) {
         if(height[i] < height[j]) {
             result = result > (j - i) * height[i] ? result : (j - i) * height[i];
             i++;
         }
         else {
             result = result > (j - i) * height[j] ? result : (j - i) * height[j];
             j--;
         }
     }
     return result;
 }



// 线性复杂度：
// 有两个指针i和j分别指向头和尾， 如果a[i]<a[j], 则i++,否则j--:
// 证明：
// 对任意ｋ<j：
// 都有(k-i)*min(a[k],a[i]) < (j-i)min(a[j],a[i]) = (j-i)a[i]
// 因为：
// (k-i) < (j-i)
// min(a[k],a[i]) < a[i] < min(a[j],a[i])
// 所以此种情况移动j只能得到更小的值， 移动j无用， 只能移动i。 反之亦然。



// 以例子：   [4,6,2,6,7,11,2] 来讲解。
// 1.首先假设我们找到能取最大容积的纵线为 i , j (假定i<j)，那么得到的最大容积 C = min( ai , aj ) * ( j- i) ；
// 2.下面我们看这么一条性质：
// ①: 在 j 的右端没有一条线会比它高！ 假设存在 k |( j<k && ak > aj) ，
// 那么  由 ak> aj，所以 min( ai,aj, ak) =min(ai,aj) ，
// 所以由i, k构成的容器的容积C' = min(ai,aj ) * ( k-i) > C，
// 与C是最值矛盾，所以得证j的后边不会有比它还高的线；
// ②:同理，在i的左边也不会有比它高的线；
// 这说明什么呢？如果我们目前得到的候选： 设为 x, y两条线（x< y)，那么能够得到比它更大容积的新的两条边必然在  [x,y]区间内并且 ax' > =ax , ay'>= ay;
// 3.所以我们从两头向中间靠拢，同时更新候选值；在收缩区间的时候优先从  x, y中较小的边开始收缩；
// 直观的解释是：容积即面积，它受长和高的影响，当长度减小时候，高必须增长才有可能提升面积，所以我们从长度最长时开始递减，然后寻找更高的线来更新候补；

