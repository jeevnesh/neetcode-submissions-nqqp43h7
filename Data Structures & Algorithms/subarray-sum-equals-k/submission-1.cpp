class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int prefixSum = 0;
        unordered_map<int,int> freqCount;
        freqCount[0] = 1;
        for(int i = 0 ; i < nums.size(); i++){
            prefixSum += nums[i];
            if(freqCount.find(prefixSum - k) != freqCount.end()){
                count += freqCount[prefixSum - k];
            }
            freqCount[prefixSum]++;
        }
        return count;
    }
};