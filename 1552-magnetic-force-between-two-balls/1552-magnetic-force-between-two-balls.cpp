class Solution {
public:
    bool canWePlace(vector<int> &position, int distance , int m){
       int countBalls = 1, lastBall = position[0];
       for(int i=1;i<position.size();i++){
            if(position[i]-lastBall>= distance){
                countBalls++;
                lastBall = position[i];
            }
       }
       return countBalls>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low = 1, high = position[position.size()-1]-position[0];
        while(low<=high){
            int mid = (low+high)/2;
            if(canWePlace(position,mid,m)){
                low= mid+1;
            }
            else{
                high= mid-1;
            }
        }
        return high;
    }
};