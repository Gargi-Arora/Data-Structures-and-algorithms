class Solution {
public:
    vector<int> findNSE(vector<int> &nums){
        int n = nums.size();
        vector<int> NSE(n);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty()&& nums[st.top()]>=nums[i]){
                st.pop();
            }
            NSE[i] = st.empty()?n:st.top();
            st.push(i);
        }
        return NSE;
    }
    vector<int> findPSE(vector<int> &nums){
        int n = nums.size();
        vector<int> PSE(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            PSE[i] =  st.empty()?-1:st.top();
            st.push(i);
        }
        return PSE;
    }
    vector<int> findNGE(vector<int> &nums){
        int n = nums.size();
        vector<int> NGE(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            NGE[i] =  st.empty()?n:st.top();
            st.push(i);
        }
        return NGE;
    }
    vector<int> findPGE(vector<int> &nums){
        int n = nums.size();
        vector<int> PGE(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            PGE[i] =  st.empty()?-1:st.top();
            st.push(i);
        }
        return PGE;
    }
    long long sumSubarrayMins(vector<int> &nums){
        vector<int> NSE = findNSE(nums);
        vector<int> PSE = findPSE(nums);
        long long total = 0;
        for(int i=0;i<nums.size();i++){
            long long left = i - PSE[i];
            long long right = NSE[i] - i;
            total += right*left*nums[i];
        }
        return total;
    }
    long long sumSubarrayMaxs(vector<int> &nums){
        vector<int> NGE = findNGE(nums);
        vector<int> PGE = findPGE(nums);
        long long total = 0;
        for(int i=0;i<nums.size();i++){
            long long left = i - PGE[i];
            long long right = NGE[i] - i;
            total += right*left*nums[i];
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};