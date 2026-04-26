class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int left = 0;
        unordered_set<int> st;
        for (int right = 0; right < nums.size(); right++) {
            if (st.find(nums[right]) != st.end()) return true;
            st.insert(nums[right]);
            if (right - left >= k) {
                st.erase(nums[left]);
                left++;
            }
        }
        return false;
    }
};