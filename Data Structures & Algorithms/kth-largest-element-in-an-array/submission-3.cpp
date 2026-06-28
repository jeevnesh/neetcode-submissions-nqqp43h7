class Solution {
   private:
    int partition(vector<int>& nums, int left, int right) {
        int i = left;
        for (int j = left; j < right; j++) {
            if (nums[j] <= nums[right]) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }

   public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int pivotIndex = partition(nums, left, right);
            if (pivotIndex == n - k) {
                return nums[pivotIndex];
            } else if (pivotIndex < n - k) {
                left = pivotIndex + 1;
            } else if (pivotIndex > n - k) {
                right = pivotIndex - 1;
            }
        }
        return -1;
    }
};
