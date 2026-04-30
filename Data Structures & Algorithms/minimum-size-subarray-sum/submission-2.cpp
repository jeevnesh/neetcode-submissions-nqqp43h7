class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = INT_MAX, left = 0, right = 0, windowSum = 0;
        while (right < nums.size()) {
            windowSum += nums[right];
            while(windowSum >= target){
                minLength = min(minLength, right-left+1);
                windowSum -= nums[left];
                left++;
            }
            right++;
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};