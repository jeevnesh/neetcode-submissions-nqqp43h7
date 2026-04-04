class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minSoFar = prices[0];
        for(int i = 1 ; i < prices.size(); i++){
            maxProfit = max(maxProfit,prices[i] - minSoFar);
            if(prices[i] < minSoFar){
                minSoFar = prices[i];
            }
        }
        return maxProfit;
    }
};
