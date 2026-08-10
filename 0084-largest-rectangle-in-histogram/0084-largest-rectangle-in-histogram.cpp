class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int element = 0;
        int NSE = 0;
        int PSE = 0;
        int maxArea = 0;
        for(int i = 0;i<n;i++){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                element = st.top();
                st.pop();
                NSE = i;
                PSE = st.empty() ? -1:st.top();
                maxArea = max(heights[element] * (NSE-PSE-1), maxArea);
            }
            st.push(i);
        }
        while(!st.empty()){
            NSE = n;
            element = st.top();
            st.pop();
            PSE = st.empty()?-1:st.top();
            maxArea = max(heights[element] * (NSE-PSE-1), maxArea);
        }
        return maxArea;
    }
};