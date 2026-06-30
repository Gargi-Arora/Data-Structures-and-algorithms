class Solution {
public:
    int CheckDivisor(vector<int> &nums,int mid){
        int total =0;
        for(int num : nums){
            total += (num+mid-1)/mid;
        }
        return total;
    }
    int smallestDivisor(vector<int>& nums,int threshold) {
        if(nums.size()>threshold) return -1;
        int low=1, high = *max_element(nums.begin(),nums.end());
        int ans = high;
        while(low<=high){
            int mid = (low + high)/2;
            int total = CheckDivisor(nums,mid);
            if(total<=threshold){
                ans = mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return ans;
    }
};