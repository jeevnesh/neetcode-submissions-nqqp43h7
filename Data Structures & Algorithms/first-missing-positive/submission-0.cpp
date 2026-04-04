class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //brute force
        int expected = 1;
        sort(nums.begin(), nums.end());
        for(int num : nums){
            if(num < expected){
                continue;
            } else if(num == expected){
                expected++;
            } else if(num > expected){
                return expected;
            }
        }
        return expected;
    }
};