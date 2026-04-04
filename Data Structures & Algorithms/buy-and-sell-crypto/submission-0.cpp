class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //brute force
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++){
            for(int j = i+1; j < prices.size(); j++){
                if(prices[j] > prices[i]){
                    maxProfit = max(maxProfit, prices[j]-prices[i]);
                }
            }
        }
        return maxProfit;
    }
};
