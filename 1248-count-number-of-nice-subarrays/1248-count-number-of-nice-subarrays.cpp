class Solution {
public:
    int function(vector<int>& nums,int goal){
        if(goal<0) return 0;
        int l = 0;
        int r = 0;
        int sum = 0;
        int cnt = 0;
        while(r<nums.size()){
            sum += nums[r]%2;
            while(sum>goal){
                sum -= nums[l]%2;
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return function(nums,k)-function(nums,k-1);
    }
};