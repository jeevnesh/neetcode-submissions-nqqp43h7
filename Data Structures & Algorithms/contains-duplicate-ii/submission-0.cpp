class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size() ,i = 0, j = 0;
        unordered_set<int> st;
        while(j < n){
            if(st.find(nums[j]) != st.end()){
                return true;
            } 
            st.insert(nums[j]);
            if(j-i == k) {
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return false; 
    }
};