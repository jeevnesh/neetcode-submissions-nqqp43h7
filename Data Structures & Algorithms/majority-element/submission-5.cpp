class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int i = 0, count = 0, majority = INT_MIN;
        while (i < nums.size()) {
            if (count == 0) {
                majority = nums[i];
                count++;
            } else if (nums[i] == majority) {
                count++;
            } else {
                count--;
            }
            i++;
        }
        return majority;
    }
};