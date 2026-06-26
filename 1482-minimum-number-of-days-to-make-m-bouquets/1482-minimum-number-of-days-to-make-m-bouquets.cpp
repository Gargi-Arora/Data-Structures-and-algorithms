class Solution {
public:
    bool possible(vector<int>& bloomDay,int day,int m,int k){
        int cnt=0, NoOfBouquets =0;
        for(int bloom : bloomDay){
            if(bloom<=day){
                cnt++;
                if(cnt==k){
                    NoOfBouquets++;
                    cnt=0;
                }
            }
            else{
                cnt=0;
            }
        }
        return NoOfBouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long TotalFlowers = 1LL * m * k;
        if(TotalFlowers > bloomDay.size()) return -1;
        int mini = *min_element(bloomDay.begin(),bloomDay.end());
        int max = *max_element(bloomDay.begin(),bloomDay.end());
        int low= mini , high = max;
        int result = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if (possible(bloomDay,mid,m,k)){
                result = mid;
                high= mid-1;
            }else{
                low= mid+1;
            }
        }
        return result;      
    }
};