class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int subsets = 1<<nums.size();
        vector<vector<int>> ans;
        for(int n = 0;n<=subsets-1;n++){
            vector<int> list;
            for(int i = 0;i<=nums.size();i++){
                if(n &(1<<i)) list.push_back(nums[i]);
            }
            ans.push_back(list);
        }
        return ans;
    }
};