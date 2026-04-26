class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0 , n = prices.size();
        if(n == 0) return 0;
        int left = 0;
        for(int right = 1; right < n; right++){
            if(prices[right] >= prices[left]){
                profit = max(profit,prices[right] - prices[left]);
            }else{
                left = right;
            }
        }
        return profit;
    }
};
