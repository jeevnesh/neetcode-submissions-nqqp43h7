class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i = 0;
        int count = 0;
        int majority = 0;
        while(i < nums.size()){
            if(count == 0){
            majority = nums[i];
            count++;
        } else {
            if(nums[i] == majority){
                count++;
            } else {
                count--;
            }
        }
        i++;
        }
        
        return majority;
    }
};