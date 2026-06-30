class Solution {
public:
    int daysNeeded(vector<int>& weights,int mid){
        int days = 1;
        int currentload = 0;
        for(int w : weights){
            if(currentload + w> mid){
                days++;
                currentload = w;
            }
            else{
                currentload+=w;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end()), high = accumulate(weights.begin(),weights.end(),0) ;
        while(low<=high){
            int mid = (low+high)/2;
            int needed = daysNeeded(weights,mid);
            if(needed <= days){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};