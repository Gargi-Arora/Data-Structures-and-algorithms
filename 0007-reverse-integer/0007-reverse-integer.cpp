class Solution {
public:
    int reverse(int x) {
        int RevNum=0;
        while(x!=0){
            int ld;
            ld= x%10;
            if(RevNum> INT_MAX/10 || RevNum< INT_MIN/10) return 0;
            RevNum = (RevNum*10)+ld;
            x=x/10;
        }
        return RevNum;
    }
};