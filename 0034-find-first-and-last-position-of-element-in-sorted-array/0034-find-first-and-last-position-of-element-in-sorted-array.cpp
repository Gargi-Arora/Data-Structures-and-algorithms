class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int starting = lower_bound(nums.begin(),nums.end(),target)- nums.begin();
        if(starting>=nums.size() || nums[starting] != target) return {-1,-1};
        int ending = (upper_bound(nums.begin(),nums.end(),target)- nums.begin())-1;
        return {starting,ending};
    }
};