class Solution {
public:
    long long CheckDivisor(vector<int> &nums,int mid){
        long long total =0;
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
            long long total = CheckDivisor(nums,mid);
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