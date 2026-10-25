class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp = 0 ;
        int bestBuy = prices[0] ; 

        for(int i = 1 ; i<prices.size() ; i++) {
            mp = max(mp , prices[i] - bestBuy);

            bestBuy = min(bestBuy , prices[i]);
        }
        return mp ;
    }
};