class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ansStart =0, ansEnd=0;
        int start = 0,sum =0, maxi =INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(sum==0) start=i;
            sum += nums[i];
            if(sum>maxi){
                maxi= sum;
                ansStart = start; 
                ansEnd= i;
            }
            if(sum<0) sum=0;
        }
        cout<<"Subarray: ";
        for(int i=ansStart; i<= ansEnd;i++){
            cout<<nums[i]<<" ";
        }
        return maxi;
    }
};