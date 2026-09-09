class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int r = 0;
        int l = 0;
        int len = 0;
        int maxLen = 0;
        int hashLen = 256;
        int hash[hashLen];
        for(int i = 0;i<hashLen;i++){
            hash[i]=-1;
        }
        while(r<n){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l = hash[s[r]]+1;
                }
            }
            len = r-l+1;
            maxLen = max(len,maxLen);
            hash[s[r]]=r;
            r++;
        }
        return maxLen;
    }
};