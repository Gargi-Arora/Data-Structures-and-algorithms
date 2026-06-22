class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n= nums.size();
        int cnt = 0;
        int el;
        for(int i=0;i<n;i++){
            if(cnt==0){
                cnt=1;
                el = nums[i];
            }
            else if(nums[i]==el){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el){
                count++;
            }
            if(count>(n/2)){
                return el;
            }
        }
        return -1;
    }
};