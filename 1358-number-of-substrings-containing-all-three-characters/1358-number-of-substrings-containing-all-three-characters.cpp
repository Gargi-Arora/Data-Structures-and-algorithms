class Solution {
public:
    int numberOfSubstrings(string s) {
        int freq[3]={0};
        int cnt = 0;
        int left = 0;
        for(int r = 0;r<s.size();r++){
            freq[s[r]-'a']++;
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                // Count all substrings from current right to end
                cnt += (s.length() - r);

                // Decrease frequency of character at left and move left forward
                freq[s[left] - 'a']--;
                left++;
            }
        }
        return cnt;
    }
};