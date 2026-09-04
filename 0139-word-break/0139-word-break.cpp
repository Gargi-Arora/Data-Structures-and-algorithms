class Solution {
public:
    bool wordBreakRec(int ind,string& s,vector<string> &wordDict, vector<int> &dp){
       if(ind>= s.size()){
         return true;
       }
       if(dp[ind]!= -1){
         return dp[ind];
       }
       bool possible = false;
       for(int i = 0;i<wordDict.size();i++){
            string temp = wordDict[i];
            if(temp.size()>s.size()-ind) continue;
            bool ok = true;
            int k = ind;
            for(int j = 0;j<temp.size();j++){
                if(temp[j]!=s[k]){
                    ok = false;
                    break;
                }
                else{
                    k++;
                }
            }
            if(ok){
                possible |= wordBreakRec(ind + temp.size(),s,wordDict,dp);
            }
       }
        return dp[ind] = possible;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        string temp = "";
        return wordBreakRec(0,s,wordDict,dp);
    }
};