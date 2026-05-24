class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0, n = nums.size();
        while(j < n){
            if(nums[j] != val){
                swap(nums[j],nums[i]);
                i++;
            }
            j++;
        }
        return i;
    }
};