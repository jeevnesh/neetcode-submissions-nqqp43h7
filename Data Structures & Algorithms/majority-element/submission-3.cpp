class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, candidate = nums[0], i = 1, n = nums.size();
        while(i < n){
            if(count == 0){
                candidate = nums[i];
            }
            if(nums[i] == candidate){
                count++;
            }else{
                count--;
            }
            i++;
        }
        return candidate;
    }
};