class Solution {
   private:
    int binarySearch(int start, int end, vector<int>& nums, int target) {
        if (start > end) {
            return -1;
        }
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            return binarySearch(mid + 1, end, nums, target);
        } else {
            return binarySearch(start, mid - 1, nums, target);
        }
    }

   public:
    int search(vector<int>& nums, int target) {
        int i = 0, n = nums.size(), j = n - 1;
        return binarySearch(i, j, nums, target);
    }
};
