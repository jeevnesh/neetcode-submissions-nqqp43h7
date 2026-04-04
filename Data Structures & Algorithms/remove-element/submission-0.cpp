class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int i = 0;
       int j = 0;
       while(j < nums.size()){
        if(nums[i] != val){
            i++;
        } else if(nums[i] == val && nums[j] != val){
            swap(nums[i],nums[j]);
            i++;
        }
        j++;
       }
       return i;
    }
};