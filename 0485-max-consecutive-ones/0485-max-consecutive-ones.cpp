class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n= nums.size();
        int cnt=0;
        int maxCount;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnt++;
                maxCount= max(cnt,maxCount);
            }
            else cnt=0;
        }
        return maxCount;
    }
};