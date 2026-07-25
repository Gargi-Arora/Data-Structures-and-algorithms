class Solution {
public:
    vector<int> generateRows(int row){
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for(int col = 0;col<row;col++){
            ans = ans*(row-col);
            ans = ans/(col+1);
            ansRow.push_back(int(ans));
        }
        return ansRow;
    }
    vector<vector<int>> generate(int n){
        vector<vector<int>> ans;
        for(int i =0;i<n;i++){
            ans.push_back(generateRows(i));
        }
        return ans;
    }
};