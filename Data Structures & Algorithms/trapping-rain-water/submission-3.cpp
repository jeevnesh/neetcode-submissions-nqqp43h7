class Solution {
   public:
    int trap(vector<int>& nums) {
        int left = 0, n = nums.size(), right = n - 1;
        int ans = 0, leftMax = 0, rightMax = 0;
        while (left < right) {
            if (nums[left] < nums[right]) {
                if (nums[left] >= leftMax) {
                    leftMax = nums[left];
                } else {
                    ans += leftMax - nums[left];
                }
                left++;
            } else {
                if (nums[right] >= rightMax) {
                    rightMax = nums[right];
                } else {
                    ans += rightMax - nums[right];
                }
                right--;
            }
        }
        return ans;
    }
};
