class Solution {
public:
    vector<int> findNSE(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> NSE(n);
        for(int i = n-1 ; i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            NSE[i] = st.empty()?n:st.top();
            st.push(i);
        }
        return NSE;
    }
    vector<int> findPSE(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> PSE(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            PSE[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return PSE;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> NSE = findNSE(arr);
        vector<int> PSE = findPSE(arr);
        int total = 0;
        const long long mod = (int)1e9+7;
        for(int i = 0;i<arr.size();i++){
            int left = i - PSE[i];
            int right = NSE[i] - i;
            total = (total + (right*left*1LL*arr[i])%mod)%mod;
        }
        return total;
    }
};