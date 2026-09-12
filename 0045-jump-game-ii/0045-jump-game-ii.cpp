class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0,jumps = 0;
        while(r<nums.size()-1){
            int farthest = 0;
            for(int ind = l;ind<=r;ind++){
                farthest = max(farthest,ind + nums[ind]);
            }
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }
};