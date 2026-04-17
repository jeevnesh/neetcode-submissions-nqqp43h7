class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1, k = 0;
        while(k <= j){
            if(nums[k] == 0){
                swap(nums[k], nums[i]);
                i++;
                k++;
            }else if(nums[k] == 1){
                k++;
            }else{
                swap(nums[k],nums[j]);
                j--;
            }
        }
    }
};