class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int minPrice = INT_MAX, j = 0, n = nums.size(), profit = 0;
        while(j<n){
            minPrice = min(minPrice,nums[j]);
            profit = max(profit, nums[j]-minPrice);
            j++;
        }
        return profit;
    }
};
