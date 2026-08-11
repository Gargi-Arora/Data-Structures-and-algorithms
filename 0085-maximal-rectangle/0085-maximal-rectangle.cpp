class Solution {
public:
    int Lhist(vector<int>& matrix){
        int n = matrix.size();
        stack<int> st;
        int NSE = 0;
        int PSE = 0;
        int element = 0;
        int maxArea = 0;
        for(int i = 0;i<n;i++){
            while(!st.empty() && matrix[st.top()]>matrix[i]){
                element = st.top();
                st.pop();
                NSE = i;
                PSE = st.empty()? -1:st.top();
                maxArea = max(maxArea, (NSE-PSE-1)*matrix[element]);
            }
            st.push(i);
        }
            while(!st.empty()){
                NSE = n;
                element = st.top();
                st.pop();
                PSE = st.empty()?-1:st.top();
                maxArea = max(maxArea, (NSE-PSE-1)*matrix[element]);
            }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> pSum(m, vector<int>(n, 0));
        int maxArea = 0;
        for(int j = 0;j<n;j++){
            int sum = 0;
            for(int i = 0;i<m;i++){
                sum = (matrix[i][j] == '0') ? 0 : sum + 1;
                pSum[i][j] =  sum;
            }
        }
        for(int i = 0;i<m;i++){
            maxArea = max(maxArea, Lhist(pSum[i]));
        }
        return maxArea;
    }
};