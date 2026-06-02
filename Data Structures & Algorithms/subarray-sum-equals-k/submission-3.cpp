class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        int result = 0, currPrefixSum = 0;
        freqMap[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            currPrefixSum += nums[i];
            if (freqMap.find(currPrefixSum - k) != freqMap.end()) {
                result += freqMap[currPrefixSum - k];
            }
            freqMap[currPrefixSum]++;
        }
        return result;
    }
};