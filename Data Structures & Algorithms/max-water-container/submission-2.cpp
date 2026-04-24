class Solution {
   public:
    int maxArea(vector<int>& nums) {
        int i = 0, n = nums.size(), j = n - 1;
        int area = 0;
        while (i < j) {
            int height = min(nums[i], nums[j]);
            int width = j - i;
            area = max(area, height * width);
            if (nums[i] >= nums[j]) {
                j--;
            } else {
                i++;
            }
        }
        return area;
    }
};
