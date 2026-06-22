class Solution {
public:
    bool isPalindrome(string s) {
       string cleaned = "";
       for (char c: s){
         if(isalnum(c))
            cleaned += tolower(c);
       }
       return check(0, cleaned);
    }
private:
    bool check(int i, string& s){
        if(i>= (int)s.size()/2) return true;
        if(s[i] != s[s.size() - i - 1]) return false;
        return check(i+1, s);
    }

};