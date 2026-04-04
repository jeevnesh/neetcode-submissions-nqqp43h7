class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = -1, j = nums.size()-1, k = 0;
        while(k <= j){
            if(nums[k] == 0){
                i++;
                swap(nums[k],nums[i]);
                k++;
            }
            else if(nums[k] == 1){
                k++;
            }
            else if(nums[k] == 2){
                swap(nums[k],nums[j]);
                j--;
            }
        }
    }
};