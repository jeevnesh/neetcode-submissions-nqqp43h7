class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (auto i : nums) {
            freqMap[i]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto i : freqMap) {
            bucket[i.second].push_back(i.first);
        }
        vector<int> result;
        for (int i = nums.size(); i > 0; i--) {
            for (auto num : bucket[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        return result;
    }
};
