class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 1;
        int i = 1;
        int n = ratings.size();
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                sum+=1;
                i++;
                continue;
            }
            int peak = 0;
            while(i<n&&ratings[i]>ratings[i-1]){
                peak+=1;
                sum+=(peak+1);
                i++;
            }
            int down = 0;
            while(i<n&&ratings[i]<ratings[i-1]){
                down+=1;
                sum+=down;
                i++;
            }
            if(down>peak){
                sum+=(down-peak);
            }

        }
        return sum;
    }
};