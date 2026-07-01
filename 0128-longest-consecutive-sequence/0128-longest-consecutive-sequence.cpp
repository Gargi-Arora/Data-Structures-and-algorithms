class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int> st;
        int n = nums.size();
        int count = 0;
        int longest = 1;
        int x;
        for(int i= 0;i<n;i++){
            st.insert(nums[i]);
        }
        for(int it:st){
            if(st.find(it - 1)==st.end()){
                count=1;
                x = it;
            }
            while(st.find(x+1)!=st.end()){
                count++;
                x = x+1;
            }
            longest = max(longest,count);
        }
        return longest;
    }
};