// Given an array of integers and an integer k, 
//return true if and only if there are two distinct indices i and j in the array such that nums[i] = nums[j]
// and the difference between i and j is at most k.

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()==0) return false;
        if(k>nums.size()) return false;

       	hash_map<int,int> mymap;


        return false;
    }
};