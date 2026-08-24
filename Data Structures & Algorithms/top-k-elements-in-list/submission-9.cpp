class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freqCounter;
        for (auto num : nums) {
            freqCounter[num]++;
        }
        vector<vector<int>> arr(n + 1);
        for (auto i : freqCounter) {
            arr[i.second].push_back(i.first);
        }
        vector<int> ans;
        for (int i = n; i > 0; i--) {
            while (arr[i].size()) {
                if (ans.size() < k) {
                    ans.push_back(arr[i].back());
                    arr[i].pop_back();
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};
