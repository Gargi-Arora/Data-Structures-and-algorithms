class Solution {
public:
    bool isValid(string s){
        int balance = 0;
        for(char c:s){
            if(c=='(') balance++;
            else balance--;
            if(balance<0) return false;
        }
        return balance == 0;
    }
    void generateAll(string curr,int n,vector<string> &res){
        if(curr.size()==2*n){
            if(isValid(curr)) res.push_back(curr);
            return;
        }
        generateAll(curr+'(',n,res);
        generateAll(curr+')',n,res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateAll("",n,res);
        return res;
    }
};