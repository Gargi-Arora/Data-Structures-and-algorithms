class StockSpanner {
public:
    vector<int> arr;
    StockSpanner() {
    }
    
    int next(int price) {
        int cnt = 0;
        arr.push_back(price);
        cnt = 1;
        for(int i = arr.size()-2;i>=0;i--){
            if(arr[i]<=price) cnt++;
            else break;
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */