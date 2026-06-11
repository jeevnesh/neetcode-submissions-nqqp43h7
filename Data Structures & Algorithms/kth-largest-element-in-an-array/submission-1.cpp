class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> freqArray(2001, 0);
        for (int num : nums) {
            freqArray[num + 1000]++;
        }
        for (int idx = 2000; idx >= 0; idx--) {
            while (freqArray[idx] > 0) {
                freqArray[idx]--;
                k--;
                if (k == 0) {
                    return idx - 1000;
                }
            }
        }
        return -1;
    }
};
