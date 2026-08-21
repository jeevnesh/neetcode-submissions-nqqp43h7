class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size();
        unordered_set<int> st;
        while (j < n) {
            if (st.count(nums[j])) return true;
            st.insert(nums[j]);
            if (j-i >= k) {
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return false;
    }
};