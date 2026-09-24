class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = l+1;
        int prft = 0;
        while(r<prices.size()){
            if(prices[r]<prices[l]){
                l=r;
                r=r+1;
            }else{
                prft = max(prft, prices[r]-prices[l]);
                r++;
            }
        }
        return prft;
    }
};
