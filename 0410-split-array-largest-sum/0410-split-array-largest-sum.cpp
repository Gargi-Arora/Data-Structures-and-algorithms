class Solution {
public:
    int division(vector<int>& nums, int size){
        long long countUnits = 0, arr = 1;
        for(int i= 0;i<nums.size();i++){
            if(countUnits + nums[i]<= size){
                countUnits+= nums[i];
            }
            else{
                arr++;
                countUnits = nums[i];
            }
        }
        return arr;
    }
    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size()) return -1;
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            int arr = division(nums,mid);
            if(arr<=k){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return low;
    }
};