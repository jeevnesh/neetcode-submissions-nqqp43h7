class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1, n = nums.size();
        vector<int> ans(n,1);
        for(int i = 1; i < n; i++){
            ans[i] = prefix * nums[i-1];
            prefix *= nums[i-1];
        }
        int suffix = 1;
        for(int i = n-1; i >= 0; i--){
            ans[i] = ans[i] * suffix;
            suffix *= nums[i];
        }
        return ans;
    }
};
