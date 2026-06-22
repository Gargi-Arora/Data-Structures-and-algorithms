class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int revNum=0;
        int dup= x;
        while(x!=0){
            int ld= x%10;
            x/=10;
            if(revNum > INT_MAX/10) return false;
            revNum = (revNum*10)+ ld;
        }
        return (revNum== dup);
    }
};