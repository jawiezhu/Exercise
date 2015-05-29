// Given an array of integers, find if the array contains any duplicates. 
// Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	if(nums.size()==0) return false;
        sort(nums.begin(),nums.end());
        int tmp=nums[0];

        for(int i=1;i<nums.size();i++)
        {
        	if(nums[i]==tmp)
        		return true;
        	else
        		tmp=nums[i];
        }

        return false;
    }
};




// 1、哈希法。用一个set记录所有已经出现过的数字，若出现冲突，则包含重复元素，若不冲突，则不包含重复元素。
// 此方法的时间复杂度为O(n)，空间复杂度为O（n）

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        int len=nums.size();
        for(int i=0; i<len; i++){
            if(s.find(nums[i])==s.end()){
                s.insert(nums[i]);
            }else{
                return true;
            }
        }
        return false;
    }
};
// 2、排序法。现将数组排序，然后扫描一次数组，若出现相邻的两个数相同，则包含重复元素，否则没有。
// 此方法时间复杂度为O（nlogn），空间复杂度为O（1）【取决于排序方法】，不过用leetcode跑出来比1方法要快些，
// 因为1方法建立set需要花费一些时间，也有测试用例的问题。
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int len=nums.size();
        for(int i=1; i<len; i++){
            if(nums[i-1]==nums[i]){
                return true;
            }
        }
        return false;
    }
};

//===============
int Partition(int *nums,int low, int high){//一份为二，前半部分小于pivotkey,后半部分大于pivotkey
    int temp, pivotkey;
    pivotkey = nums[low];
    temp = pivotkey;
    while(low < high){
        while(low < high && nums[high] >= pivotkey){
            high--;
        }
        nums[low] = nums[high];
        while(low < high && nums[low] <= pivotkey){
            low++;
        }
        nums[high] = nums[low];
    }
    nums[low] = temp;
    return low;
}
void QSort1(int *nums,int low, int high){//快速排序算法，耗时在O(nlogn)，还是很严重，还怠于优化
    int pivot;
    while(low < high){
        pivot = Partition(nums,low,high);
        QSort1(nums,low,pivot-1);
        low = pivot+1;
    }
}
bool containsDuplicate(int* nums, int numsSize) {
    int i,j;
    if(nums == NULL || numsSize <= 1)return false;
    QSort1(nums,0,numsSize-1);
    for(i = 0; i < numsSize-1; i++){
        if(nums[i] == nums[i+1]){
            return 1;
        }
    }
    return false;
}




bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize <= 1) return false;
    int length = 100007;
    if (numsSize < length) length = numsSize;
    int * hash = (int*)malloc(sizeof(int) * length);
    bool * used = (bool*)malloc(sizeof(bool) * length);
    for (int i = 0; i < length; i++) used[i] = false;
    for (int i = 0; i < numsSize; i++) {
        int p = (nums[i] + numsSize) % numsSize;
        while (used[p]) {
            if (hash[p] == nums[i]) {
                free(hash);
                free(used);
                return true;
            }
            p++;
            if (p == length) p = 0;
        }
        hash[p] = nums[i];
        used[p] = true;
    }
    free(hash);
    free(used);
    return false;
}


