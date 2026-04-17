class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, majority = 0;
        int j = 0;
        while(j < nums.size()){
            if(count == 0){
                majority = nums[j];
            }
            if(nums[j] == majority){
                count++;
            }else{
                count--;
            }
            j++;
        }
        return majority;
    }
};