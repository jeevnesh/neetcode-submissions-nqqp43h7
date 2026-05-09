class Solution {
   private:
    int binarySearch(int start, int end, vector<int>& nums, int target) {
        if (start > end) return start;
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target)
            return binarySearch(mid + 1, end, nums, target);
        else
            return binarySearch(start, mid - 1, nums, target);
    }

   public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(0, nums.size() - 1, nums, target);
    }
};