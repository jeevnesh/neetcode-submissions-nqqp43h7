class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // skip duplicate first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = n - 1;
            vector<int> subAns;
            while (j < k) {
                long long sum = (long long)nums[i] + nums[j] + nums[k];
                if (sum < 0)
                    j++;
                else if (sum > 0)
                    k--;
                else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    // skip duplicate second element
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    // skip duplicate thried element
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return result;
    }
};
